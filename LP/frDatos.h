#ifndef _FRDATOS_H
#define _FRDATOS_H

#include "../LD/sqlite3.h"

int totalCamareros (sqlite3 *db);
int nuevoCamarero (sqlite3 *db, int dni);
void mostrarCamareros(sqlite3 *db);

int MesaOcupada(int *cuentas[],int mesa,int nueva);
int MostrarProductosxCategoria (sqlite3 *db,string categoria);
int getProducto(sqlite3 *db,string categoria, int opcion);
void ImprimirCuenta (sqlite3 *db,int **cuentas, int mesa);
float totalCuenta(sqlite3 *db,int **cuentas, int mesa);

//void listaPlantilla();
//void mediaCamarero ();
//void actividadCamarero ();
//void valorMedioComandas ();
//void mediaServicio ();
//void PrecioMedioProductosxCategoria ();
//void importeXmes ();

#endif