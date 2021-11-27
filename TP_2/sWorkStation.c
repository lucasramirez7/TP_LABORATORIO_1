#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "workStation.h"


int loadPlaceDescription(sWorkStation places[], int size, int placeId, char description[]){

    int ok = 0;
    int flag = 1;
    if (places != NULL && size > 0 && description != NULL){
        ok = 1;
        for (int i = 0; i < size; i++){
            if (places[i].id == placeId){
                strcpy(description, places[i].description);
                flag = 0;
                break;
            }
        }
        if (flag){
            ok = -1;
        }
    }
    return ok;
}

int showPlace(sWorkStation places[], int size){

     int ok = 0;
    if (places != NULL && size > 0){

        puts("************* PUESTOS DE TRABAJO ************* \n");
        puts("      ID          DESCRIPCION ");
        puts("-------------------------------");

    for (int i=0; i<size; i++){
        printf("     %d          %-10s \n",places[i].id,places[i].description);
            }
        puts("\n \n");
        ok = 1;
        }

    return ok;
}
int validatePlaceId(sWorkStation places[], int id, int size){

    int ok = 0;

    if (places != NULL && size > 0 ){
        ok = 1;
        for (int i = 0; i < size; i++){
            if(places[i].id == id){
                 ok = 1;
                break;
            }
            }
    }
    return ok;
}
