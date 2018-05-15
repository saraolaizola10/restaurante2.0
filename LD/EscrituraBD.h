#ifndef _ESCRITURABD_H
#define _ESCRITURABD_H

#include <string.h>
#include <iostream>
#include "../LD/sqlite3.h"
using namespace std;

int iniciarBD(sqlite3 *db);
int altaCamarero (sqlite3 *db,int dni, std::string nombre, std::string apellido, int tel);

#endif