#ifndef WORKSTATION_H_INCLUDED
#define WORKSTATION_H_INCLUDED

typedef struct{
    int id;
    char description[20];
}sWorkStation;

#endif // WORKSTATION_H_INCLUDED

int loadPlaceDescription(sWorkStation places[], int size, int placeId, char description[]);
int showPlace(sWorkStation places[], int size);
int validatePlaceId(sWorkStation places[], int id, int size);

