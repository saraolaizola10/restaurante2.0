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

	int getDni() const;
	int getFechayhora() const;
	float getTotal() const;
	float getMedia() const;
};

#endif