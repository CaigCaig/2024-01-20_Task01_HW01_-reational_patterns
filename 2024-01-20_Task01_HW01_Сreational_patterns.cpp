﻿#include <iostream>
#include "sql_query_builder.h"

using namespace std;

void SendQuery(const SqlSelectQuery& e) {
    cout << e.query << endl;
 }

int main() {
	SqlSelectQueryBuilder query_builder;
	query_builder.AddColumn("name").AddColumn("phone");
	query_builder.AddFrom("students");
	query_builder.AddWhere("id", "42").AddWhere("name", "John");

    //static_assert(query_builder.BuildQuery(), "SELECT name, phone FROM students WHERE id=42 AND name=John;");
    SendQuery(query_builder.BuildQuery());
    system("pause");
}

/*

Реализуйте класс SqlSelectQueryBuilder, который можно использовать для построения простых SELECT-запросов.
Обратите внимание на следующие моменты
Методы построения запроса AddColumn, AddFrom, AddWhere могут вызывать в любом порядке. При этом запрос должен всегда строиться корректно.
Если метод AddColumn не был вызван, запрос должен начинаться с SELECT * ....
Для простоты строки в запросе могут быть не выделены кавычками, как в примере.
Вызовы AddFrom должны перезаписывать название таблицы в классе.
Не забудьте ; в конце каждого запроса.

*/