#ifndef _PERSONA_H_
#define _PERSONA_H_

class Persona
{
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

	void print() const;
};

#endif