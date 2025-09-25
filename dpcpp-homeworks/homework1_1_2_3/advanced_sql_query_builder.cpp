#include "advanced_sql_query_builder.h"

AdvancedSqlSelectQueryBuilder& AdvancedSqlSelectQueryBuilder::addWhereLessOr(const std::string& field, const std::string& value) {
	conditions_less_or.insert( { EscapeSql(field), EscapeSql(value) } );

	return *this;
}

AdvancedSqlSelectQueryBuilder& AdvancedSqlSelectQueryBuilder::addWhereLessAnd(const std::string& field, const std::string& value) {
	conditions_less_and.insert({ EscapeSql(field), EscapeSql(value) });

	return *this;
}

AdvancedSqlSelectQueryBuilder& AdvancedSqlSelectQueryBuilder::addWhereMoreOr(const std::string& field, const std::string& value) {
	conditions_more_or.insert({ EscapeSql(field), EscapeSql(value) });

	return *this;
}

AdvancedSqlSelectQueryBuilder& AdvancedSqlSelectQueryBuilder::addWhereMoreAnd(const std::string& field, const std::string& value) {
	conditions_more_and.insert({ EscapeSql(field), EscapeSql(value) });

	return *this;
}

std::string AdvancedSqlSelectQueryBuilder::BuildQuery() const {
	std::string prime_query{ SqlSelectQueryBuilder::BuildQuery() };
	prime_query.pop_back();
	std::stringstream query{};
	query << prime_query;

	bool need_pretext{ true };

	//WHERE
	size_t where_pos{ query.str().find("WHERE") };
	if (where_pos == std::string::npos && (!conditions_less_or.empty() || !conditions_less_and.empty() || !conditions_more_or.empty() || !conditions_more_and.empty()) ) {
		query << " WHERE ";
		need_pretext = false;
	}

	//OR >
	if (!conditions_more_or.empty()) {
		size_t i{ 0 };
		for (const auto& condition : conditions_more_or) {
			if (i != 0 || need_pretext) {
				query << " OR ";
			}
			query << condition.first << " > " << condition.second;
			i++;
		}
		need_pretext = true;
	}

	//AND <
	if (!conditions_less_and.empty()) {
		size_t i{ 0 };
		for (const auto& condition : conditions_less_and) {
			if (i != 0 || need_pretext) {
				query << " AND ";
			}
			query << condition.first << " < " << condition.second;
			i++;
		}
		need_pretext = true;
	}

	//OR <
	if (!conditions_less_or.empty()) {
		size_t i{ 0 };
		for (const auto& condition : conditions_less_or) {
			if (i != 0 || need_pretext) {
				query << " OR ";
			}
			query << condition.first << " < " << condition.second;
			i++;
		}
		need_pretext = true;
	}

	//AND >
	if (!conditions_more_and.empty()) {
		size_t i{ 0 };
		for (const auto& condition : conditions_more_and) {
			if (i != 0 || need_pretext) {
				query << " AND ";
			}
			query << condition.first << " > " << condition.second;
			i++;
		}
		need_pretext = true;
	}

	query << ";";
	return query.str();
}