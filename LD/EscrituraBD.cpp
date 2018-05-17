#include "EscrituraBD.h"
#include "sqlite3.h"
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
using namespace std;

void iniciarBD(sqlite3 *db)
{
	char *err_message=0;
	int rc;

	const char *sql_query = "CREATE TABLE CAMAREROS (DNI INT PRIMARY KEY NOT NULL, NOMBRE TEXT, APELLIDO TEXT, TEL INT, SALARIO FLOAT);";
  	rc = sqlite3_exec(db, sql_query, 0, 0, &err_message);
  	if (rc != SQLITE_OK ) 
  		cout << sqlite3_errmsg(db);

  	const char *sql_query = "CREATE TABLE PERSONAS (DNI INT PRIMARY KEY NOT NULL, NOMBRE TEXT, APELLIDO TEXT, TEL INT);";
  	rc = sqlite3_exec(db, sql_query, 0, 0, &err_message);
  	if (rc != SQLITE_OK ) 
  		cout << sqlite3_errmsg(db);

  	const char *sql_query = "CREATE TABLE PRODUCTOS (ID INT PRIMARY KEY NOT NULL, NOMBRE TEXT, CATEGORIA TEXT, PRECIO FLOAT);";
  	rc = sqlite3_exec(db, sql_query, 0, 0, &err_message);
  	if (rc != SQLITE_OK ) 
  		cout << sqlite3_errmsg(db);

  	const char *sql_query = "CREATE TABLE CATEGORIAS (ID INT PRIMARY KEY NOT NULL, NOMBRE TEXT, ORDEN INT);";
  	rc = sqlite3_exec(db, sql_query, 0, 0, &err_message);
  	if (rc != SQLITE_OK ) 
  		cout << sqlite3_errmsg(db);

  	const char *sql_query = "CREATE TABLE COMANDAS (DNI INT PRIMARY KEY NOT NULL, FECHYHO INT, TOTAL FLOAT, MEDIA FLOAT);";
  	rc = sqlite3_exec(db, sql_query, 0, 0, &err_message);
  	if (rc != SQLITE_OK ) 
  		cout << sqlite3_errmsg(db);

}


int altaCamarero (sqlite3 *db,int dni, string nombre,string apellido, int tel) 
{
	sqlite3_stmt *stmt;

	std::stringstream ss;
	ss << "INSERT INTO CAMAREROS (dni,nombre,apellido,tel,salario) values (" << dni << ",'" << nombre << "','" << apellido << "'," << tel << ",500);";
	std::string ssql = ss.str();
	char* sql = new char[ssql.length() + 1];
	strcpy(sql, ssql.c_str());
	
	int result = sqlite3_prepare_v2(db,sql,-1,&stmt, NULL) ;
	if (result != SQLITE_OK) 
	{
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) 
	{
		cout << "ERROR. El DNI ya existe.\n" << endl;
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) 
	{
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}
	return SQLITE_OK;
}

int altaPersona (sqlite3 *db,int dni, string nombre,string apellido, int tel) 
{
	sqlite3_stmt *stmt;

	std::stringstream ss;
	ss << "INSERT INTO CAMAREROS (dni,nombre,apellido,tel) values (" << dni << ",'" << nombre << "','" << apellido << "'," << tel << ");";
	std::string ssql = ss.str();
	char* sql = new char[ssql.length() + 1];
	strcpy(sql, ssql.c_str());
	
	int result = sqlite3_prepare_v2(db,sql,-1,&stmt, NULL) ;
	if (result != SQLITE_OK) 
	{
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) 
	{
		cout << "ERROR. El DNI ya existe.\n" << endl;
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) 
	{
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}
	return SQLITE_OK;
}

