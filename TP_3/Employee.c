#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"


sEmployee* new_Employee(){
   return (sEmployee*) malloc(sizeof(sEmployee));
}
void employee_delete(sEmployee* this){

    if(this != NULL) {
		free(this);
		this = NULL;
}
}

int employee_setId(sEmployee* this, int id){

int ok = 0;

	if(this !=NULL && id > 0) {
		this-> id = id;
		ok = 1;
	}
    return ok;
}

int employee_getId(sEmployee* this, int* id){

    int ok = 0;

	if(this != NULL && id != NULL) {

		*id= this ->id;
		ok = 1;

	}
	return ok;
}

int employee_setName(sEmployee* this,char* name){

    int ok = 0;

	if(this != NULL) {
		strcpy(this->name, name);

		ok = 1;
	}
    return ok;
}


int employee_getName(sEmployee* this,char* name){

    int ok = 0;

	if(this != NULL && name != NULL) {

		strcpy(name, this->name);

		ok = 1;
	}
	 return ok;
}

int employee_sethoursWorked(sEmployee* this,int hoursWorked){

    int ok = 0;

	if(this != NULL && hoursWorked >= 0) {

		this->hoursWorked = hoursWorked;
		ok = 1;

	}

    return ok;

}
int employee_gethoursWorked(sEmployee* this,int* hoursWorked){

    int ok = 0;

    if (this != NULL && hoursWorked != NULL){

        *hoursWorked = this -> hoursWorked;
        ok = 1;
    }

    return ok;
}

int employee_setSalary(sEmployee* this,int salary){

    int ok = 0;

	if(this !=NULL && salary >= 0) {

		this -> salary = salary;
		ok = 1;
	}

	return ok;


}
int employee_getSalary(sEmployee* this,int* salary){

    int ok = 0;

	if(this != NULL && salary != NULL) {

	*salary = this -> salary;
	ok = 1;

	}

	return ok;


}

sEmployee* new_EmployeeDates(char* idStr,char* nameStr,char* hoursWorkedStr, char* salaryStr){

    sEmployee* newEmployee = NULL;
    newEmployee = new_Employee();

    if(newEmployee == NULL){
    employee_delete(newEmployee);
    newEmployee = NULL;
    }
    else{
        employee_setId(newEmployee, atoi(idStr));
        employee_setName(newEmployee, nameStr);
        employee_sethoursWorked(newEmployee,atoi(hoursWorkedStr));
        employee_setSalary(newEmployee, atoi(salaryStr));
    }

    return newEmployee;
}
void employee_headers(){

    printf("   ID                     NOMBRE      HORAS   SUELDO\n");

}

int employee_Print(sEmployee* this, int auxId, char *auxName, int auxHours, int auxSalary){

    int ok = 0;

	if(this != NULL) {

		printf("%5d %30s %10d %8d\n", auxId, auxName, auxHours, auxSalary);
		ok = 1;

	}
	return ok;
}


