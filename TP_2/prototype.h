

#ifndef PROTOTYPE_H_INCLUDED
#define PROTOTYPE_H_INCLUDED



#endif // PROTOTYPE_H_INCLUDED


typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} sEmployee;

int menu();
int setUpPeople(sEmployee list[], int size);
int searchFree(sEmployee list[], int size);
int registerPeople(sEmployee list[], int size, int* pId, char name[], char lastName[], float salary, int sector);
void showPerson(sEmployee person);
int showPeople(sEmployee list[], int size);
int removePerson(sEmployee list[], int size, int id);
int searchPeopleId(sEmployee list[], int size,int id);
int validateInt(int value, int lBot, int lTop);
char validateChar(char value, char a, char b);
char orderChar(char completeName[], char name[], char lastName[]);
int removePerson(sEmployee list[], int size, int id);
int modifyPeople(sEmployee list[], int size, int id);
int hardcodearDates(sEmployee list[], int size, int cant);

//int sortPeople(sEmployee list[], int size, int order);
//int subMenu();


