#ifndef _LECTURABD_H
#define _LECTURABD_H

#include "../LD/sqlite3.h"
#include "../LN/Camarero.h"
#include <list>

list <Camarero> getCamareros (sqlite3 *db);

#endif