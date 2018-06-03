#include "Utilidades.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEN 50

int getLongitud (int num)
{
	int longitud = floor(log10(abs(num))) + 1;
	return longitud;
}

char* ComaAPunto (char* input)                                         
{
    int i;
   	for (i = 0; i<strlen(input); i++)          
    {
        if (input[i]==',')  
        {
        	input[i]='.';
        }                                           
    }
   	return input;
}

int getHora()
{
  time_t now = time(0);
  int fyh = (int) now;
  return fyh;
}

int getMes (int f)
{
  int mes;

  time_t fecha;
  struct tm *tm;

  fecha = (time_t) f;
  tm = localtime (&fecha);
  mes = tm->tm_mon;

  return mes;
}

int getDia(int f)
{
  int dia;

  time_t fecha;
  struct tm *tm;

  fecha = (time_t) f;
  tm = localtime (&fecha);
  dia = tm->tm_mday;

  return dia;
}

void mostrarHora()
{
  time_t now = time(0);
  struct tm *tm;
  tm = localtime (&now);
  printf ("    %04d/%02d/%02d %02d:%02d \n",tm->tm_year+1900,tm->tm_mon+1,tm->tm_mday,tm->tm_hour,tm->tm_min);
}

void mostrarAnyo(int f)
{
  int anyo;
  time_t fecha;
  struct tm *tm;

  fecha = (time_t) f;
  tm = localtime (&fecha);
  anyo = tm->tm_year+1900;

  printf("%04d",anyo);
}

void mostrarDia()
{
  char *meses[] = {"ENERO","FEBRERO","MARZO","ABRIL","MAYO","JUNIO","JULIO","AGOSTO","SEPTIEMBRE","OCTUBRE","NOVIEMBRE","DICIEMBRE"};
  int dia,mes;

  time_t now = time(0);
  struct tm *tm;
  tm = localtime (&now);
  dia = tm->tm_mday;
  mes = tm->tm_mon+1;

  printf("%02d de %s",dia,meses[mes]);

}

void mostrarHorayMinuto(int f)
{
  int hora,minuto;
  time_t fecha;
  struct tm *tm;

  fecha = (time_t) f;
  tm = localtime (&fecha);
  hora = tm->tm_hour;
  minuto = tm->tm_min;

  printf("%02d:%02d",hora,minuto);
}