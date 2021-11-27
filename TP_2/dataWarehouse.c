#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataWarehouse.h"
#include "employee.h"



int places[10] = {2001,2002,2003,2001,2000,2002,2000,2001,2003,2002};

float salary[10] = {20001,44002,12003,22001,20400,92002,42000,42001,52003,82002};

char names[10][20] = {"Juan","Pedro","Sofia","Miguel",
                        "Valentina","Camila","Andrea",
                        "Luis","Diego","Analia"};

char lastNames[10][20] = {"ganzo","tribu","pana","corona",
                        "lacio","mela","trio",
                        "futra","javo","kacha"};


int peopleHardcode(sEmployee list[], int size, int amount, int* pId){
    int cont = -1;
    if (list != NULL && size > 0 && amount >= 0 && amount <= size && pId != NULL){
        cont = 0;
        for (int i = 0; i < amount;  i++){
            list[i].id = *pId;
            (*pId)++;
            strcpy(list[i].name , names[i]);
            strcpy(list[i].lastName , lastNames[i]);
            list[i].sector = places[i];
            list[i].salary = salary[i];
            list[i].isEmpty = 0;
            cont++;
        }
    }
    return cont;
}

