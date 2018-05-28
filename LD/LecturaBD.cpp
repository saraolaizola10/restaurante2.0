#include "LecturaBD.h"
#include "../LN/Administrador.h"
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
#include <algorithm>
#include <list>

using namespace std;

list <Camarero> getCamareros (sqlite3 *db)
{
	sqlite3_stmt *stmt;
	
	char sql[] = "SELECT DNI,NOMBRE,APELLIDO,TEL,TURNO,SUELDO FROM CAMAREROS";
	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) 
		cout << sqlite3_errmsg(db) << endl;

	list <Camarero> listaCamareros {};
	int tel, dni;
	float sueldo;
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
			strcpy(str, (char *) sqlite3_column_text(stmt, 4));
			string turno (str);
			sueldo = sqlite3_column_double(stmt, 5);
			Camarero a (nombre,apellido,dni,tel,turno,sueldo);
			listaCamareros.push_back(a);
		}
	} while (result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) 
		cout << sqlite3_errmsg(db) << endl;

	return listaCamareros;
}

list <Administrador> getAdministradores (sqlite3 *db)
{
	sqlite3_stmt *stmt;
	
	char sql[] = "SELECT DNI,NOMBRE,APELLIDO,TEL,CARGO,SUELDO FROM ADMINISTRADORES";
	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) 
		cout << sqlite3_errmsg(db) << endl;

	list <Administrador> listaAdministradores {};
	int tel, dni;
	float sueldo;
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
			strcpy(str, (char *) sqlite3_column_text(stmt, 4));
			string cargo (str);
			sueldo = sqlite3_column_double(stmt, 5);
			Administrador a (nombre,apellido,dni,tel,cargo,sueldo);
			listaAdministradores.push_back(a);
		}
	} while (result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) 
		cout << sqlite3_errmsg(db) << endl;

	return listaAdministradores;
}


vector <Persona*> getPersonas (sqlite3 *db)
{
    sqlite3_stmt *stmt1;
    sqlite3_stmt *stmt2;
    
    char sql1[] = "SELECT DNI,NOMBRE,APELLIDO,TEL,TURNO,SUELDO FROM CAMAREROS";
    int result1 = sqlite3_prepare_v2(db, sql1, -1, &stmt1, NULL) ;
    if (result1 != SQLITE_OK) 
        cout << sqlite3_errmsg(db) << endl;

    char sql2[] = "SELECT DNI,NOMBRE,APELLIDO,TEL,CARGO,SUELDO FROM ADMINISTRADORES";
    int result2 = sqlite3_prepare_v2(db, sql2, -1, &stmt2, NULL) ;
    if (result2 != SQLITE_OK) 
        cout << sqlite3_errmsg(db) << endl;

   	vector <Persona*> listaPersonas {};
    int tel, dni;
    float sueldo;
    char str [100];

    do
    {
        result1 = sqlite3_step(stmt1);
        if (result1 == SQLITE_ROW) 
        {
            dni = sqlite3_column_int(stmt1, 0);
            strcpy(str, (char *) sqlite3_column_text(stmt1, 1));
            string nombre (str);
            strcpy(str, (char *) sqlite3_column_text(stmt1, 2));
            string apellido (str);
            tel = sqlite3_column_int(stmt1, 3);
            strcpy(str, (char *) sqlite3_column_text(stmt1, 4));
            string turno (str);
            sueldo = sqlite3_column_double(stmt1, 5);
            
            Persona *b =  new Camarero (nombre,apellido,dni,tel,turno,sueldo);
            listaPersonas.push_back(b);
        }
    } while (result1 == SQLITE_ROW);

    do
    {
        result2 = sqlite3_step(stmt2);
        if (result2 == SQLITE_ROW) 
        {
            dni = sqlite3_column_int(stmt2, 0);
            strcpy(str, (char *) sqlite3_column_text(stmt2, 1));
            string nombre (str);
            strcpy(str, (char *) sqlite3_column_text(stmt2, 2));
            string apellido (str);
            tel = sqlite3_column_int(stmt2, 3);
            strcpy(str, (char *) sqlite3_column_text(stmt2, 4));
            string cargo (str);
            sueldo = sqlite3_column_double(stmt2, 5);
            Persona *b = new Administrador (nombre,apellido,dni,tel,cargo,sueldo);
            listaPersonas.push_back(b);
        }
    } while (result2 == SQLITE_ROW);

    result1 = sqlite3_finalize(stmt1);
    if (result1 != SQLITE_OK) 
        cout << sqlite3_errmsg(db) << endl;
    result2 = sqlite3_finalize(stmt2);
    if (result2 != SQLITE_OK) 
        cout << sqlite3_errmsg(db) << endl;

    sort(listaPersonas.begin(), listaPersonas.end());

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