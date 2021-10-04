#include <stdio.h>
#include <string.h>

int main()
{
    char winter[] = "зима";
    char summer[] = "лето";    //задание времён года
    char autumn[] = "осень";
    char spring[] = "весна";
    char input[10];
    printf("Введите время года (с маленькой буквы) \n");
    scanf ("%s", input);
    strcmp(winter, input) == 0 ? printf ("Зимние месяцы: декабрь, январь и февраль"):
    strcmp(summer, input) == 0 ? printf ("Летние месяцы: июнь, июль и август"):        //вывод месяцов соот. времён года
    strcmp(spring, input) == 0 ? printf ("Весенние месяцы: март, апрель и май"):
    strcmp(autumn, input) == 0 ? printf ("Осенние месяцы: сентябрь, октябрь и ноябрь"):
    printf("Введите корректные данные!");
    //выполнил Романович Антон, группа МС 12
    return 0;
}
