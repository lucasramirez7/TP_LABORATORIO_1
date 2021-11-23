/*
 ============================================================================
 Name        : TP_[1].c
 Author      : Ramirez Lucas
 Description : Calculadora
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "mi libreria.h"
#define NADA 0
#define PRIMER_INGRESO 1
#define SEGUNDO_INGRESO 2
#define OPERAR 3
#define MOSTRAR 4

int main(){


    char seguir = 's';
    int numeroUno = 0, numeroDos = 0;
    int suma = 0, resta = 0, multiplicacion = 0, factorialUno = 0, factorialDos = 0;
    int okDivision = 0;
    float division = 0;
    int flag = NADA;


    do{

    switch(menu(numeroUno, numeroDos)){

    case 1:
    system("cls");
    numeroUno = ingreseEntero(numeroUno);
    flag = PRIMER_INGRESO;
    break;

    case 2:

    if(flag == PRIMER_INGRESO)
    {
        system("cls");
        numeroDos = ingreseEntero(numeroDos);
        flag = SEGUNDO_INGRESO;
        break;
    }
    else
    {
        printf("\n*****Antes debes ingresar el primer numero***** \n");

    }

    break;

    case 3:
    if(flag == SEGUNDO_INGRESO){
        system("cls");
        flag = OPERAR;
        suma = sumar(numeroUno, numeroDos);
        resta = restar(numeroUno, numeroDos);
        okDivision = dividir(numeroUno,numeroDos,&division);
        multiplicacion = multiplicar(numeroUno, numeroDos);
        factorialUno = factorial(numeroUno);
        factorialDos = factorial(numeroDos);

    }
    else if (flag == PRIMER_INGRESO){
        printf("\n*****Antes debes ingresar el segundo numero para operar***** \n");

    }
    else{
        printf("\n*****Antes debes ingresar los numeros para operar***** \n");

    }
    break;

    case 4:
    if (flag == OPERAR){
        system("cls");
        printf("El resultado de la suma entre %d y %d da: %d \n",numeroUno, numeroDos, suma);
        printf("El resultado de la resta entre %d y %d da: %d \n",numeroUno, numeroDos, resta);

        printf("El resultado de la multiplicacion entre %d y %d da: %d \n",numeroUno, numeroDos, multiplicacion);
        if(okDivision == 1){

        	printf("El resultado de la division entre %d y %d da: %0.2f \n",numeroUno,numeroDos, division);
        }
        else{
        	printf("No se puede dividir por cero");
        }

        printf("El resultado del factorial de %d da: %d \n",numeroUno, factorialUno);
        printf("El resultado del factorial de %d da: %d \n",numeroDos, factorialDos);

    }
    else
    {
        printf("\n*****Antes debes realizar las operaciones***** \n");

    }
    break;

    case 5:
        seguir = 'n';
    break;

    default:
        system("cls");
        printf("Opcion incorrecta (Pulsa enter e intentelo nuevamente). \n \n");
        break;
    }

    system("pause");

    }while(seguir == 's');

    return 0;
}
