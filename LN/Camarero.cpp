#include "Camarero.h"
#include <iostream>
using namespace std;

Camarero::Camarero(const char* nombre, const char* apellido, int tel, int dni): Persona(nombre, apellido, tel, dni)
{
	
}

Camarero::Camarero(const Camarero &c) : Persona(c)
{
	
}

Camarero::~Camarero()
{

}
