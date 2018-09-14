#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i;
    int numeros[5];

    for (i=0;i<5;i++)
    {
        printf("Ingrese numero:\n");
        scanf("%d",&numeros[i]); /**PASAR DIRECCION DEL INDICE DEL ARRAY*/
    }

    insertion(numeros,5);
    for (i=0;i<5;i++)
    {
        printf("%d\n",numeros[i]);
    }

}
