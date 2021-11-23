#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "mi libreria.h"


int ValidateIntNumber(char number[]) {

    int i = 0;
    int j;
    int ok = 1;

    j = strlen(number);

    while(i < j && ok == 0) {

        if(isdigit(number[i]) != 0) {

        	i++;

        }

        else {

            ok = 0;
        }
    }

    return ok;
}

int ValidateString(char string[]) {

    int i = 0;
    int ok = 1;
    int j;

    j = strlen(string);
    while(i < j && ok == 0) {

        if(isalpha(string[i]) != 0 || string[i] == ' '||string[i] == '-') {//agregue la validacion de '-' porque el archvio tiene nombres con guiones

        	i++;
        }

        else {

            ok = 0;
        }
    }

    return ok;
}


char validateChar(char value, char a, char b){
      return (value == a || value == b);
}
int validateInt(int value, int lBot, int lTop){
    return (value >=lBot && value <= lTop);
}
