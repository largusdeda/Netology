#include <iostream>
#include <cassert>

#include "sql_query_builder.h"
#include "advanced_sql_query_builder.h"

int main() {
	/* //////////////////////////////////////////// SQL SELECT QUERY BUILDER ////////////////////////////////////////////////////// */
	
	{
		SqlSelectQueryBuilder query_builder;
		query_builder.AddColumn("name").AddColumn("phone");
		query_builder.AddFrom("students");
		query_builder.AddWhere("id", "42").AddWhere("name", "John");

		std::string result{ query_builder.BuildQuery() };

		assert(result == "SELECT name, phone FROM students WHERE id = 42 AND name = John;");
	}

	{
		SqlSelectQueryBuilder query_builder;
		query_builder.AddFrom("students");
		query_builder.AddWhere("id", "42").AddWhere("name", "John");

		std::string result{ query_builder.BuildQuery() };

		assert(result == "SELECT * FROM students WHERE id = 42 AND name = John;");
	}

	{
		SqlSelectQueryBuilder query_builder;

		std::vector<std::string> col = { "name", "phone" };

		std::map<std::string, std::string> cond;
		cond.insert(std::pair("id", "42"));
		cond.insert(std::pair("name", "John"));
		cond.insert(std::pair("surname", "Ivanov"));

		query_builder.AddColumns(col);
		query_builder.AddFrom("students");
		query_builder.AddWhere(cond);

		std::string result{ query_builder.BuildQuery() };

		assert(result == "SELECT name, phone FROM students WHERE id = 42 AND name = John AND surname = Ivanov;");
	}

	/* //////////////////////////////////////////// SQL SELECT QUERY BUILDER ////////////////////////////////////////////////////// */


	/* //////////////////////////////////////////// ADVANCED SQL SELECT QUERY BUILDER ////////////////////////////////////////////////////// */

	{
		AdvancedSqlSelectQueryBuilder query_builder;
		query_builder.AddColumns({ "name", "phone" });
		query_builder.AddFrom("students");
		query_builder.addWhereMoreAnd("id", "42");

		std::string result{ query_builder.BuildQuery() };

		assert(result == "SELECT name, phone FROM students WHERE id > 42;");
	}

	{
		AdvancedSqlSelectQueryBuilder query_builder;
		query_builder.AddColumns({ "name", "phone" });
		query_builder.AddFrom("students");
		query_builder.AddWhere("id", "42").AddWhere("name", "John");
		query_builder.addWhereMoreOr("id", "55");
		query_builder.addWhereLessAnd("id", "170");

		std::string result{ query_builder.BuildQuery() };

		assert(result == "SELECT name, phone FROM students WHERE id = 42 AND name = John OR id > 55 AND id < 170;");
	}

	{
		AdvancedSqlSelectQueryBuilder query_builder;
		query_builder.AddColumns({ "name", "phone" });
		query_builder.AddFrom("students");
		query_builder.AddWhere("id", "42").AddWhere("name", "John");
		query_builder.addWhereMoreOr("id", "55");
		query_builder.addWhereLessAnd("id", "170");
		query_builder.addWhereMoreAnd("id", "300");
		query_builder.addWhereLessOr("id", "500");

		std::string result{ query_builder.BuildQuery() };

		assert(result == "SELECT name, phone FROM students WHERE id = 42 AND name = John OR id > 55 AND id < 170 OR id < 500 AND id > 300;");
	}

	/* //////////////////////////////////////////// ADVANCED SQL SELECT QUERY BUILDER ////////////////////////////////////////////////////// */

	return EXIT_SUCCESS;
}