#include "sql_query_builder.h"

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn(const std::string& column) {
	columns.insert(EscapeSql(column));

	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumns(const std::vector<std::string>& columns) noexcept {
	for (const auto& column : columns) {
		this->columns.insert(EscapeSql(column));
	}

	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddFrom(const std::string& table) {
	this->table = EscapeSql(table);

	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::string& field, const std::string& value) {
	conditions.insert( { EscapeSql(field), EscapeSql(value) } );

	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::map<std::string, std::string>& kv) noexcept {
	for (const auto& pair : kv) {
		conditions.insert( { EscapeSql(pair.first), EscapeSql(pair.second) } );
	}
	return *this;
}

std::string SqlSelectQueryBuilder::BuildQuery() const {
	std::ostringstream query{};
	
	//SELECT
	query << "SELECT ";
	if (columns.empty()) {
		query << "*";
	}
	else {
		for (auto it{ columns.begin() }; it != columns.end(); it++) {
			if (it != columns.begin()) {
				query << ", ";
			}
			query << *it;
		}
	}

	//FROM
	if (!table.empty()) {
		query << " FROM " << table;
	}
	else {
		std::stringstream err{};
		err << "Table \"" << table << "\" does not exist.";
		throw std::runtime_error(err.str());
	}

	//WHERE
	if (!conditions.empty()) {
		query << " WHERE ";
		size_t i{ 0 };
		for (const auto& condition : conditions) {
			if (i != 0) {
				query << " AND ";
			}
			query << condition.first << " = " << condition.second;
			i++;
		}
	}

	query << ";";
	return query.str();
}

std::string SqlSelectQueryBuilder::EscapeSql(const std::string& input) const {
	std::string output;
	output.reserve(input.length());

	for (char ch : input) {
		switch (ch) {
			case '\'': 
				output += "''"; 
				break; 
			case '\\': 
				output += "\\\\"; 
				break; 
			case ';': 
				output += "\\;"; 
				break; 
			case '"': 
				output += "\\\""; 
				break;
			default: 
				output += ch; 
				break;
		}
	}

	return output;
}
