#include "EscrituraBD.h"
#include "LecturaBD.h"
#include "../LN/Categoria.h"
#include "sqlite3.h"
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <list>
using namespace std;

void iniciarBD(sqlite3 *db)
{
	char *err_message=0;
	int rc;

	const char *sql_query = "CREATE TABLE CAMAREROS (DNI INT PRIMARY KEY NOT NULL, NOMBRE TEXT, APELLIDO TEXT, TEL INT, TURNO TEXT, SUELDO FLOAT);";
  	rc = sqlite3_exec(db, sql_query, 0, 0, &err_message);

  	const char *sql_query1 = "CREATE TABLE ADMINISTRADORES (DNI INT PRIMARY KEY NOT NULL, NOMBRE TEXT, APELLIDO TEXT, TEL INT, CARGO TEXT, SUELDO FLOAT);";
  	rc = sqlite3_exec(db, sql_query1, 0, 0, &err_message);

  	const char *sql_query2 = "CREATE TABLE PRODUCTOS (ID INT PRIMARY KEY NOT NULL, NOMBRE TEXT, CATEGORIA TEXT, PRECIO FLOAT);";
  	rc = sqlite3_exec(db, sql_query2, 0, 0, &err_message);

  	const char *sql_query3 = "CREATE TABLE CATEGORIAS (ID INT PRIMARY KEY NOT NULL, NOMBRE TEXT, ORDEN INT);";
  	rc = sqlite3_exec(db, sql_query3, 0, 0, &err_message);

  	const char *sql_query4 = "CREATE TABLE COMANDAS (DNI INT, FECHAYHORA INT PRIMARY KEY NOT NULL, TOTAL FLOAT, MEDIA FLOAT);";
  	rc = sqlite3_exec(db, sql_query4, 0, 0, &err_message);
}

int altaCamarero (sqlite3 *db,int dni, string nombre,string apellido, int tel, string turno, float sueldo) 
{
	sqlite3_stmt *stmt;

	std::stringstream ss;
	ss << "INSERT INTO CAMAREROS (dni,nombre,apellido,tel,turno,sueldo) values (" << dni << ",'" << nombre << "','" << apellido << "'," << tel << ",'" << turno << "'," << sueldo << ");";
	std::string ssql = ss.str();
	char* sql = new char[ssql.length() + 1];
	strcpy(sql, ssql.c_str());
	
	int result = sqlite3_prepare_v2(db,sql,-1,&stmt, NULL);
	result = sqlite3_step(stmt);
	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) 
	{
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}
	return SQLITE_OK;
}

int altaAdministrador (sqlite3 *db,int dni, string nombre,string apellido, int tel,string cargo, float sueldo) 
{
	sqlite3_stmt *stmt;

	std::stringstream ss;
	ss << "INSERT INTO ADMINISTRADORES (dni,nombre,apellido,tel,cargo,sueldo) values (" << dni << ",'" << nombre << "','" << apellido << "'," << tel << ",'" << cargo <<"'," << sueldo << ");";
	std::string ssql = ss.str();
	char* sql = new char[ssql.length() + 1];
	strcpy(sql, ssql.c_str());
	
	int result = sqlite3_prepare_v2(db,sql,-1,&stmt, NULL) ;
	result = sqlite3_step(stmt);
	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) 
	{
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}
	return SQLITE_OK;
}

int altaProducto (sqlite3 *db,int id, string nombre,string categoria, float precio) 
{
	sqlite3_stmt *stmt;

	std::stringstream ss;
	ss << "INSERT INTO PRODUCTOS (id,nombre,categoria,precio) values (" << id << ",'" << nombre << "','" << categoria << "'," << precio << ");";
	std::string ssql = ss.str();
	char* sql = new char[ssql.length() + 1];
	strcpy(sql, ssql.c_str());
	
	int result = sqlite3_prepare_v2(db,sql,-1,&stmt, NULL);
	result = sqlite3_step(stmt);
	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) 
	{
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}
	return SQLITE_OK;
}

int altaCategoria (sqlite3 *db,int id, string nombre, int orden) 
{
	sqlite3_stmt *stmt;

	std::stringstream ss;
	ss << "INSERT INTO CATEGORIAS (id,nombre,orden) values (" << id << ",'" << nombre << "'," << orden << ");";
	std::string ssql = ss.str();
	char* sql = new char[ssql.length() + 1];
	strcpy(sql, ssql.c_str());
	
	int result = sqlite3_prepare_v2(db,sql,-1,&stmt, NULL) ;
	result = sqlite3_step(stmt);
	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) 
	{
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}
	return SQLITE_OK;
}

int ordenarCategorias (sqlite3 *db,Categoria newCat)
{
	char *errMsg=0;
	int antes=0;

	list <Categoria> categorias = getCategorias(db);

	int rc = sqlite3_exec (db, "DROP TABLE CATEGORIAS", NULL, NULL, &errMsg);
	const char *sql_query = "CREATE TABLE CATEGORIAS (ID INT PRIMARY KEY NOT NULL, NOMBRE TEXT, ORDEN INT);";
  	rc = sqlite3_exec(db, sql_query, 0, 0, &errMsg);
	
	for (auto c: categorias)
	{
		if (c.getOrden()==newCat.getOrden())
		{
			altaCategoria(db,newCat.getId(),newCat.getNombre(),newCat.getOrden());
			antes++;
		}
		if (antes==0)
			altaCategoria(db,c.getId(),c.getNombre(),c.getOrden());
		else
			altaCategoria(db,c.getId(),c.getNombre(),c.getOrden()+1);
	}
}

int altaComanda (sqlite3 *db,int dni, int fechayhora, float total, float media) 
{
	sqlite3_stmt *stmt;

	std::stringstream ss;
	ss << "INSERT INTO COMANDAS (dni,fechayhora,total,media) values (" << dni << "," << fechayhora << "," << total << "," << media << ");";
	std::string ssql = ss.str();
	char* sql = new char[ssql.length() + 1];
	strcpy(sql, ssql.c_str());
	
	int result = sqlite3_prepare_v2(db,sql,-1,&stmt, NULL) ;
	result = sqlite3_step(stmt);
	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) 
	{
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}
	return SQLITE_OK;
}

int updateProducto (sqlite3 *db,int id, string nombre, float precio)
{
	sqlite3_stmt *stmt;

	std::stringstream ss;
	ss << "UPDATE PRODUCTOS SET nombre='"<<nombre<<"',precio="<<precio<<") where (id="<<id<<");";
	std::string ssql = ss.str();
	char* sql = new char[ssql.length() + 1];
	strcpy(sql, ssql.c_str());
	
	int result = sqlite3_prepare_v2(db,sql,-1,&stmt, NULL) ;
	result = sqlite3_step(stmt);
	if (result != SQLITE_OK) 
	{
		cout << "Id no encontrado." << endl;
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

int updateAdministrador (sqlite3 *db,int dni, int tel,string cargo, float sueldo) 
{
	sqlite3_stmt *stmt;

	std::stringstream ss;
	ss << "UPDATE PRODUCTOS SET tel="<<tel<<",cargo='"<<cargo<<"',sueldo="<<sueldo<<") where (dni="<<dni<<");";
	std::string ssql = ss.str();
	char* sql = new char[ssql.length() + 1];
	strcpy(sql, ssql.c_str());
	
	int result = sqlite3_prepare_v2(db,sql,-1,&stmt, NULL) ;
	result = sqlite3_step(stmt);
	if (result != SQLITE_OK) 
	{
		cout << "Dni no encontrado." << endl;
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

int deleteProducto (sqlite3 *db,int id)
{
	sqlite3_stmt *stmt;

	std::stringstream ss;
	ss << "DELETE FROM PRODUCTOS where (id="<<id<<");";
	std::string ssql = ss.str();
	char* sql = new char[ssql.length() + 1];
	strcpy(sql, ssql.c_str());
	
	int result = sqlite3_prepare_v2(db,sql,-1,&stmt, NULL) ;
	result = sqlite3_step(stmt);
	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) 
	{
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}
	return SQLITE_OK;
}

int deleteCamarero (sqlite3 *db,int dni)
{
	sqlite3_stmt *stmt;

	std::stringstream ss;
	ss << "DELETE FROM CAMAREROS where (dni="<<id<<");";
	std::string ssql = ss.str();
	char* sql = new char[ssql.length() + 1];
	strcpy(sql, ssql.c_str());
	
	int result = sqlite3_prepare_v2(db,sql,-1,&stmt, NULL) ;
	result = sqlite3_step(stmt);
	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) 
	{
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}
	return SQLITE_OK;
}




 
