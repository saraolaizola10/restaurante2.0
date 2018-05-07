#include "utilidades.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>


#define MAX_LEN 50

void clear_if_needed(char *str)
{
	if (str[strlen(str)-1] != '\n')
	{
		int c;    
    	while ( (c = getchar()) != EOF && c != '\n');
    }
}

char* quitarEspacio (char* input)                                         
{
    int i,j;
    char *output=input;
    for (i = 0, j = 0; i<strlen(input); i++,j++)          
    {
        if (input[i]!=' ')                           
            output[j]=input[i];                     
        else
            j--;                                     
    }
    output[j]=0;
    return output;
}

char* EspacioA_ (char* input)                                         
{
    int i;
   	for (i = 0; i<strlen(input); i++)          
    {
        if (input[i]==' ')  
        {
        	input[i]='_';
        }                                           
    }
   	return input;
}

char* _AEspacio (char* input)                                         
{
    int i;
   	for (i = 0; i<strlen(input); i++)          
    {
        if (input[i]=='_')  
        {
        	input[i]=' ';
        }                                           
    }
   	return input;
}

char * toUpper (char *input)
{
	int i;
	for (i=0;i<strlen(input);i++)
	{
      toupper(input[i]);
   	}
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

float pedirFloat ()
{
	char str[MAX_LEN];
	int num,lenght,punto;
	float input=0;

	do
	{
		num=0;
		punto=0;

		fgets(str,50,stdin);
		
		clear_if_needed(str);
		ComaAPunto(str);
		lenght = strlen(str)-1;;

		for (int i=0;i<lenght;i++)
		{
			if ((!isdigit(str[i])&&(str[i]!='.')))
			{	
				num=1;
				break;
			}
			if (str[i]=='.')
				punto++;
		}
		if ((num!=0)||(punto>1))
			printf("Error. Asegurate de introducir un numero\n");

	} while ((num!=0)||(punto>1));
	
	sscanf(str,"%f",&input);

	return input;
}

int pedirNumero ()
{
	char str[MAX_LEN];
	int input,lenght,num;;

	do
	{
		num=0;
		fgets(str,50,stdin);
		lenght = strlen (str)-1;

		for (int i=0;i<lenght;i++)
		{
			if (!isdigit(str[i]))
			{
				num=1;
				break;
			}	

		}
		if (num!=0)
			printf("Error. Asegurate de introducir un numero\n");

	} while (num!=0);
	
	clear_if_needed(str);
	sscanf(str,"%d",&input);
	return input;
}


void linea()
{
	printf("\n _______________________________________ \n");
}
