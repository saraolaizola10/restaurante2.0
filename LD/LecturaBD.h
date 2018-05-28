#ifndef _LECTURABD_H
#define _LECTURABD_H

#include "../LD/sqlite3.h"
#include "../LN/Persona.h"
#include "../LN/Administrador.h"
#include "../LN/Camarero.h"
#include "../LN/Producto.h"
#include "../LN/Categoria.h"
#include "../LN/Comanda.h"
#include <list>
#include <vector>

list <Administrador> getAdministradores (sqlite3 *db);
list <Camarero> getCamareros (sqlite3 *db);
vector <Persona*> getPersonas(sqlite3 *db);
list <Comanda> getComandas (sqlite3 *db);
list <Producto> getProductos (sqlite3 *db);
list <Categoria> getCategorias (sqlite3 *db);

#endif