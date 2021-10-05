#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    int x, itog;        // задаём необходимые переменные 
    printf ("Введите число х = \n");
    scanf ("%i", &x);   // ввод переменой х через клавиатуру 
    itog=2*pow(x,8);    // вычисление значения выражения 
    printf ("Результат 2х^8 = %d", itog);   // вывод этого значения
    return 0;    //выполнил Романович Антон МС-12
}