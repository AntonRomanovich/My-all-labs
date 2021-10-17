#include <stdio.h>
#include <math.h>

int main()
{
    int a[3][3];  //задание переменных
    int i, j, f[3], sum=0;
    
    for (i=0;i<3;i++) {
        for (j=0;j<3;j++) {  //ввод элементов матрицы
            printf("Введите элемент [%d,%d]\n", i+1, j+1);
            scanf("%d",&a[i][j]);
        }
    }

    for (i=0;i<3;i++) {
        for (j=0;j<3;j++)  //вывод матрицы
        printf(" %d", a[i][j]);
        printf("\n");
    }
    
    for ( i=0; i<3; i++ ) {
        for ( j=0; j<3; j++ ) {
            if ( a[i][j]>=0 ) {
                f[i] = 1;
            }
            else {
                f[i] = 0;
                break;
            }  //поиск неотрицательных элементов матрицы
        }
        if ( f[i]==1 ) {
            for ( j=0; j<3; j++ ) {
                sum += a[i][j];  //вычисление суммы элементов 
            }
        }
    }
    
    printf ("sum = %i \n", sum);

    return 0;  //выполнил Романович Антон МС-12
}