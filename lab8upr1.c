#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char fam[100];
    char name[100];
    char otch[100];
    char adres[100];
    char group[100];
    float rating;
};

struct student students[100];
int student_num = 0;

void doAddStident() {
    system("cls");
    fflush(stdin);

    struct student st;
    printf("Enter last name: ");
    scanf("%s", st.fam);
    printf("Enter name : ");
    scanf("%s", st.name);
    printf("Enter second name: ");
    scanf("%s", st.otch);
    printf("Enter address: ");
    gets (st.adres);
    printf("Enter group: ");
    gets (st.group);
    printf("Enter rating: ");
    scanf("%d", &st.rating);
    students[student_num++] = st;
}

void doEditStudent() {
    system("cls");
    fflush(stdin);

    int num;
    printf("Enter student number to edit: ");
    scanf("%d", &num);
    if (num > student_num) {
        return;
    }
    struct student st;
    printf ("Enter last name\n");
    gets (st.fam);
    printf ("Enter name \n");
    gets (st.name);
    printf ("Enter second name \n");  
    gets (st.otch);
    printf ("Enter the address \n");
    gets (st.adres);  
    printf ("Enter the group the student is in \n");
    gets (st.group);
    printf ("Indicate student rating \n");  
    scanf ("%f", &st.rating);
    students[num - 1] = st;
}

void doRemoveStudent() {
    system("cls");
    fflush(stdin);

    int num;
    printf("Enter student number to remove: ");
    scanf("%d", &num);
    if (num > student_num) {
        return;
    }
    int index = num - 1;
    for (int i = index; i < student_num - 1; i++) {
        students[i] = students[i + 1];
    }
    student_num--;
}

void doListStudents() {
    while (1) {
        system("cls");
        fflush(stdin);
        printf("N|   Student   |   Address    |    Group    |     Rating \n");
        for (int i = 0; i < student_num; i++) {
            struct student st = students[i];
            printf("%2d|%s %s %d|%s|%s|%d\n",
                   i + 1, st.fam, st.name, st.otch, st.adres, st.group, st.rating );
        }
        printf("Enter 0 to return:");
        int i;
        scanf("%d", &i);
        if (i == 0) {
            return;
        }
    }
}

void menu() {
    while (1) {
        system("cls");
        fflush(stdin);
        printf("1. Enter info aboute students\n");
        printf("2. Sort students\n");
        printf("3. Search some student\n");
        printf("4. Edit student\n");
        printf("5. Remove student\n");
        printf("6. List students\n");
        printf("7. Exit\n");
        int i;
        printf("Select item: ");
        scanf("%d", &i);
        switch (i) {
            case 1:
                doAddStident();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                doEditStudent();
                break;
            case 5:
                doRemoveStudent();
                break;
            case 6:
                doListStudents();
                break;
            case 7:
                system("cls");
                fflush(stdin);
                return;
        }
    }
}

int main()
{
    menu();
}