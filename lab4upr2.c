#include <stdio.h>
#include <math.h>

int main() {
    int r;
    printf ("how mach numbers should be on massive? \n");   //задание размера массива пользователем
    scanf ("%i", &r);

    int a[r]; 
    int i, j;

    for ( i=0; i<r; i++ ) {
        printf("a[%d] = ", i);  //заполнение массива
        scanf("%d", &a[i]);
        printf (" "); 
    }

    for ( i=0; i<r; i++ ) {
        for ( j=1; j<r; j++ ) {    
            if ( i!=j ) {
                if ( a[i]==a[j] ) {     //поиск одинаковых чисел
                    for ( j = i + 1; j<r; j++ ) {     //удаление поторяющихся чисел из массива
                        a[j-1] = a[j];
                    }
                    r--;
                }
            }
        }
    }

    for ( i=0; i<r; i++ ) {
        printf("%d ",a[i]);  //вывод чисел
    }

    return 0;  //выполнил Романович Антон МС-12
} 