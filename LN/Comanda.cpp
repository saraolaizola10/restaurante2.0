#include "Comanda.h"
#include <string.h>

#include <iostream>
using namespace std;

Comanda:: Comanda(int dni, int fechayhora, float total, float media): dni(dni), fechayhora(fechayhora), total(total), media(media){}


Comanda:: Comanda(const Comanda &c)
{
	this->dni= c.dni;
	this->fechayhora = c.fechayhora;
	this->total= c.total;
	this->media = c.media;
}
Comanda:: ~Comanda()
{
	
}

int Comanda::getDni()
{
	return this->dni;
}
int Comanda::getFechayhora()
{
	return this->fechayhora;
}
float Comanda::getTotal()
{
	return this->total;
}
float Comanda::getMedia()
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