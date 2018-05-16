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

	int getDni();
	int getFechayhora();
	float getTotal();
	float getMedia();

	void setDni(const int dni);
	void setFechayhora(const int fyh);
	void setTotal(const float tot);		
	void setMedia(const float med);
};

#endif