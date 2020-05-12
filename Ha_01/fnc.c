#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//f'(x)
double slope(double x1){
    double ys;
    ys = (2 * x1) - 6;
    return ys;
}

//f(x)
double fnc(double x1){
    double yf;
    yf = pow((x1 - 3), 2); 
    return yf;
}

//Newton-Raphson-Verfahren
double nrv(double x1){
    double yf = 0;
    double ys = 0;
    double x2 = 0;

    yf = fnc(x1);
    ys = slope(x1);
    
    x2 = x1 - (yf/ys);
    return x2;
}