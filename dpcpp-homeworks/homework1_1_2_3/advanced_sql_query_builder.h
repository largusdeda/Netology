#pragma once

#include "sql_query_builder.h"

class AdvancedSqlSelectQueryBuilder : public SqlSelectQueryBuilder {

public:
	AdvancedSqlSelectQueryBuilder& addWhereLessOr(const std::string& field, const std::string& value);
	AdvancedSqlSelectQueryBuilder& addWhereLessAnd(const std::string& field, const std::string& value);
	AdvancedSqlSelectQueryBuilder& addWhereMoreOr(const std::string& field, const std::string& value);
	AdvancedSqlSelectQueryBuilder& addWhereMoreAnd(const std::string& field, const std::string& value);

	std::string BuildQuery() const override;

private:
	std::map<std::string, std::string> conditions_less_or;
	std::map<std::string, std::string> conditions_less_and;
	std::map<std::string, std::string> conditions_more_or;
	std::map<std::string, std::string> conditions_more_and;

};