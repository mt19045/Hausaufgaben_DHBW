#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedListLib.h"

void addlistElem(listElement *start){

    listElement *new;
    new = (listElement*)malloc(sizeof(listElement));
    if(new == NULL){
        printf("cant reserve storage.\n");
        return;                                                         //void gibt nichts zurück, d.h. nur return
    }

    //manage pointers
    listElement *currElem = start;
    while(currElem->nextElem != NULL) currElem = currElem->nextElem;
    currElem->nextElem = new;
    new->nextElem = NULL;

    //enter data
    printf("Enter lastName: \n");
    scanf("%s", new->lastName);                                         /*scanf erwartet immer eine Adresse; da strings im prinzip ein pointer 
                                                                        auf die erste Adresse des zusammenhängenden Speicherplatzese Zeigt, 
                                                                        kann am direkt den pinter rein*/
    printf("Enter firstName: \n");
    scanf("%s", new->firstName);
    printf("Enter age: \n");
    scanf("%d",&(new->age));                                            /*da int age eine einzige Zelle und kein pointer ist ist muss da auf 
                                                                        die Adresse mit "&" verwiesen werden*/
    
}

void printList(listElement *start){

    if (start->nextElem == NULL) printf("\nlist is empty.\n");
    else{
        int i = 1;
        listElement *currElem = start;
        printf("\ncurrent list:\n\n");
        do{
            currElem = currElem->nextElem;
            printf("%d)", i); i++;
            printf("\tlast name: %s\n", currElem->lastName);
            printf("\tfirst name: %s\n", currElem->firstName);
            printf("\tage: %d\n", currElem->age);
        }while(currElem->nextElem != NULL);
        printf("\n");
    }

}

void delListElem(listElement *start){

    printf("\n>> delListElem fcn is tbd.\n\n");

}

void delList(listElement *start){

    printf("\n>> getLenOfList fcn is tbd.\n\n");

}

int getLenOfList(listElement *start){

    int counter = 0;
    listElement * currElem = start;
    while (currElem->nextElem != NULL) {// get last elem in list
        currElem = currElem->nextElem; counter++;
        }
    return counter;
}

void saveList(listElement *start){

	char filename[50];
	printf("\n >> saving data...\n\n");
	printf("filename without extension: ");
	scanf("%s",filename);
	strcat(filename, ".txt");                               // adding .txt to file name
	
	FILE * fPtr;                                            //file poniter
    fPtr = fopen(filename, "w");                            //open and write 

    if (fPtr != NULL){

        fprintf(fPtr, "%d\n\n",getLenOfList(start));        //len of list
        listElement *currElm = start;
        do{
            currElm = currElm->nextElem;
            
            //adding data to txt doc
            fprintf(fPtr, "%s\n", currElm->firstName);      
            fprintf(fPtr, "%s\n", currElm->lastName);
            fprintf(fPtr, "%d\n\n", currElm->age);
        }while (currElm->nextElem != NULL);

    }
    else {
        printf("coulden't save list!");
        return;
    }    
    
    fclose(fPtr);                                           //close file pointer
    printf("\nfile has been successefully saved!\n\n");
    
	return;
}

void loadList(listElement *start){
	
	char filename[50];
	printf("\nloading data...\n\n");
	printf("availible data: \n----------------\n");
	system("dir /b *.txt");                                 //print available *.txt files in current location
	printf("\nfilname without extension: ");
	scanf("%s",filename);
	strcat(filename, ".txt");                               // adding .txt to file name
	
	FILE * fPtr;
	fPtr = fopen(filename, "r");                            //read

    if (fPtr != NULL){
        int len;
        fscanf(fPtr, "%d", &len);
        
        listElement *currElem = start;                      //creating current Pointer, pointing to element of start

        for (int i = 0; i < len; i++){                      //for every list element new loop
            listElement *new;
            new = (listElement*)malloc(sizeof(listElement));
            if(new == NULL){
                printf("cant reserve storage.\n");
                return;                                                      
            }

            while(currElem->nextElem != NULL) currElem = currElem->nextElem;
            currElem->nextElem = new;
            new->nextElem = NULL;

            //scanning data, saving in new element in list
            fscanf(fPtr,"%s", new->lastName);
            fscanf(fPtr,"%s", new->firstName);
            fscanf(fPtr,"%d", &(new->age));

            
        }
    }
    else {
        printf("\ncound't open file!\n\n");
        return;
    }

	fclose(fPtr);
	printf("loading data will be append to current list...\n");
	printList(start);
}

void exitFcn(listElement *start){

    printf("\n>> exitFcn fcn is tbd.\n\n");

}

void sortList(listElement *start){
	
	printf("\n>>sortList fcn is tbd.\n\n");
    
}

void stringToLower(char *string) {
	
    printf("\n>>stringToLower fcn is tbd.\n\n");

}