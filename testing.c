#include <stdio.h>
#include <math.h>

int main()
{
    int i, j;
    int matrica [5][5];

    for (i=0;i<5;i++) {
        for (j=0;j<5;j++) {
            printf("Введите элемент [%d,%d]\n", i+1, j+1);  //ввод элементов матрицы
            scanf("%d",&matrica[i][j]);
        }
    }

    for (i=0;i<5;i++) {
        for (j=0;j<5;j++)
        printf(" %d", matrica[i][j]);  //вывод матрицы
        printf("\n");
    }

    printf ("\n");

    for (i=0;i<5;i++) {
        for (j=0;j<5;j++) {
            if (j >= i && j <= 5-i && j != 5-i) {
                printf ("%d ", matrica[i][j]);
            }
            else {
                printf ("  ");
            }
        }
        printf ("\n");
    }

    return 0;
}