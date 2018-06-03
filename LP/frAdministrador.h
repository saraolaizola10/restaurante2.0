#ifndef _FRADMINISTRADOR_H
#define _FRADMINISTRADOR_H

#include "../LD/sqlite3.h"

int comprobarClave();
void cambiarClave();

void AltaCategoria(sqlite3 *db);
void AltaProducto(sqlite3 *db);
void EditarProducto(sqlite3 *db);
void EditarAdministrador(sqlite3 *db);
void EliminarProducto(sqlite3 *db);
void EliminarCamarero (sqlite3 *db);

#endif