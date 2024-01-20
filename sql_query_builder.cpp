#include "sql_query_builder.h"

SqlSelectQuery SqlSelectQueryBuilder::BuildQuery() noexcept {
	sql_select_query.query = "SELECT ";
	//for_each(sql_select_query.columns.begin(), sql_select_query.columns.end(), []() {sql_select_query.query += sql_select_query.columns; });
	if (sql_select_query.columns.size()) {
		for (const auto& i : sql_select_query.columns) { sql_select_query.query += i + ", "; }
		sql_select_query.query.erase(sql_select_query.query.length() - 2, 2);
	}
	else sql_select_query.query += "*";
	sql_select_query.query += " FROM " + sql_select_query.from + " WHERE ";
	for (const auto& i : sql_select_query.meta) { sql_select_query.query += i.first + "=" + i.second + " AND "; }
	sql_select_query.query.erase(sql_select_query.query.length() - 5, 5);
	sql_select_query.query += ";";
	//"SELECT name, phone FROM students WHERE id=42 AND name=John;"
	return sql_select_query;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn(const std::string& column) {
	sql_select_query.columns.push_back(column);
	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddFrom(const std::string& from) {
	sql_select_query.from = from;
	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::string& key, const std::string& value) {
	sql_select_query.meta[key] = value;
	return *this;
}