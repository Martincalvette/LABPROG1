#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    char nombre[70];
    int edad;
    float altura;
} Persona;
int printPersona(Persona* per);
int altaPersona (Persona* pp);


int main ()
{

    Persona martin;
    martin.altura =1.81;
    martin.edad=22;
    strncpy(martin.nombre,"Martin",70);

    altaPersona(&martin);
    printPersona(&martin);
}


void printPersona(Persona* per)
{
    printf("%s %d %f",per->nombre,per->edad,per->altura);
}

void altaPersona (Persona* pp)
{
    /** usar biblioteca get entero, get char y get float*/
    printf("Ingrese nombre:\n");
    printf("Ingrese edad:\n");
    printf("Ingrese altura:\n");

    scanf("%s %d %f",pp->nombre,pp->edad,pp->altura);


}
