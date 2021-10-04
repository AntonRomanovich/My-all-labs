#include <stdio.h>
#include <math.h>


int main()
{
    int i = 0;
    double numberOne = 1;
    double numberTwo = 3;
    double pi;                 //задание переменных
    double piOne = 0;
    double piTwo = 0;
    while ( i<251 ) {
        piOne += 1/numberOne;
        numberOne = 1*( fabs( numberOne ) + 4 );    //вычисление положителных слагаемых
        i++;
    }
    while ( i<501 ) {
        piTwo -= 1/numberTwo;
        numberTwo = 1*( fabs( numberTwo ) + 4 );    //вычисление отрицательных слагаемых 
        i++;
    }
    pi = ( piOne + piTwo );         //вычисление числа пи
    printf ("Число пи равно %.15f \n", 4*pi);    
    
    return 0;  //Романович Антон МС-12
}