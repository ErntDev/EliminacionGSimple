#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void ingresarCoeficientes(double *M[], int n)
{
    int i,j;

    puts("\n\tIngrese los coeficientes.");
    for (i=0;i<n;i++)
    {
        printf("\nEcuacion %d\n",i+1);
        for(j=0;j<n;j++) {
            printf("X%d: ",j+1);
            scanf("%lf",&M[i][j]);
        }
    }
    puts("\n\tIngrese cada uno de los terminos independientes.");

    for (i=0;i<n;i++)
    {
        printf("C%d: ",i+1);
        scanf("%lf",&M[i][n]);
    }
}

void mostrarSistemaEcuaciones(double *M[], int n)
{
    int i,j;
    puts("\n\t\tSistema de ecuaciones: ");
    for (i=0;i<n;i++)
    {
        printf("\t\t");
        for(j=0;j<n;j++)
            printf("%c%gx%d\t",M[i][j]>0?'+':8,M[i][j],j+1);
        printf("= %g\n",M[i][n]);
    }
}

void gaussSimpleEtapa1(double *M[],int n)
{
    int i,j,k,pivote=0;
    double a,coef;
    double EcNormPorCoef[n],EcNormalizada[n];

    for (i=0;i<n-2;i++)
    {
        a=M[i][pivote];
        for (j=0;j<n;j++)
            //Normalizar
            EcNormalizada[j]=M[i][j]/a;

        for (j=i+1;j<n-1;j++)
        {
            coef=M[j][pivote];
            //Multiplicar el coeficiente por la ecuación normalizada
            for (k=0;k<n;k++)
                EcNormPorCoef[k]=coef*EcNormalizada[k];

            //Restar la ecuación original menos la ecuaciónNorm*Coef.
            for (k=0;k<n;k++)
            {
                M[j][k]=M[j][k]-EcNormPorCoef[k];
            }
        }
        pivote++;
    }
}

void gaussSimpleEtapa2(double *M[], double *X, int n)
{
    int i,j;
    int p=n;
    double suma=0;

    for (i=0;i<n-2;i++)
        X[i]=0;

    for (i=n-1;i>=0;i--)
    {
        suma=0;
        for (j=n-1;j>=0;j--)
        {
            if (j==i)
                continue;
            suma+=((M[i][j])*X[j]);
        }
        //Despeje
        X[i]=(M[i][n]-suma)/M[i][p-1];
        p--;
    }
}
