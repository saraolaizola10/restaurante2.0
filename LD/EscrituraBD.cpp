#include "EscrituraBD.h"
#include "sqlite3.h"
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
using namespace std;

int iniciarBD(sqlite3 *db)
{
	char *err_message=0;
	int rc;
	//=sqlite3_open("BD.sqlite",&db);
 
 	//if (rc!=SQLITE_OK) 
	//{
	//	cout << stderr << "Can not open the database: " << sqlite3_errmsg(db) << endl;
	//	sqlite3_close(db);
	//	return 1;
	//}
	//else
	//{
	//	cout << "Database Opened successfully\n" << endl;
  	//}

	const char *sql_query = "CREATE TABLE CAMAREROS(DNI INT PRIMARY KEY NOT NULL, NOMBRE TEXT, APELLIDO TEXT, TEL INT);";
 
  	rc = sqlite3_exec(db, sql_query, 0, 0, &err_message);
 
  	if (rc != SQLITE_OK ) 
  	{
    	cout << "SQL error: " << err_message << endl;
 
   		sqlite3_free(err_message);
    	sqlite3_close(db);
 
    	return 1;
  	} 
  	else 
  	{
    	cout << "Table CAMAREROS created successfully\n" << endl;
  	}
}


int altaCamarero (sqlite3 *db,int dni, string nombre,string apellido, int tel) 
{
	sqlite3_stmt *stmt;

	std::stringstream ss;
	ss << "INSERT INTO CAMAREROS values (" << dni << ",\"" << nombre << "\",\"" << apellido << "\"," << tel << ");";
	std::string ssql = ss.str();
	char* sql = new char[ssql.length() + 1];
	strcpy(sql, ssql.c_str());
	cout << sql << endl;

	//string sqlstatement = "INSERT INTO CAMAREROS (dni,nombre,apellido,tel) values (" + dni + "," + nombre + "," + apellido + "," + tel + ");";

	int result = sqlite3_prepare_v2(db,sql,-1,&stmt, NULL) ;
	if (result != SQLITE_OK) 
	{
		cout << "Error preparing statement (INSERT)\n" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}

	cout << "SQL query prepared (INSERT)\n" << endl;

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) 
	{
		cout << "Error inserting new data into country table\n" << endl;
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		cout << "Error finalizing statement (INSERT)\n"<< endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}

	cout << "Prepared statement finalized (INSERT)\n" << endl;

	return SQLITE_OK;
}
//ALTA CAMARERO

//ALTA CATEGORIA

//ALTA PRODUCTO