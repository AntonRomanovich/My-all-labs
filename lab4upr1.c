#include <stdio.h>
#include <math.h>

int main() {
int a[10]; 
int i;
int j = 0;
for ( i=0; i<10; i++ ) {
    printf("a[%d] = ", i);
    scanf("%d", &a[i]); 
}
for ( i=0; i<10; i++ ) {
    if ( a[i]==a[j] ) {
        for (j=i+1; j<10; j++) {
            a[j-1]=a[j];
        }
    }
}

for ( i=0; i<10; i++ ) {
    printf("%d ",a[i]);
}

return 0;
}