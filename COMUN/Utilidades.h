#ifndef _UTILIDADES_H
#define _UTILIDADES_H

#ifdef __cplusplus
extern "C" 
{
	#endif

	int getLongitud (int num);
	char* ComaAPunto (char* input);

	int getHora();
	int getDia(int f);
	int getMes(int f);

	void mostrarHora();
	void mostrarAnyo(int f);
	void mostrarDia();
	void mostrarHorayMinuto(int f);

	#ifdef __cplusplus
}
#endif 

#endif