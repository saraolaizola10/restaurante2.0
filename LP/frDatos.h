#ifndef _FRDATOS_H
#define _FRDATOS_H

#include "../LD/sqlite3.h"

int totalCamareros (sqlite3 *db);
int nuevoCamarero (sqlite3 *db, int dni);
void mostrarCamareros(sqlite3 *db);

//void listaPlantilla();
//void mediaCamarero ();
//void actividadCamarero ();
//void valorMedioComandas ();
//void mediaServicio ();
//void PrecioMedioProductosxCategoria ();
//void importeXmes ();

#endif