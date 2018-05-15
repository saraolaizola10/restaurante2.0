#ifndef _FRADMINISTRADOR_H
#define _FRADMINISTRADOR_H

#include "../LD/sqlite3.h"

int comprobarClave();
void cambiarClave();

void AltaCamarero(sqlite3 *db);
void AltaCategoria();
void AltaProducto();
void EditarProducto();
void EliminarProducto();

//void listaPlantilla();
//void mediaCamarero ();
//void actividadCamarero ();
//void valorMedioComandas ();
//void mediaServicio ();
//void PrecioMedioProductosxCategoria ();
//void importeXmes ();

#endif