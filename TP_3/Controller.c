#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int ok = 0;

    pFile = fopen(path,"r");

    if(pFile != NULL){
        ok = parser_EmployeeFromText(pFile,pArrayListEmployee);

        if(ok == 0){
            puts("No se puede cargar la lista");
        }else{
            puts("Lista cargada con exito");
        }
    } else {
        printf("El archivo %s no existe \n", path);
    }

    fclose(pFile);

    return ok;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee) {

	int ok = 0;
	FILE* pFile;

	pFile = fopen(path, "rb");

	system("cls");

	if(pFile != NULL) {

		ok = parser_EmployeeFromBinary(pFile, pArrayListEmployee);

		 if(ok == 0){
            puts("No se puede cargar la lista");
        }else{
            puts("Lista cargada con exito");
        }

	} else {

		printf("ERROR. EL ARCHIVO .BIN NO EXISTE.\n");
	}

	fclose(pFile);

    return ok;

}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee){
    sEmployee* employee;
    char id[80];
    char name[80];
    char hoursWorked[80];
    char salary[80];
    int idInt;
    int ok = 0;

    if(pArrayListEmployee != NULL){
        system("cls");
        puts("********** ALTA DE EMPLEADO **********");

        idInt = parser_setIdFromBinary("id.bin");
        sprintf(id,"%d",idInt); // PEDIMOS EL ID

        puts("Ingrese un nombre"); // PEDIMOS EL NOMBRE
        fflush(stdin);
        gets(name);

        puts("ingrese las horas trabajadas"); //PEDIMOS LAS HORAS TRABAJADAS
        fflush(stdin);
        gets(hoursWorked);

        puts("ingrese salario"); // PEDIMOS SALARIO
        fflush(stdin);
        gets(salary);

        employee = new_EmployeeDates(id,name,hoursWorked,salary);

        if(employee != NULL){

            ll_add(pArrayListEmployee, employee);
            ok = 1;
        }
    }
    return ok;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee){

    sEmployee* employee = NULL;

	int ok = 1;

	char confirmOption;
    int  dateOption;
    int flag = 0;

	int id;
	char name[50];
	int hoursWorked;
	int salary;


	if(pArrayListEmployee != NULL){
	system("cls");
	puts("******** MODIFICAR EMPLEADO******\n");
	controller_ListEmployee(pArrayListEmployee);
	printf("Ingrese ID: ");
    scanf("%d", &id);

    for(int i = 0; i < ll_len(pArrayListEmployee); i++) {

         employee = ll_get(pArrayListEmployee, i);
         if(id == employee -> id){
           flag = 1;
           break;
         }
         }


         if(employee != NULL && flag == 1){
            do{
            system("cls");
            employee_Print(employee,id,name,hoursWorked,salary);
            printf("Confirma Modificacion?(s/n): ");
            fflush(stdin);
            scanf("%c", &confirmOption);
            confirmOption  = tolower(confirmOption);
            }while(!validateChar(confirmOption,'s','n'));

         if(confirmOption != 's'){
                puts("Modificación cancelada");
            }else{

            system("cls");
            puts("********** SELECCIONA EL DATO A MODIFICAR ********** \n \n");
            printf("1- nombre\n");
            printf("2- Horas Trabajadas \n");
            printf("3- Salario\n");
            printf("10- Salir\n \n");
            printf("INGRESE OPCION: ");
            scanf("%d", &dateOption);
            }

          switch(dateOption){

            case 1:
                system("cls");
                puts("Ingrese nuevo nombre:");
                fflush(stdin);
                gets(name);
                employee_setName(employee,name);
                ok = 1;
            break;

            case 2:
                system("cls");
                puts("Ingrese nuevas horas trabajadas:");
                scanf("%d",&hoursWorked);
                employee_setName(employee,name);
                ok = 1;
            break;

            case 3:
                system("cls");
                puts("Ingrese nuevo sueldo:");
                scanf("%d",&salary);
                employee_setName(employee,name);
                ok = 1;
            break;

            case 10:
                system("cls");
                ok = 1;
            break;

            default:
                puts("Opcion invalida");
            break;
            }

        }else{
            puts("No existe el id que marcaste");
            ok = 1;
        }
    }


    return ok;

}


/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee) {

	sEmployee* employee = NULL;
	int ok = 0;
	int id;
	int index;
	int confirmOption;
	int flag = 0;

	system("cls");

	puts("**************Baja empleado**************\n");
	controller_ListEmployee(pArrayListEmployee);
	puts("Ingrese el id que desea eliminar: ");
    scanf("%d", &id);

        for(index = 0; index < ll_len(pArrayListEmployee); index++) {

         employee = ll_get(pArrayListEmployee, index);

          if(id == employee -> id){
           flag = 1;
           break;
         }
         }

			if(flag == 1) {

            do{
            system("cls");
            employee_Print(employee, employee->id, employee->name, employee->hoursWorked, employee->salary);
            printf("seguro quiere eliminar este empleado?(s/n): ");
            fflush(stdin);
            scanf("%c", &confirmOption);
            confirmOption  = tolower(confirmOption);
            }while(!validateChar(confirmOption,'s','n'));

            if(confirmOption != 's'){
              puts("Baja cancelada");
                ok = 1;
            }else{
            ll_remove(pArrayListEmployee,index);
            employee_delete(employee);
            ok = 1;
			}
		} else{

		puts("No existe ese ID");
		ok = 1;
		}


    return ok;

}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee){

    int ok = 0;
    int size = ll_len(pArrayListEmployee);
    sEmployee* employee = NULL;

    system("cls");


    if(pArrayListEmployee != NULL){
       employee_headers();

        for(int i = 0; i < size; i++){
            employee = ll_get(pArrayListEmployee,i);
            employee_Print(employee, employee->id, employee->name, employee->hoursWorked, employee->salary);
            ok = 1;
        }


    }

    return ok;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int controller_saveAsText(char* path , LinkedList* pArrayListEmployee) {

	FILE* pFile = NULL;
	sEmployee* employee = NULL;
	int ok = 0;
	int id;
	char name[50];
	int hours;
	int salary;

	system("cls");

	if(path != NULL && pArrayListEmployee != NULL) {

		pFile = fopen(path, "w");

		if(pFile != NULL) {
			fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");

			for(int i = 0; i<ll_len(pArrayListEmployee); i++) {

				pFile = ll_get(pArrayListEmployee, i);

				if(pFile != NULL) {

					if(employee_getId(pFile, &id) == 0 && employee_getNombre(employee, name) == 0 &&
					employee_gethoursWorked(employee,hours) == 0 && employee_getSalary(employee, &salary) == 0) {

						fprintf(pFile,"%d,%s,%d,%d\n", id,name,hours,salary);
						ok = 1;
                        puts("Se ha guardado con exito");
					}
				}
			}

			fclose(pFile);
		}
	}

	return ok;
}
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee){


	FILE* pFile = NULL;
	sEmployee* employee = NULL;
	int ok = 0;

	system("cls");

	pFile = fopen(path, "wb");

	if(pFile != NULL) {

		for(int i = 0; i<ll_len(pArrayListEmployee); i++) {

			employee = ll_get(pArrayListEmployee, i);

			if(employee != NULL){

					fwrite(employee,sizeof(sEmployee),1,pFile);
					ok = 1;

			}
		}
	}

    return ok;





}

