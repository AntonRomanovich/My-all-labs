#include <stdio.h>
#include <math.h>

int main() {
    int r;
    printf ("how mach numbers should be on massive? \n");   //задание размера массива пользователем
    scanf ("%i", &r);

    int a[r]; 
    int i, j, f;

    for ( i=0; i<r; i++ ) {
        printf("a[%d] = ", i);  //заполнение массива
        scanf("%d", &a[i]);
        printf (" "); 
    }

    for ( i=0; i<r; i++ ) {
        f=1;
        for ( j=0; j<r; j++ ) {
            if ( a[i]==a[j] && i!= j ) {   //поиск повторяющихся элементов массива
                f = 0;
                break;
            }
        }
        if ( f==1 ) {
            printf ("%d ", a[i]);  //вывод неповторяющихся
        }
    }

    return 0;  //выполнил Романович Антон МС-12
}