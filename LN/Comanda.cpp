#include "Comanda.h"
#include <string.h>

#include <iostream>
using namespace std;

Comanda:: Comanda(int dni, int fechayhora, float total, float media): dni(dni), fechayhora(fechayhora), total(total), media(media){}



Comanda:: ~Comanda(){}

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



void Comanda::setDni(const int dni)
{
	this->dni = dni;
}
void Comanda::setFechayhora(const int fyh)
{
	this->fechayhora = fyh;
}
void Comanda::setTotal(const float tot)
{
	this->total = tot;
}		
void Comanda::setMedia(const float med)
{
	this->media = med;
}