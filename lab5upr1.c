#include <stdio.h>
#include <math.h>

int main()
{
    int a[3][3];  //задание переменных
    int i, j, f[3], sum=0, sum1[2]={0, 0}, fsize=3, k;
    
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
    
    printf ("сумма элементов, на строчках без отрицательных элементов и 0 = %i \n", sum);
    
    for ( k=1; k<2; k++ ) {
        for ( i=0; i<fsize; i++ ) {  //вычисление суммы на диагоналях выше главной
            if ( i+k >= 3 ) {
                break;
            }
            sum1[0] += a[i][i+k];
        }	
    }
    
    for ( k=1; k<2; k++ ){
        for ( i=0; i<fsize; i++ ){  //вычисление суммы на диагоналях ниже главной
            if ( i+k >= 3 ) {
                break;
            }
            sum1[1] += a[i+k][i];
        }	
    }

    int min = sum1[0];
    for ( i=0; i<2; i++ ) {  //сравнение сумм
        if (sum1[i]<min) {
            min = sum1[i];
        }
    }
    
    printf ("Минимальная сумма элементов одной из побочных диагоналей, параллельной главной диагонали = %i", min);

    return 0;  //выполнил Романович Антон МС-12
}