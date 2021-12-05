#include <stdio.h>
#include <math.h>
int a[3][4];
void search( int a[3][4] );  //задание прототипа функции


int main()
{
    int i, j;
    
    for (i=0;i<3;i++) {
        for (j=0;j<4;j++) {
            printf("Введите элемент [%d,%d]\n", i+1, j+1);  //ввод элементов матрицы
            scanf("%d",&a[i][j]);
        }
    }
    
    printf ("Изначальная матрица \n");
    for (i=0; i<3; i++) {
        for (j=0; j<4; j++)  //вывод матрицы
        printf("%d ", a[i][j]);
        printf("\n");
    }

    search ( a );  //вызов функции

    return 0;
}

void search( int a[3][4] ) {
    int i, j, f=0;
    for( i=0; i<3; i++ ) {
        for( j=0; j<4; j++ ) {
            if( a[i][j]>0 ) {
                f=1;
                printf("в строке %d есть положительныйй элемент \n", i+1);  //нахождение положительных элементов
                break;
            }
        }
    }
    if ( f == 0 ) {
        printf("ни в одной строке нету положительных элементов");
    }
}