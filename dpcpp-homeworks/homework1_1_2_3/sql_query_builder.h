#pragma once

#include <string>
#include <set>
#include <map>
#include <sstream>
#include <stdexcept>
#include <vector>

class SqlSelectQueryBuilder {

public:
	SqlSelectQueryBuilder() = default;

	SqlSelectQueryBuilder& AddColumn(const std::string& column);
	SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& columns) noexcept;
	SqlSelectQueryBuilder& AddFrom(const std::string& table);
	SqlSelectQueryBuilder& AddWhere(const std::string& field, const std::string& value);
	SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept;

	virtual std::string BuildQuery() const;

protected:
	std::string EscapeSql(const std::string& input) const;

private:
	std::string table{ "" };
	std::set<std::string> columns{};
	std::multimap<std::string, std::string> conditions{};
};