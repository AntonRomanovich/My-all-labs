#include <stdio.h>
#include <math.h>

int main()
{
    float x, y, z, s;  //задание переменных
    printf ("Введите 3 числа x, y, z \n");  
    scanf ("%f%f%f", &x, &y, &z);  //ввод переменных с клавиатуры
    s = (log(pow(y,-sqrt(fabs(x)))))*(x-y/2)+pow(sin(atan(z)),2);  //вычисление s
    printf ("Ответ: s = %f", s);  //вывод значения s
    return 0;      //выполнил Романович Антон МС-12
}