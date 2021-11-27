#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1000
#define PLACE_SIZE 5
#define SIZE_CHAR 51
#include "employee.h"
#include "mi libreria.h"
//#include "dataWarehouse.h"

int main()
{
    int follow = 's';
    int nextId = 1000;
    int optionOrder;
    int id = 0;

    sEmployee list[SIZE];
    sWorkStation places[PLACE_SIZE] = {{2000,"Secretario"},{2001,"Administrador"},{2002,"Recursos humanos"},{2003,"Auxiliar"},{2004,"operador"}};


    if (!setUpPeople (list,SIZE))
    {
        printf("¡Problemas al inicializar! \n");
    }


    peopleHardcode(list,SIZE,10,&nextId);

    do
    {
        switch(menu()){

        case 1:
            if(!registerPeople(list,SIZE,&nextId,places,PLACE_SIZE)){
                printf("No se puede realizar el alta \n");
            }
            else
            {
                printf("Se registro la persona con exito!\n");
            }
            break;

        case 2:
            if(!removePerson(list,SIZE,places,PLACE_SIZE)){
                puts("No se puede dar de baja");

            }

            break;

        case 3:
            if(!modifyPeople(list,SIZE,id,places,PLACE_SIZE)){
                puts("No se puede modificar");
            }


            break;

        case 4:
            showPeople(list, SIZE,places,PLACE_SIZE);
            break;

        case 5:
            system("cls");
            puts("***********HASTA LUEGO!*********** \n");
            follow = 'n';
            break;

        default:
            fflush(stdin);
            printf("Opcion invalida\n");
        }
        system("pause");


    }
    while(follow == 's');


    return 0;
}


