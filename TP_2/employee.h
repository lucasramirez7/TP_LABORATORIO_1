#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED
#include "workStation.h"


typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} sEmployee;

int setUpPeople(sEmployee list[], int size);
int searchFree(sEmployee list[], int size);
int registerPeople(sEmployee list[], int size,int* pId, sWorkStation places[], int sizePlaces);
void showPerson(sEmployee person,sWorkStation places[], int placeSize);
int showPeople(sEmployee list[], int size, sWorkStation places[], int placeSize);
int removePerson(sEmployee list[], int size, sWorkStation places[], int sizePlaces);
int searchPeopleId(sEmployee list[], int size,int id);
int modifyPeople(sEmployee list[], int size,int id, sWorkStation places[], int sizePlaces);
int sortEmployeesByLastName(sEmployee employeeList[], int size, int order);

#endif // EMPLOYEE_H_INCLUDED
