#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee){

    int ok = 0;
    char id[80];
    char name[80];
    char hoursWorked[80];
    char salary[80];
    int information;


    sEmployee* pEmployee;

    if(pFile != NULL && pArrayListEmployee != NULL){

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n],\n",id,name,hoursWorked,salary);

        while(!feof(pFile)){

          information = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n],\n",id,name,hoursWorked,salary);

        if(information == 4){

            if(ValidateIntNumber(id) == 1 && ValidateString(name) == 1 && ValidateIntNumber(hoursWorked) == 1 && ValidateIntNumber(salary) == 1){

                pEmployee =  new_EmployeeDates(id,name,hoursWorked,salary);

                if(pEmployee == NULL){
                    puts("No hay mas espacio en memoria");
                break;

                }else{
                    if(ll_add(pArrayListEmployee,pEmployee) != -1){
                    ok = 1;
                    }
                }
             }
            }
        }
    }
    return ok;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}


int parser_setIdFromBinary(char* idChar){


        FILE * pFile = NULL;
		int auxId = -1;
		int flag = 1;

		pFile = fopen(idChar, "rb");

		if(pFile != NULL) {
			fread(&auxId,sizeof(int),1, pFile);
			auxId++;
			flag = 0;
		}
		fclose(pFile);

		if(flag == 0) {
			pFile= fopen(idChar, "wb");
			if(pFile != NULL){
				fwrite(&auxId,sizeof(int),1,pFile);
			}

			fclose(pFile);
		}

		return auxId;

}
