#ifndef _FRADMINISTRADOR_H
#define _FRADMINISTRADOR_H

#include "../LD/sqlite3.h"

int comprobarClave();
void cambiarClave();

void AltaCamarero(sqlite3 *db);
void AltaAdministrador(sqlite3 *db);
void AltaCategoria(sqlite3 *db);
void AltaProducto(sqlite3 *db);
void EditarProducto(sqlite3 *db);
void EliminarProducto(sqlite3 *db);

#endif