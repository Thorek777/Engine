#pragma once

MYSQL_ROW row;
MYSQL_RES* res2;
const char* base;

void MySQL_ExecuteQuery(string query);
void MySQL_Clear();
