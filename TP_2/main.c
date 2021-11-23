#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototype.h"
#define SIZE 1000
#define SIZE_CHAR 51





int main()
{
    int follow = 's';
    int nextId = 1000;
    char name[SIZE_CHAR];
    char lastName[SIZE_CHAR];
    int salary;
    int sector;
    int id;
    int modifyThisId;

    sEmployee list[SIZE];


    if (!setUpPeople (list,SIZE))
    {
        printf("¡Problemas al inicializar! \n");
    }
    do
    {
        switch(menu())
        {

        case 1:
            if(!registerPeople(list,SIZE,&nextId,name,lastName,salary,sector)){
                printf("No se puede realizar el alta \n");
            }
            else
            {
                printf("Se registro la persona con exito!\n");
            }
            break;

        case 2:
            if(!removePerson(list,SIZE,id)){
                puts("No se puede dar de baja");

            }

            break;

        case 3:
            if(!modifyPeople(list,SIZE,id)){
                puts("No se puede modificar");
            }


            break;

        case 4:
            showPeople(list, SIZE);
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


