//Datum:    12.05.2020
//Aufgabe:  Newton-Raphson-Verfahren
//Autor:     Christian Lutz

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fnc.h"


int main(){
    int row = 0;                        //Variable für Spalten zählen
    int leny = pow(10,3);               //max länge (10 hoch 3)
    double inres[3][leny];              //Matrix (3 X 10 hoch 3)
    double x1 = -67409290.0237;         //Startwert
    int done = 0;                       //Endbedingung
    
    inres[2][row] = x1;                 //Spalte 3 -> x
    inres[1][row] = fnc(x1);            //Spalte 2 -> f(x)
    inres[0][row] = row;                //Spalte 1 -> n

    printf("\nn:\tf(x):\t\tx:\n\n");
    printf("%d\t", inres[0][row]); // JW: type int vs double
    printf("%lf\t", inres[1][row]);
    printf("%lf\n", inres[2][row]);

    while(done == 0){ 
        row++;

        inres[2][row] = nrv(inres[2][row-1]);
        inres[1][row] = fnc(inres[2][row]);
        inres[0][row] = (double)row;

        printf("%.0lf\t", inres[0][row]);
        printf("%lf\t", inres[1][row]);
        printf("%lf\n", inres[2][row]);

        if (inres[1][row] == 0 || row == (leny)) done = 1;      //wenn f(x) == 0 ist, oder das ende des Array erreicht ist
        
    }

    printf("\n--------------------\nN = (%.2lf/0) \n", inres[2][row]);      //Ausgabe Nullstelle

    return 0;
}

/*
JW-2020-05-12:
--------------
> nice implementation! (9/10) 
> for clean code please cast the value in int before printing it as %d: -1P
*/