#include <stdio.h>
#include <string.h>
void search(char s[100]);

int main() {
    char s[100];
    gets(s);
    search (s);
return 0;
}

void search (char s[100]) {
    int i, id, max, count, len;
    len = strlen(s);
    max = 0;
    id = 0;
    count = 0;
    for (i=0; i< len; i++)
        if (s[i] != ' ') count += 1;
        else {
            if (count > max) {
                max = count;
                id = i - count;
            }
            count = 0;
        }
 
    if (count > max) {
        max = count;
        id = i - count;
    }
    max += id;
    for (i=id; i< max; i++)
        putchar(s[i]);
    printf("\n");
}