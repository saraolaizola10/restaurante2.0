#ifndef _PERSONA_H
#define _PERSONA_H

class Persona
{
private:
	char *nombre;
	char *apellido;
	int tel;
	int dni;
	
public:
	Persona(const char* nombre, const char* apellido, int tel, int dni);
	Persona(const Persona &p);
	virtual ~Persona();

	const char* getNombre();
	const char* getApellido();
	int getTel();
	int getDni();

};

#endif