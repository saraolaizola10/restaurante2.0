#ifndef _FRCAMARERO_H
#define _FRCAMARERO_H

#include "../LD/sqlite3.h"

int pedirDNI(sqlite3 *db);
int getNumeroMesa(int MESAS);
void AtenderMesa(sqlite3 *db,int *cuentas[],int mesa);
void AltaComanda(sqlite3 *db,int dni,int **cuentas, int mesa);

#endif