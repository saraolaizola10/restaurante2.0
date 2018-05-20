#include "Comanda.h"
#include <string.h>

#include <iostream>
using namespace std;

Comanda:: Comanda(int dni, int fechayhora, float total, float media): dni(dni), fechayhora(fechayhora), total(total), media(media)
{
	this->dni=dni;
	this->fechayhora=fechayhora;
	this->total=total;
	this->media=media;
}


int Comanda::getDni() const
{
	return this->dni;
}
int Comanda::getFechayhora() const
{
	return this->fechayhora;
}
float Comanda::getTotal() const
{
	return this->total;
}
float Comanda::getMedia() const
{
	return this->media;
}