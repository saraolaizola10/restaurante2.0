#ifndef _COMANDA_H
#define _COMANDA_H

class Comanda
{
private:
	int dni;
	int fechayhora;
	float total;
	float media;

public:
	Comanda(int dni, int fechayhora, float total, float media);
	Comanda(const Comanda &c);
	virtual ~Comanda();	

};

#endif