/*
date:       03.06.2020
task:       sort list with bubblesort    
author:     Christian Lutz
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedListLib.h"

int main(){

    listElement *start;                                             //start pointer
    start = (listElement*)malloc(sizeof(listElement));
    if (start == NULL){                                             //ueberprüfen ob Speicherplatz vorhandem/reserviert wurde
        printf("cant reserve storage.\n");
        return -1;
    }

    start->nextElem = NULL;                                        //start pointer zeigt auf nextElem pointer

    //menu
    int FLAGG = 1;
    while (FLAGG){
        
        printf("1... print list\n");
        printf("2... add element to list\n");
        printf("3... delet element\n");
        printf("4... delet list\n");
        printf("5... save list\n");
        printf("6... load list\n");
        printf("7... sort list\n");
        printf("0... exit\n");
        scanf("%d", &FLAGG);
        system("cls");            //menue wird in der Konsolo gelöscht
    
        switch (FLAGG){
            case 1: printList(start); break;
            case 2: addListElem(start); break;
            case 3: delListElem(start); break;
            case 4: delList(start); break;
            case 5: saveList(start); break;
            case 6: loadList(start); break;
            case 7: sortList(start); break;
            case 0: FLAGG = 0; break;
            default: printf("invalide choice\n"); break;    
        }
    } 
    return 0;
}