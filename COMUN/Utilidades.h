#ifndef _UTILIDADES_H
#define _UTILIDADES_H

#ifdef __cplusplus
extern "C" 
{
	#endif

	int getLongitud (int num);
	char* ComaAPunto (char* input);

	int getHora();
	void mostrarHora();
	int getMes(int f);
	void mostrarAnyo(int f);

	#ifdef __cplusplus
}
#endif 

#endif