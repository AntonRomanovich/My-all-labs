#include <stdio.h>
#include <math.h>

int main()
{
int x1, x2, x3, y1, y2, y3;
printf ("Ведите координаты вершин треугольника \n");
printf ("1 koordinata \n");
scanf ("%i%i", &x1,&y1);
printf ("2 koordinata \n");
scanf ("%i%i", &x2,&y2);
printf ("3 koordinata \n");
scanf ("%i%i", &x3,&y3);
float side1, side2, side3, side1x, side1y, side2x, side2y, side3x, side3y;

side1x = x1-x3; // вычисление 1 стороны
side1y = y1-y3;
side1 = pow(side1x,2) + pow(side1y,2);

side2x = x1-x2; //вычисление 2 стороны
side2y = y1-y2;
side2 = pow(side2x,2) + pow(side2y,2);

side3x = x2-x3; //вычисление 3 стороны
side3y = y2-y3;
side3 = pow(side3x,2) + pow(side3y,2);

if (side1>side2 && side1>side3) {
    side2+side3>side1 ? printf("треугольник остроугольный"):
    side2+side3<side1 ? printf("треугольник тупоугольный"):
    printf("треугольник прямоугольный");
}
if (side2>side1 && side2>side3) {
    side1+side3>side2 ? printf("треугольник остроугольный"):  //определение вида треугольника
    side1+side3<side2 ? printf("треугольник тупоугольный"):
    printf("треугольник прямоугольный");
}
if (side3>side2 && side3>side1) {
    side2+side1>side3 ? printf("треугольник остроугольный"):
    side2+side1<side3 ? printf("треугольник тупоугольный"):
    printf("треугольник прямоугольный");
}
  //выполнил Романович Антон, группа МС 12
return 0;
}
