/*
date:       23.05.2020
task:       Save and load linked list      
authors:    Lukas Mehringer and Christian Lutz
*/

#ifndef LINKEDLISTLIB_H_
#define LINKEDLISTLIB_H_

struct listElem{
    char lastName[50];
    char firstName[50];
    int age;
    struct listElem *nextElem;

};

typedef struct listElem listElement;

void addlistElem(listElement *);
void printList(listElement *);
void delListElem(listElement *);
void delList(listElement *);
int getLenOfList(listElement *);
void saveList(listElement *);
void loadList(listElement *);
void exitFcn(listElement *);
void sortList(listElement *);
void stringToLower(char *); 

#endif