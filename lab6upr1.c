#include <stdio.h>
#include <math.h>
#include <conio.h>

int main() {

    int i, kol=0, n, pol=0;
    float a[30], sum=0, max;
    
    do{
        printf("Vvedite kol-vo elementov massiva (<30)\n "); //задание размерности массива
        scanf("%d",&n);
    } while (n>=30);

    for( i=0; i<n; i++ ) {
        printf ("Vvedite element massiva a[%d] \n", i+1); //ввод элементов массива
        scanf ("%f", a+i);
    }

    for( i=0; i<n; i++ ) {
        if( max < fabs(*(a+i)) ) {  //нахождение максимального по модулю
            max = fabs(*(a+i));
        }
    } 
    printf ("max modul = %f \n", max);

    for( i=0; i<n; i++ ) {
        if( *(a+i)>0 ) {
            pol += 1;       //нахождение 2-х положительных
        }
    }
    if( pol>=2 ) {
        for( i=0; i<n; i++ ) {
            if( a+i>0 ) {
                if( a[i+1]<=0 ) {
                    sum += a[i+1];  //вычесление суммы если есть хотя бы 2 положительных числа
                } else {
                    printf("sum = %f \n", sum);
                    break;
                }
            }
        }
    } else {
        printf("polozhitel'nykh chisel men'she dvukh");  //если нету 2-х положительных
    }

    return 0;
}                       //Выполнил Романович Антон МС-12 вариант 5