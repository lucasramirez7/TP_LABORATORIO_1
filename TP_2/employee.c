#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
#include "mi libreria.h"
#include "workStation.h"

int menu(){

    int opcion;


    system("cls");
    puts("********** GESTIONAR EMPLEADOS ********** \n \n");
    printf("1- Alta Empleado\n");
    printf("2- Baja Empleado\n");
    printf("3- Modificar Empleado\n");
    printf("4- Listar Empleados\n");
    printf("5- salir\n \n");
    printf("INGRESE OPCION: ");
    scanf("%d", &opcion);

    return opcion;

}

int setUpPeople(sEmployee list[], int size){

    int ok = 0;

    if(list != NULL && size > 0)
    {
        for(int i=0; i < size; i++)
        {
            list[i].isEmpty = 1;
        }
        ok = 1;
    }
    return ok;
}

int searchFree(sEmployee list[], int size){

    int index = -1;

    for(int i=0; i<size; i++)
    {
        if(list[i].isEmpty)
        {
            index = i;
            break;
        }

    }
    return index;
}


char orderChar(char completeName[], char name[], char lastName[]){

int i = 0;



    strcpy(completeName, lastName);
    strcat(completeName, ", ");
    strcat(completeName, name);

    strlwr(completeName);
    completeName[0] = toupper(completeName[0]);
    while(completeName[i] != '\0'){
         if(completeName [i] == ' '){
            completeName [i + 1] = toupper(completeName[i+1]);
         }

        i++;
    }


  return completeName;

}
int showPeople(sEmployee list[], int size, sWorkStation places[], int placeSize){
    int ok = 0;
    int flag = 1;

    if (list != NULL && size > 0)
    {
        system("cls");
        puts("******************LISTA DE EMPLEADOS******************\n \n ");
        puts("---------------------------------------------------------- \n");
        puts("   ID    NOMBRE COMPLETO         SALARIO        SECTOR   ");
        puts("---------------------------------------------------------- \n");

        for(int i=0; i<size; i++)
        {
            if(!list[i].isEmpty)
            {
                showPerson(list[i],places,placeSize);
                flag = 0;
            }
        }
        if(flag)
        {
            puts("-----------------------------------------");
            puts("-******No hay personas registradas******-");
            puts("-----------------------------------------");

        }
        ok = 1;
    }
    return ok;
}

void showPerson(sEmployee person,sWorkStation places[], int placeSize){

    char completeName[110];
    char descriptionPlace[110];

    orderChar(completeName,person.name,person.lastName);
    loadPlaceDescription(places,placeSize,person.sector,descriptionPlace);

    printf("  %-04d    %-15s         $%-7.2f      %-10s  \n",
           person.id,
           completeName,
           person.salary,
           descriptionPlace);

    printf("\n");
}

int subMenu(){

    int opcion;

    system("cls");
    puts("*********************INFORMAR*******************\n\n");
    puts("1- Listado de empleados (ordenados alfabéticamente por Apellido y Sector).\n");
    puts("2-total/promedio salario y los empleados que superan ese salario.\n");
    printf("0- Volver al menu \n");
    scanf("%d",&opcion);


    return opcion;

}
int searchPeopleId(sEmployee list[], int size,int id){

    int index = -1;

    for(int i=0; i<size; i++){
        if(list[i].id == id && list[i].isEmpty == 0){

                index = i;
                break;
            }
    }

 return index;
}

int registerPeople(sEmployee list[], int size,int* pId, sWorkStation places[], int sizePlaces){

    int ok = 0;
    int index;

    sEmployee auxPeople;

    if (list != NULL && size > 0)
    {

        system("cls");
        puts("**********ALTA EMPLEADO**********\n\n");
        index = searchFree(list, size);


        if(index == -1)
        {
            printf("No hay lugar \n");
        }
        else
        {

            auxPeople.id = *pId;
            (*pId)++;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(auxPeople.name);
            puts("---------------------------------------");
            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(auxPeople.lastName);
            puts("---------------------------------------");

            printf("Ingrese el salario: $ ");
            scanf("%f", &auxPeople.salary);
           /* while(!validateInt(auxPeople.salary,0,700000)){
            printf("ERROR!!! Ingrese el salario($0-$70000): $ ");
            scanf("%f", &auxPeople.salary);
            }*/

            puts("---------------------------------------");
            do{
            system("cls");
            showPlace(places,sizePlaces);
            printf("Ingrese el sector: ");
            scanf("%d",&auxPeople.sector);
            puts("---------------------------------------");
            auxPeople.isEmpty = 0;
            }while(!validateInt(auxPeople.sector,2000,2004));

            list[index] = auxPeople;


        }
        ok = 1;
    }
    return ok;
}
int modifyPeople(sEmployee list[], int size,int id, sWorkStation places[], int sizePlaces){

    int ok = 0;
    int index;
    int opcion;
    char confirm;

    if(list != NULL && size > 0){
        system("cls");
        puts("**********MODIFICAR EMPLEADO**********\n\n");
        showPeople(list,size,places,sizePlaces);
        printf("Ingrese ID: ");
        scanf("%d", &id);

        index = searchPeopleId(list,size,id);
        if(index == -1){
            printf("ERROR!! El ID: %d no corresponde a un empleado\n", id);
        }
        else{
            showPerson(list[index],places,sizePlaces);
            do{
            system("cls");
            printf("Seguro queres modificar?(s/n): ");
            fflush(stdin);
            scanf("%c", &confirm);
            }while(!validateChar(confirm,'s','n'));
            if(confirm == 's'){

                    do{
                    system("cls");
                    puts("Que dato modificamos?");
                    puts("1- Nombre");
                    puts("2- Apellido");
                    puts("3- salario");
                    puts("4- sector");
                    printf("ingrese opcion: ");
                    scanf("%d", &opcion);
                    }while(opcion < 0 && opcion > 4);

                switch(opcion)
                {
                case 1:
                    system("cls");
                    printf("El nombre es: %s \n", list[index].name);
                    puts("Ingrese el nuevo nombre para modificar: \n");
                    scanf("%s",&list[index].name);
                    ok = 1;
                    break;

                case 2:
                    system("cls");
                    printf("El nombre es: %s \n", list[index].lastName);
                    puts("Ingrese el nuevo nombre para modificar: \n");
                    scanf("%s",&list[index].lastName);
                    ok = 1;
                    break;

                case 3:
                    system("cls");
                    printf("El salario es: %.2f \n", list[index].salary);
                    puts("Ingrese el nuevo nombre para modificar: \n");
                    scanf("%f",&list[index].salary);
                    ok = 1;
                    break;

                case 4:
                    system("cls");
                    printf("El sector es: %d \n", list[index].sector);
                    showPlace(places,sizePlaces);
                    puts("Ingrese el nuevo nombre para modificar: \n");
                    scanf("%d",&list[index].sector);
                    ok = 1;
                    break;


                }
            }
            else{
                printf("*****Modificacion cancelada!****** \n");
            }
        }

    }
    return ok;

}
int removePerson(sEmployee list[], int size, sWorkStation places[], int sizePlaces){

    int ok = 0;
    int id;
    int index;


    char confirm;
    if(list != NULL && size > 0){
        system("cls");
        puts("------------------------BAJA DE EMPLEADOS------------------------\n\n");
        showPeople(list,size,places,sizePlaces);
        puts("\n");
        printf("Ingrese ID: ");
        scanf("%d", &id);

        index = searchPeopleId(list,size,id);
        if(index == -1){
            printf("ERROR!! El ID: %d no corresponde a un micro\n", id);
        }
        else{
            do{
            system("cls");
            showPerson(list[index],places,sizePlaces);
            printf("------------------------------------------------------------\n");
            printf("Confirma baja?(s/n): ");
            fflush(stdin);
            scanf("%c", &confirm);
            confirm = tolower(confirm);
            }while(!validateChar(confirm,'s','n'));
            if(confirm == 's'){
            list[index].isEmpty = 1;
            printf("*****Baja exitosa!****** \n");
            }
            else{
                printf("*****Baja cancelada!****** \n");
            }
        }

    }
    return ok;
}

int sortEmployeesByLastName(sEmployee list[], int size, int order){

    sEmployee aux;
    int flagSort = -1;
    if(order == 1)
    {
        for(int i=0 ; i < size - 1 ; i++)
        {
          for (int j = i + 1; j < size ; j++)
           {
             if (strcmp (list[i].lastName, list[j].lastName) > 0)
              {
                  aux=list[i];
                  list[i]=list[j];
                  list[j]=aux;
                  flagSort = 0;
              }

              if(strcmp (list[i].lastName, list[j].lastName) == 0)
              {
                   if(strcmp(list[i].name, list[j].name) > 0)
                   {
                        aux=list[i];
                        list[i]=list[j];
                        list[j]=aux;
                        flagSort = 0;
                    }

                }
            }

        }
    }
    if(order == 2)
    {
        for(int i=0 ; i < size - 1 ; i++)
        {
            for (int j = i + 1; j < size ; j++)
            {
                if (strcmp (list[i].lastName, list[j].lastName) < 0)
                {
                    aux=list[i];
                    list[i]=list[j];
                    list[j]=aux;
                    flagSort = 0;
                }

                if(strcmp (list[i].lastName, list[j].lastName) == 0)
                {
                    if(strcmp(list[i].name, list[j].name) < 0)
                    {
                        aux=list[i];
                        list[i]=list[j];
                        list[j]=aux;
                        flagSort = 0;
                    }

                }
            }
        }
    }


    return flagSort;

}


