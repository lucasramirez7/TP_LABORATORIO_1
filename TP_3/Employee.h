#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"

typedef struct
{
    int id;
    char name[128];
    int hoursWorked;
    int salary;
}sEmployee;

sEmployee* employee_new();
sEmployee* new_EmployeeDates(char* idStr,char* nameStr,char* hoursWorkedStr, char* salaryStr);
void employee_delete(sEmployee* this);

int employee_setId(sEmployee* this,int id);
int employee_getId(sEmployee* this,int* id);

int employee_setName(sEmployee* this,char* name);
int employee_getName(sEmployee* this,char* name);

int employee_sethoursWorked(sEmployee* this,int hoursWorked);
int employee_gethoursWorked(sEmployee* this,int* hoursWorked);

int employee_setSalary(sEmployee* this, int salary);
int employee_getSalary(sEmployee* this, int* salary);

//int employee_searchId(sEmployee* this, int* id);

int employee_dates(sEmployee* this, int auxId, char *auxName, int auxHours, int auxSalary);

void employee_headers();
int employee_Print(sEmployee* this, int auxId, char *auxName, int auxHours, int auxSalary);

int EmployeeId(FILE* pFile);

int employee_SortBy_Id(LinkedList* this);
int employee_SortBy_Name(LinkedList* this);
int employee_SortBy_Salary(LinkedList* this);
int employee_SortBy_Hs(LinkedList* this);


#endif // employee_H_INCLUDED

int compareByName(void* firstEmployee,void* SecondEmployee);
int compareById(void* firstEmployee,void* SecondEmployee);
int compareByHs(void* firstEmployee,void* SecondEmployee);
int compareBySalary(void* firstEmployee,void* SecondEmployee);


