#include "LecturaBD.h"
#include "sqlite3.h"
#include <fstream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
using namespace std;

int mostrarCamareros(sqlite3 *db)
{
	sqlite3_stmt *stmt;

	char sql[] = "SELECT DNI, NOMBRE, APELLIDO, TEL FROM CAMAREROS";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) 
	{
		cout << "Error preparing statement (SELECT)\n" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}

	cout << "SQL query prepared (SELECT)\n"<< endl;

	int tel, dni;
	char str [100];

	cout << "\n" << endl;
	cout << "\n" << endl;
	cout << "Mostrando camareros:\n" << endl;
	do
	{
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) 
		{
			dni = sqlite3_column_int(stmt, 0);
			strcpy(str, (char *) sqlite3_column_text(stmt, 1));
			string nombre (str);
			strcpy(str, (char *) sqlite3_column_text(stmt, 2));
			string apellido (str);
			tel = sqlite3_column_int(stmt, 3);
			cout << nombre << " " << apellido << " , tel: " << tel << " dni: " << dni << endl;
		}
	} while (result == SQLITE_ROW);

	cout << "\n" << endl;
	cout << "\n" << endl;
	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		cout << "Error finalizing statement (SELECT)\n" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}

	cout << "Prepared statement finalized (SELECT)\n" << endl;

	return SQLITE_OK;
}
//MOSTRAR CAMAREROS
//GET TOTAL CAMAREROS
//GET CAMARERO

//MOSTRAR PRODUCTOS
//GET TOTAL PRODUCTOS
//GET ID ULTIMO PRODUCTO

//MOSTRAS CATEGORIAS
//GET TOTAL CATEGORIAS