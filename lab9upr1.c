#include <stdio.h>

int main() 
{
    char line[255];
    int i;

    FILE *F1 = fopen("F1.txt", "w");
    for (i=0; i<10; i++) {
        fprintf(F1, "%d stroka \n", i+1);
    }
    fclose(F1);

    F1 = fopen("F1.txt", "r");
    for (i=0; i<10; i++) {
        fgets(line, 255, F1);
        if (i%2 == 1) {
            printf("%s \n", line);
        }
    }
    fclose(F1);

    return 0;  //Выполнил Романович Антон МС-12 вариант 5
}