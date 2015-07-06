/*
Elaborado por   :Ernesto García Maldonado
Carrera         :Ingeniería en Tecnologías Computacionales
*/
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    double **M;    //Guardar los coeficientes del sistema de ecuaciones
    double *X;
    int i,n;

    puts("   ::Programa para resolver un sistema de ecuaciones simultaneas lineales::");
    puts("\t\t   por el metodo de eliminacion gaussiana");

    do
    {
        printf("\nNumero de ecuaciones [2-8]: ");
        scanf("%d",&n);
    } while (n<2 || n>8);

    X=(double*)calloc(n,sizeof(double));
    M=(double**)calloc(n,sizeof(double*));

    for (i=0;i<n;i++)
        M[i]=(double*)calloc(n+1,sizeof(double));

    ingresarCoeficientes(M,n);
    mostrarSistemaEcuaciones(M,n);
    gaussSimpleEtapa1(M,n+1);
    gaussSimpleEtapa2(M,X,n);

    printf("\n\n\t\tSistema triangular Superior");
    mostrarSistemaEcuaciones(M,n);

    printf("\n\n\t\tRaices del sistema de ecuaciones\n");
    for (i=0;i<n;i++)
        printf("\t\tX%d=%.9lf\n",i+1,X[i]);

    return 0;
}
