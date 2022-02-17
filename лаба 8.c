//#include <iostream>                   
#include <stdio.h>                      
#include <string.h>
#include<locale.h>
//include <windows.h>
//using namespace std;

struct sklad  //объявляем шаблон структуры
{
	char punkt[30];    //Пунк прибытия 
	char vremya[5];         //Время вылета 
	float cena;         //Цена
	int nomer;            //Номер 
	int date;           //Дата вылета

};

struct sklad mas[30]; //объвляем глобальный массив структур
struct sklad tmp; //объявляем временую переменную структурного типа
int sch = 0;        //Счетчик полных записей
int er;            //Переключатель

void enter_new();
int menu();
void out();
void del();
void change();
void find();

int main()
{
	setlocale(LC_ALL, "Russian");
	while (1)
	{
		switch (menu())
		{
		case 1:del(); break;
		case 2:enter_new(); break;
		case 3:change(); break;
		case 4:out(); break;
		case 5:find(); break;
		case 6: return 0;
		default: printf("Не верный выбор/n");
		}
	}
}

void enter_new()                         // ф-ция ввода новой структуры
{
	if (sch < 30) //вводим новую запись только, если счетчик полных записей меньше максимального количества записей
	{
		printf ( "Запись номер %d\n", sch + 1); //выводим номер записи
		printf ( "\nВведите пунк прибытия\n");
		rewind(stdin);
		fgets(mas[sch].punkt,30,stdin);
		printf ( "Введите время \n");
		gets(mas[sch].vremya);
		printf ( "Введите цену\n");
		scanf_s ("%f",&mas[sch].cena);
		printf ( "Введите номер\n");
		scanf_s ("%d",&mas[sch].nomer);
		printf ( "Введите дату \n");
		scanf_s("%d", &mas[sch].date);
		sch++; //увеличиваем счетчик полных записей на единицу
	}
	else printf ("Введено максимальное кол-во записей");
}

int menu()
{
	int er;
	printf ("Введите:\n");
	printf ("1-для удаления записи\n");
	printf ("2-для ввода новой записи\n");
	printf ("3-для изменения записи\n");
	printf ("4-для вывода записи(ей)\n");
	printf ("5-для поиска \n");
	printf ("6-для выхода\n");
	scanf_s("%d",&er);
	return er;
}
void out()    //ф-ция вывода записей
{
	int sw;   // переключатель для выбора выводить все записи или одну
	int k;    //номер структуры, кот. надо вывести
	if (sch == 0)//если счетчик количества структур равен 0
		printf ( "\nНет запичей: \n");
	else
	{
		printf ("\nВведите: \n");
		printf ("1-если хотите вывести какую-либо запсь\n");
		printf ("2-если хотите вывести все записи\n");
		scanf_s ("%d",&sw);
		if (sw == 1)
		{
			printf ("Введите номер записи, которую нужно вывести\n");
			scanf_s ("%d",&k);
			printf ("\n");
			printf ("Пункт:%s\n" , mas[k - 1].punkt );
			printf ("Время:%s\n", mas[k - 1].vremya);
			printf ("Цена:%f\n" , mas[k - 1].cena );
			printf ("Номер:%d\n" , mas[k - 1].nomer);
			printf ("Дата:%d\n" , mas[k - 1].date);
			printf ("____________\n" );
		}
		if (sw == 2)
		{
			for (int i = 0; i < sch; i++) //выводим в цикле все записи
			{
				printf ("Пункт:%s" , mas[i].punkt );//выводим на экран значение name i-ой структуры из массива структур mas
				printf ("Время:%s\n",mas[i].vremya);
				printf ("Цена:%f\n" , mas[i].cena) ;
				printf ("Номер:%d\n" , mas[i].nomer);
				printf ("Дата:%d\n" , mas[i].date) ;
				printf("____________\n");
			}
		}
	}
}
void del()        //ф-ция удаления записи
{
	int d;        //номер записи, которую нужно удалить
	printf ("\nВведите номер записи, которую необходимо удалить\n");
	printf ("Если необходимо удалить все записи,нажмите '99'\n");
	scanf_s ("%d",&d);
	if (d != 99)
	{
		for (int i = (d - 1); i < sch; i++)//цикл для удаления заданной записи, начинаем цикл с удаляемой записи
			mas[i] = mas[i + 1]; //замещаем текущую запись следующей за ней
		sch = sch - 1; //уменяьшаем счетчик полных записей на 1
	}
	if (d == 99)
	{
		for (int i = 0; i < 30; i++)//цикл по все записям от первой до 30-ой
			mas[i] = tmp; //замещаем каждую структуру в массиве пустой структурой
		sch = 0; //счетчик структур обнуляем, т.к. все записи удалены
	}
}

void change() //функция для изменения записи
{
	int c;//номер записи, которую нужно изменить
	int per;
	printf ("\nВведите номер записи\n");
	scanf_s ("%d",&c);
	do
	{
		printf ("Введите: \n");
		printf ("1-для изменения пункта\n");
		printf ("2-для изменения времени\n");
		printf ("3-для изменения цены\n");
		printf ("4-для изменения номера\n");
		printf ("5-для изменения даты\n");
		printf ("6-для прекращения\n");
		scanf_s ("%d",&per);
		switch (per)
		{
		case 1:
			printf ("\nВведите новый пункт\n");
			rewind(stdin);
			fgets(mas[c-1].punkt, 30, stdin);
			break;
		case 2:
			printf ("Введите новое время \n");
			rewind(stdin);
			fgets(mas[c - 1].vremya, 5, stdin);
			break;
		case 3:
			printf ("Введите новую цену\n");
			scanf_s ("%f",&mas[c - 1].cena);
			break;
		case 4:
			printf ("Введите новое номер\n");
			scanf_s ("%d",&mas[c - 1].nomer);
			break;
		case 5:
			printf ("Введите новую дату\n");
			scanf_s ("%d",&mas[c - 1].date);
			break;
		case 6: return;
		}
	} while (1);
}

void find()   //ф-ция поиска записей
{
	int sw;     // переключатель
	if (sch == 0)
		printf ("\nНет запичей: \n");
	else
	{
		printf ("\nВведите номер : \n");
		
		scanf_s("%d", &sw);
		for (int i = 0; i < sch; i++) //в цикле просматриваем все структуры
		{

			printf ("Пункт:%s\n" ,mas[i].punkt);
			printf ("Время:%s\n" , mas[i].vremya );
			printf ("Цена:%f\n" , mas[i].cena );
			printf ("Номер:%d\n" , mas[i].nomer );
			printf ("Дата:%d\n", mas[i].date );
			printf ("____________\n" );
		}
	}
}
