#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    printf("write some number \n");
    float n, population;        //задание переменних
    int years;
    scanf ("%f", &n);       //ввод численности города 
    population = n*3;       //вычисление утроеннного населения 
    for ( years = 0; n<population; years++) 
    {
        n = n + 1/n;            //вычисление времения, когда население утроится
    }
    printf ("Население города утроится через %i лет ", years);

    return 0;  //Романович Антон МС-12
}
