#include <stdio.h>
#include <math.h>


int main()
{
    int i = 0;
    double pi = 1;
    double number = 3;
    while ( i<500 )
    {
        if ( i%2 != 0 ) {
            pi += 1/number;
        }
        else {
            pi -= 1/number;
        }
        number += 2;
        i++;
    }
    printf ("Число пи равно %.15f \n", 4*pi);
 
    return 0;
}