#include "LecturaBD.h"
#include "../LN/Persona.h"
#include "../LN/Camarero.h"
#include "../LN/Producto.h"
#include "../LN/Categoria.h"
#include "../LN/Comanda.h"
#include "sqlite3.h"
#include <fstream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <list>
using namespace std;

list <Camarero> getCamareros (sqlite3 *db)
{
	sqlite3_stmt *stmt;
	
	char sql[] = "SELECT DNI,NOMBRE,APELLIDO,TEL,SALARIO FROM CAMAREROS";
	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) 
		cout << sqlite3_errmsg(db) << endl;

	list <Camarero> listaCamareros {};
	int tel, dni;
	float salario;
	char str [100];
	do
	{
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) 
		{
			dni = sqlite3_column_int(stmt, 0);
			strcpy(str, (char *) sqlite3_column_text(stmt, 1));
			string nombre (str);
			strcpy(str, (char *) sqlite3_column_text(stmt, 2));
			string apellido (str);
			tel = sqlite3_column_int(stmt, 3);
			salario = sqlite3_column_double(stmt,4);
			Camarero a (nombre,apellido,dni,tel,salario);
			listaCamareros.push_back(a);
		}
	} while (result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) 
		cout << sqlite3_errmsg(db) << endl;

	return listaCamareros;
}

list <Persona> getPersonas (sqlite3 *db)
{
	sqlite3_stmt *stmt;
	
	char sql[] = "SELECT DNI,NOMBRE,APELLIDO,TEL, FROM PERSONAS";
	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) 
		cout << sqlite3_errmsg(db) << endl;

	list <Persona> listaPersonas {};
	int tel, dni;
	char str [100];
	do
	{
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) 
		{
			dni = sqlite3_column_int(stmt, 0);
			strcpy(str, (char *) sqlite3_column_text(stmt, 1));
			string nombre (str);
			strcpy(str, (char *) sqlite3_column_text(stmt, 2));
			string apellido (str);
			tel = sqlite3_column_int(stmt, 3);
			Persona a (nombre,apellido,tel,dni);
			listaPersonas.push_back(a);
		}
	} while (result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) 
		cout << sqlite3_errmsg(db) << endl;

	return listaPersonas;
}

list <Producto> getProductos (sqlite3 *db)
{
	sqlite3_stmt *stmt;
	
	char sql[] = "SELECT ID,NOMBRE,CATEGORIA,PRECIO FROM PRODUCTOS";
	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) 
		cout << sqlite3_errmsg(db) << endl;

	list <Producto> listaProductos {};
	int id;
	float precio;
	char str [100];
	do
	{
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) 
		{
			id = sqlite3_column_int(stmt, 0);
			strcpy(str, (char *) sqlite3_column_text(stmt, 1));
			string nombre (str);
			strcpy(str, (char *) sqlite3_column_text(stmt, 2));
			string categoria (str);
			precio = sqlite3_column_double(stmt,3);
			Producto a (id,nombre,precio,categoria);
			listaProductos.push_back(a);
		}
	} while (result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) 
		cout << sqlite3_errmsg(db) << endl;

	return listaProductos;
}

list <Categoria> getCategorias (sqlite3 *db)
{
	sqlite3_stmt *stmt;
	
	char sql[] = "SELECT ID,NOMBRE,ORDEN FROM CATEGORIAS";
	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) 
		cout << sqlite3_errmsg(db) << endl;

	list <Categoria> listaCategorias {};
	int orden,id;
	char str [100];
	do
	{
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) 
		{
			id = sqlite3_column_int(stmt, 0);
			strcpy(str, (char *) sqlite3_column_text(stmt, 1));
			string nombre (str);
			orden = sqlite3_column_int(stmt, 2);
			Categoria a (id,nombre,orden);
			listaCategorias.push_back(a);
		}
	} while (result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) 
		cout << sqlite3_errmsg(db) << endl;

	return listaCategorias;
}

list <Comanda> getComandas (sqlite3 *db)
{
	sqlite3_stmt *stmt;
	
	char sql[] = "SELECT DNI,FECHAYHORA,TOTAL,MEDIA FROM COMANDAS";
	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) 
		cout << sqlite3_errmsg(db) << endl;

	list <Comanda> listaComandas {};
	int dni, fechayhora;
	float total, media;
	char str [100];
	do
	{
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) 
		{
			dni = sqlite3_column_int(stmt, 0);
			fechayhora = sqlite3_column_int(stmt, 1);
			total = sqlite3_column_double(stmt,2);
			media = sqlite3_column_double(stmt,3);
			Comanda a (dni,fechayhora,total,media);
			listaComandas.push_back(a);
		}
	} while (result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) 
		cout << sqlite3_errmsg(db) << endl;

	return listaComandas;
}
//GET PRODUCTOS
//...