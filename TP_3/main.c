#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
int main()
{
    /*int nextId = 1000;
    FILE* file = NULL;
    file =  fopen("id.bin","wb");
    fwrite(&nextId,sizeof(int),1,file);
    fclose(file);*/


    /*FILE* file2 = NULL;
    file2 =  fopen("data.bin","wb");
    fclose(file2);
*/
    int option = 0;
    int follow = 0;
    LinkedList* employeeList = ll_newLinkedList();

    do{
        system("cls");
        puts("*****MENU DE OPCIONES***** \n");
        puts("1- Cargar los datos de los empleados desde el archivo data.csv (modo texto)."); //OK CARGAR LOS DATOS EN RAM A LA LINKEDLIST
        puts("2- Cargar los datos de los empleados desde el archivo data.csv (modo binario)."); //OK
        puts("3- Alta de empleado");//OK
        puts("4- Modificar datos de empleado"); //OK
        puts("5- Baja de empleado");
        puts("6- Listar empleados"); // OK
        puts("7- Ordenar empleados");
        puts("8- Guardar los datos de los empleados en el archivo data.csv (modo texto).");
        puts("9- Guardar los datos de los empleados en el archivo data.csv (modo binario).");
        puts("10- Salir \n");
        printf("Ingrese opcion: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",employeeList);
                break;
            case 2:
                controller_loadFromBinary("data.bin",employeeList);
                break;
            case 3:
                controller_addEmployee(employeeList);
                break;
            case 4:
                controller_editEmployee(employeeList);
                break;
            case 5:
                controller_removeEmployee(employeeList);
                break;
            case 6:
                controller_ListEmployee(employeeList);
                break;
            case 10:
                puts("El programa se ha cerrado correctamente");
                follow = 1;
                break;
            default:
                puts("Opcion incorrecta");
                break;
        }
        system("pause");
    }while(follow == 0);

    return 0;
}
