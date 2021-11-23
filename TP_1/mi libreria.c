#include <stdio.h>
#include <stdlib.h>
#include "mi libreria.h"

int menu(int num1, int num2){

    int opc;

    system("cls");
    puts("**********Menu de opciones********** \n \n");
    printf("1. Ingresar 1er operando (A= %d) \n", num1);
    printf("2. Ingresar 2do operando (B= %d) \n", num2);
    printf("3. Calcular todas las operaciones \n");
    printf("4. Informar resultados \n");
    printf("5. Salir \n \n");
    printf("Ingrese Opcion: ");
    scanf("%d", &opc);

    return opc;

}

int ingreseEntero(int num1){

    printf("********Ingrese el primer numero ********\n");
    scanf("%d", &num1);
    return num1;

}


int sumar(int num1, int num2){

   return num1 + num2;

}

int restar(int num1, int num2){

   return num1 - num2;

}

int multiplicar(int num1, int num2){

    return num1 * num2;
}

int dividir(int num1, int num2, float* resultado){

	int todoOk = 0;

	if(num2!=0)
	{
	todoOk = 1;
	*resultado = (float) num1 / num2;
	}

	return todoOk;
}


int factorial (int num){

    if (num == 0 || num == 1){
    return 1;
    }
    else{
    return num * factorial (num - 1);
    }
}

