//#include <iostream>                   
#include <stdio.h>                      
#include <string.h>
#include<locale.h>
//include <windows.h>
//using namespace std;

struct sklad  //��������� ������ ���������
{
	char punkt[30];    //���� �������� 
	char vremya[5];         //����� ������ 
	float cena;         //����
	int nomer;            //����� 
	int date;           //���� ������

};

struct sklad mas[30]; //�������� ���������� ������ ��������
struct sklad tmp; //��������� �������� ���������� ������������ ����
int sch = 0;        //������� ������ �������
int er;            //�������������

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
		default: printf("�� ������ �����/n");
		}
	}
}

void enter_new()                         // �-��� ����� ����� ���������
{
	if (sch < 30) //������ ����� ������ ������, ���� ������� ������ ������� ������ ������������� ���������� �������
	{
		printf ( "������ ����� %d\n", sch + 1); //������� ����� ������
		printf ( "\n������� ���� ��������\n");
		rewind(stdin);
		fgets(mas[sch].punkt,30,stdin);
		printf ( "������� ����� \n");
		gets(mas[sch].vremya);
		printf ( "������� ����\n");
		scanf_s ("%f",&mas[sch].cena);
		printf ( "������� �����\n");
		scanf_s ("%d",&mas[sch].nomer);
		printf ( "������� ���� \n");
		scanf_s("%d", &mas[sch].date);
		sch++; //����������� ������� ������ ������� �� �������
	}
	else printf ("������� ������������ ���-�� �������");
}

int menu()
{
	int er;
	printf ("�������:\n");
	printf ("1-��� �������� ������\n");
	printf ("2-��� ����� ����� ������\n");
	printf ("3-��� ��������� ������\n");
	printf ("4-��� ������ ������(��)\n");
	printf ("5-��� ������ \n");
	printf ("6-��� ������\n");
	scanf_s("%d",&er);
	return er;
}
void out()    //�-��� ������ �������
{
	int sw;   // ������������� ��� ������ �������� ��� ������ ��� ����
	int k;    //����� ���������, ���. ���� �������
	if (sch == 0)//���� ������� ���������� �������� ����� 0
		printf ( "\n��� �������: \n");
	else
	{
		printf ("\n�������: \n");
		printf ("1-���� ������ ������� �����-���� �����\n");
		printf ("2-���� ������ ������� ��� ������\n");
		scanf_s ("%d",&sw);
		if (sw == 1)
		{
			printf ("������� ����� ������, ������� ����� �������\n");
			scanf_s ("%d",&k);
			printf ("\n");
			printf ("�����:%s\n" , mas[k - 1].punkt );
			printf ("�����:%s\n", mas[k - 1].vremya);
			printf ("����:%f\n" , mas[k - 1].cena );
			printf ("�����:%d\n" , mas[k - 1].nomer);
			printf ("����:%d\n" , mas[k - 1].date);
			printf ("____________\n" );
		}
		if (sw == 2)
		{
			for (int i = 0; i < sch; i++) //������� � ����� ��� ������
			{
				printf ("�����:%s" , mas[i].punkt );//������� �� ����� �������� name i-�� ��������� �� ������� �������� mas
				printf ("�����:%s\n",mas[i].vremya);
				printf ("����:%f\n" , mas[i].cena) ;
				printf ("�����:%d\n" , mas[i].nomer);
				printf ("����:%d\n" , mas[i].date) ;
				printf("____________\n");
			}
		}
	}
}
void del()        //�-��� �������� ������
{
	int d;        //����� ������, ������� ����� �������
	printf ("\n������� ����� ������, ������� ���������� �������\n");
	printf ("���� ���������� ������� ��� ������,������� '99'\n");
	scanf_s ("%d",&d);
	if (d != 99)
	{
		for (int i = (d - 1); i < sch; i++)//���� ��� �������� �������� ������, �������� ���� � ��������� ������
			mas[i] = mas[i + 1]; //�������� ������� ������ ��������� �� ���
		sch = sch - 1; //���������� ������� ������ ������� �� 1
	}
	if (d == 99)
	{
		for (int i = 0; i < 30; i++)//���� �� ��� ������� �� ������ �� 30-��
			mas[i] = tmp; //�������� ������ ��������� � ������� ������ ����������
		sch = 0; //������� �������� ��������, �.�. ��� ������ �������
	}
}

void change() //������� ��� ��������� ������
{
	int c;//����� ������, ������� ����� ��������
	int per;
	printf ("\n������� ����� ������\n");
	scanf_s ("%d",&c);
	do
	{
		printf ("�������: \n");
		printf ("1-��� ��������� ������\n");
		printf ("2-��� ��������� �������\n");
		printf ("3-��� ��������� ����\n");
		printf ("4-��� ��������� ������\n");
		printf ("5-��� ��������� ����\n");
		printf ("6-��� �����������\n");
		scanf_s ("%d",&per);
		switch (per)
		{
		case 1:
			printf ("\n������� ����� �����\n");
			rewind(stdin);
			fgets(mas[c-1].punkt, 30, stdin);
			break;
		case 2:
			printf ("������� ����� ����� \n");
			rewind(stdin);
			fgets(mas[c - 1].vremya, 5, stdin);
			break;
		case 3:
			printf ("������� ����� ����\n");
			scanf_s ("%f",&mas[c - 1].cena);
			break;
		case 4:
			printf ("������� ����� �����\n");
			scanf_s ("%d",&mas[c - 1].nomer);
			break;
		case 5:
			printf ("������� ����� ����\n");
			scanf_s ("%d",&mas[c - 1].date);
			break;
		case 6: return;
		}
	} while (1);
}

void find()   //�-��� ������ �������
{
	int sw;     // �������������
	if (sch == 0)
		printf ("\n��� �������: \n");
	else
	{
		printf ("\n������� ����� : \n");
		
		scanf_s("%d", &sw);
		for (int i = 0; i < sch; i++) //� ����� ������������� ��� ���������
		{

			printf ("�����:%s\n" ,mas[i].punkt);
			printf ("�����:%s\n" , mas[i].vremya );
			printf ("����:%f\n" , mas[i].cena );
			printf ("�����:%d\n" , mas[i].nomer );
			printf ("����:%d\n", mas[i].date );
			printf ("____________\n" );
		}
	}
}
