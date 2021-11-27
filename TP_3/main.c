#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#define EMPTY 0
#define BINARY 1
#define TEXT_SAVE 2
#define BINARY_SAVE 3

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
    fclose(file);


    FILE* file2 = NULL;
    file2 =  fopen("data.bin","wb");
    fclose(file2);



  ******** CREAMOS ARCHIVOS BINARIOS **********


    int nextId = 1000;
    FILE* file = NULL;
    file =  fopen("id.bin","wb");
    fwrite(&nextId,sizeof(int),1,file);
    fclose(file);
    FILE* file2 = NULL;
    file2 =  fopen("datos.bin","wb");
    fclose(file2);
*/



    int option = 0;
    int follow = 0;
    int flag = EMPTY;
    int flagIsEmpty = EMPTY;
    LinkedList* employeeList = ll_newLinkedList();

     do{

        flagIsEmpty = ll_isEmpty(employeeList);

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
                flag = BINARY;

                break;
            case 2:
                if(flag == BINARY){
                controller_loadFromBinary("datos.bin",employeeList);
                flag = TEXT_SAVE;
                }else{
                    system("cls");
                    puts("Primero se tiene que cargar los datos de texto (opcion 1)");
                }
                break;
            case 3:
                controller_addEmployee(employeeList);
                break;
            case 4:
                if(flagIsEmpty == 0){
                controller_editEmployee(employeeList);
                } else {
                    puts("no hay datos cargados");
                }
                break;
            case 5:
                if(flagIsEmpty == 0){
                controller_removeEmployee(employeeList);
                } else {
                    puts("no hay datos cargados");
                }
                break;
            case 6:
                controller_ListEmployee(employeeList);
                break;
            case 8:
                if(flag == TEXT_SAVE){
                controller_saveAsText("data.csv",employeeList);
                flag = BINARY_SAVE;
                }
                break;
            case 9:
                controller_saveAsBinary("datos.bin",employeeList);
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
