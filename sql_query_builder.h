#pragma once
#include <iostream>
#include "map"
#include "vector"

using namespace std;

struct SqlSelectQuery {
    vector<string> columns;
    string from;
    string where;
    string query;
    map<string, string> meta;
};

class SqlSelectQueryBuilder {
private:
    SqlSelectQuery sql_select_query;
public:
    explicit SqlSelectQueryBuilder() {};
    SqlSelectQuery BuildQuery() noexcept;
    SqlSelectQueryBuilder& AddColumn(const std::string& column);
    SqlSelectQueryBuilder& AddFrom(const std::string& from);
    SqlSelectQueryBuilder& AddWhere(const std::string& key, const std::string& value);

};