#ifndef _UTILIDADES_H
#define _UTILIDADES_H

#ifdef __cplusplus
extern "C" {
#endif

void clear_if_needed(char *str);
char* quitarEspacio (char* input);
char* EspacioA_ (char* input);
char* _AEspacio (char* input);
char * toUpper (char *input);
char* ComaAPunto (char* input);
int pedirNumero ();
float pedirFloat ();
void linea();

#ifdef __cplusplus
}
#endif 

#endif