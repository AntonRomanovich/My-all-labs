#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int ADMIN_ROLE = 0;
const int USER_ROLE = 1;

struct user {
    char login[100];
    char password[100];
    int role; //0 - Admin, 1 - user
};

struct theater {
    int day;
    int month;   //дата
    int year;  
    char nameT[100]; //название театра
    char nameS[100]; //название спектакля
    int ticket;  //количество билетов
    int rate;  //количество проданных билетов
};

struct user users[100];
int users_num = 0;

struct theater theatres[100];
int theatre_num = 0;

int load() {
    FILE *f = fopen("db.dat", "rb");
    if (f) {
        fread(&users_num, sizeof(int), 1, f);
        fread(&theatre_num, sizeof(int), 1, f);  //считывание количества пользователей и театров
        if (users_num > 100 || theatre_num > 100) {
            printf("Invalid file format");
            exit(0);
        }
        if (users_num > 0) {
            fread(users, sizeof(struct user), users_num, f);   //считыванние данных о пользователях
        }
        if (theatre_num > 0) {
            fread(theatres, sizeof(struct theater), theatre_num, f);  //считывание данных о театрах
        }
        fclose(f);
        return 1;
    }
    return 0;
}

void save() {
    FILE *f = fopen("db.dat", "wb");
    fwrite(&users_num, sizeof(int), 1, f);
    fwrite(&theatre_num, sizeof(int), 1, f);
    if (users_num > 0) {
        fwrite(users, sizeof(struct user), users_num, f);
    }
    if (theatre_num > 0) {
        fwrite(theatres, sizeof(struct theater), theatre_num, f);
    }
    fclose(f);
}

int findUser(char login[10]) {
    for (int i = 0; i < users_num; i++) {
        if (strcmp(users[i].login, login) == 0) {
            return i;
        }
    }
    return -1;
}

void doUserList() {
    while (1) {
        system("cls");
        fflush(stdin);
        for (int i = 0; i < users_num; i++) {
            printf("%d. %s / %s (%s)\n", i+1, users[i].login, users[i].password,
                   users[i].role == ADMIN_ROLE ? "admin" : "user");
        }
        printf("Enter 0 to return:");
        int i;
        scanf("%d", &i);
        if (i == 0) {
            return;
        }
    }
}

void doAddUser() {
    system("cls");
    fflush(stdin);//clear input

    struct user u;
    printf("Enter login: ");
    scanf("%s", u.login);
    printf("Enter password: ");
    scanf("%s", u.password);
    printf("Enter role (0 - Admin, 1 - User): ");
    scanf("%d", &u.role);
    if (u.role != 0) {
        u.role = 1;
    }
    users[users_num++] = u;
}

void doRemoveUser() {
    system("cls");
    fflush(stdin);

    char login[100];
    printf("Enter login to remove: ");
    scanf("%s", login);
    int index = findUser(login);
    if (index < 0) {
        return;
    }
    for (int i = index; i < users_num - 1; i++) {
        users[i] = users[i + 1];
    }
    users_num--;
}

void doUsers() {
    while (1) {
        system("cls");
        fflush(stdin);
        printf("0. Return\n");
        printf("1. List users\n");
        printf("2. Add user\n");
        printf("3. Remove user\n");
        int i;
        printf("Select item: ");
        scanf("%d", &i);
        switch (i) {
            case 0:
                return;
            case 1:
                doUserList();
                break;
            case 2:
                doAddUser();
                break;
            case 3:
                doRemoveUser();
                break;
        }
    }
}

void doListTheatres() {
    while (1) {
        system("cls");
        fflush(stdin);
        printf("+--+----------------+----------------+----------------+----------+----------+\n");
        printf("| N|       Theatre  |      Spektakle |     Tickets    |     Rate |     Date |\n");
        printf("+--+----------------+----------------+----------------+----------+----------+\n");
        for (int i = 0; i < theatre_num; i++) {
            struct theater th = theatres[i];
            printf("|%2d|%16s|%16s|%16d|%10d|%2d.%2d.%4d|\n",
                   i + 1, th.nameT, th.nameS, th.ticket, th.rate, th.day, th.month, th.year);
        }
        printf("+---------------------------------------------------------------------------+\n");
        printf("Enter 0 to return:");
        int i;
        scanf("%d", &i);
        if (i == 0) {
            return;
        }
    }
}

void doAddInformationAboutTheatre() {
    system("cls");
    fflush(stdin);

    struct theater th;
    printf("Enter name theatre: ");
    scanf("%s", th.nameT);
    printf("Enter name spectakle: ");
    scanf("%s", th.nameS);
    printf("Enter how much tickets: ");
    scanf("%d", &th.ticket);
    th.rate = 0;
    printf("Enter date performance \n");
    printf("Enter day: ");
    scanf("%d", &th.day);
    printf("Enter month: ");
    scanf("%d", &th.month);
    printf("Enter year: ");
    scanf("%d", &th.year);
    theatres[theatre_num++] = th;
}

void doEditTheatre() {
    system("cls");
    fflush(stdin);

    int num;
    printf("Enter theatre number to edit: ");
    scanf("%d", &num);
    if (num > theatre_num) {
        return;
    }
    struct theater th;

    printf("Enter name theatre: ");
    scanf("%s", th.nameT);
    printf("Enter name spectakle: ");
    scanf("%s", th.nameS);
    printf("Enter how much tickets: ");
    scanf("%d", &th.ticket);
    printf("Enter date performance \n");
    printf("Enter day: ");
    scanf("%d", &th.day);
    printf("Enter month: ");
    scanf("%d", &th.month);
    printf("Enter year: ");
    scanf("%d", &th.year);
    theatres[num - 1] = th;
}

void doRemoveTheatre() {
    system("cls");
    fflush(stdin);

    int num;
    printf("Enter theatre number to remove: ");
    scanf("%d", &num);
    if (num > theatre_num) {
        return;
    }
    int index = num - 1;
    for (int i = index; i < theatre_num - 1; i++) {
        theatres[i] = theatres[i + 1];
    }
    theatre_num--;
}

void doTheatre() {
    while (1) {
        system("cls");
        fflush(stdin);
        printf("0. Return\n");
        printf("1. List theatres\n");
        printf("2. Add theatre\n");
        printf("3. Edit theatre\n");
        printf("4. Remove theatre\n");
        int i;
        printf("Select item: ");
        scanf("%d", &i);
        switch (i) {
            case 0:
                return;
            case 1:
                doListTheatres();
                break;
            case 2:
                doAddInformationAboutTheatre();
                break;
            case 3:
                doEditTheatre();
                break;
            case 4:
                doRemoveTheatre();
                break;
        }
    }
}

void doByTiket() {
    system("cls");
    fflush(stdin);

    int num;
    printf("Enter number theatre to pay: ");
    scanf("%d", &num);
    if (num > theatre_num) {
        return;
    } 
        struct theater th = theatres[num-1];
        printf(" %2d spectacle\n", num, th.nameS);
        printf(" \n");
        printf("Enter 1 to by ticket:\n");
        printf("Enter 0 to return:\n");
        int i, t, r;
        printf("Select : ");
        scanf("%d", &i);
        switch (i) {
            case 0:
                return;
            case 1:
            	printf("Enter numbers tickets: ");
            	scanf("%d", &r);
                th.ticket+=-r;
                th.rate+=r; 
 				theatres[num-1]=th;
                printf("Enter 0 to confirm:");
        		scanf("%d", &t);
        		if (t == 0) {
            		return;
                break;
        }
    }
}



void doAdmin() {
    while (1) {
        system("cls");
        fflush(stdin);
        printf("1. Users\n");
        printf("2. Theatres\n");
        printf("3. Exit\n");
        int i;
        printf("Select item: ");
        scanf("%d", &i);
        switch (i) {
            case 1:
                doUsers();
                break;
            case 2:
                doTheatre();
                break;
            case 3:
                system("cls");
                fflush(stdin);
                return;
        }
    }
}

void doUser() {
    while (1) {
        system("cls");
        fflush(stdin);
        printf("1. Theatres\n");
        printf("2. Choise performances\n");
        printf("3. Watch favorite theartres\n");
        printf("4. Watch favorite spectacles\n");
        printf("5. Exit\n");
        int i;
        printf("Select item: ");
        scanf("%d", &i);
        switch (i) {
            case 1:
                doListTheatres();
                break;
            case 2:
                doByTiket();
                break;
            case 3:
                doFavoriteTheatres();
                break;
            case 4:
                doFavoriteSpectacles();
                break;
            case 5:
                system("cls");
                fflush(stdin);
                return;
        }
    }
}

void doLogin() {
    char login[100];
    char password[100];
    printf("Login: ");
    scanf("%s", login);
    int i = findUser(login);  //проверка логина
    if (i < 0) {
        printf("User not found");
        return;
    }
    struct user u = users[i];
    printf("Password: ");
    scanf("%s", password);
    if (strcmp(u.password, password) != 0) {  //проверка пароля
        printf("Invalid password");
        return;
    }
    if (u.role == ADMIN_ROLE) {  //проверка роли пользователя
        doAdmin();
    } else {
        doUser();
    }
}

void createDefaultAdmin() {
    system("cls");
    fflush(stdin);

    struct user u = {"admin", "pass", ADMIN_ROLE};
    users[users_num++] = u;

    printf("New database with default admin created. Use 'admin' for login and 'pass' for password\n");
}

int main(void) {
    if (load()) {
        doLogin();
    } else {
        createDefaultAdmin();
    }
    save();
}  