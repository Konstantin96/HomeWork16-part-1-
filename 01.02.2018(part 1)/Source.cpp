#include <locale.h>
#include <math.h>
#include <vector>
#include <time.h>
#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

bool prost(int x);
void lsearch(int* arr, int len, int ch);
void sort(int* arr, int Len);
void bsearch(int* arr, int len, int ch);

using namespace std;
int nz;

void main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(0));

	int i, j;
	while (true)
	{
		cout << "Vvedite nomer zadaniya: "; cin >> nz;

		if (nz == 0)
		{
			break;
			system("exit");
		}
		else if (nz == 1)
		{
			/*Написать функцию, которая проверяет, является ли переданное ей число простым? Число называется простым, если оно делится без остатка только на себя и на единицу.*/
			int arr[10];
			arr[0] = 1;
			for (i = 1; i < 10; i++)
			{
				arr[i] = arr[i - 1] + 1;
			}		
			cout << " Vvedite chislo ot 1 do 10: \n";
			for (i = 0; i < 10; i++)
			{
				if (prost(arr[i]))printf(" %d\n", arr[i]);
			}
			cout << endl;
		}
		else if (nz == 2)
		{
			/*Написать функцию, реализующую алгоритм линейного поиска заданного ключа в одномерном массиве*/
			int mas[10], ch;
			cout << " Massiv\n";
			for (i = 0; i < 10; i++)
			{
				mas[i] = 1 + rand() % 9;
				cout << mas[i] << "\t";
			}
			cout << endl;
			cout << " Chsilo kotooe nuzhno nayti\n";
			ch = 1 + rand() % 9;
			cout << ch << endl;
			lsearch(mas, 10, ch);
			cout << endl;
		}
		else if (nz == 3)
		{
			/*3.	Написать функцию, реализующую алгоритм бинарного поиска заданного ключа в одномерном массиве.*/
			int mas[10], ch;
			
			cout << " Massiv\n";
			
			for (i = 0; i < 10; i++)
			{
				mas[i] = 1 + rand() % 9;
				cout << mas[i] << "\t";
			}
			cout << endl;
			
			cout << " Binarniy poisk\n";
			
			ch = 1 + rand() % 9;
			cout << ch << endl;
			sort(mas, 10);
			
			bsearch(mas, 10, ch);
			cout << endl;
			
		}
		else if (nz == 4)
		{
			/*4.	Написать игру «Быки и коровы». Программа "загадывает" четырёхзначное число и играющий должен угадать его.
			После ввода пользователем числа программа сообщает, сколько цифр числа угадано (быки) и сколько цифр угадано и стоит на нужном месте (коровы). 
			После отгадывания числа на экран необходимо вывести количество сделанных пользователем попыток.  В программе необходимо использовать рекурсию*/
			
			int number_computer, number_player;
			int one_computer, two_computer, three_computer, four_computer, one_player, two_player, three_player, four_player;
			int bulls, cow;

			do {
				srand(time(0));
				number_computer = 1234; //(rand() % 9000 + 1000);

				one_computer = number_computer / 1000;
				two_computer = (number_computer % 1000) / 100;
				three_computer = (number_computer % 100) / 10;
				four_computer = (number_computer % 1000) % 10;
			} while (one_computer == 0 || one_computer == two_computer || one_computer == three_computer || one_computer == four_computer || two_computer == three_computer || two_computer == four_computer || three_computer == four_computer);



			do {
				cout << "                                  БЫКИ И КОРОВЫ\n\n";
				cout << "Введите число: ";
				cin >> number_player;

				one_player = number_player / 1000;
				two_player = (number_player % 1000) / 100;
				three_player = (number_player % 100) / 10;
				four_player = (number_player % 1000) % 10;

				bulls = 0;
				cow = 0;

				if (one_player == one_computer) bulls += 1; else if (one_player == two_computer || one_player == three_computer || one_player == four_computer) cow += 1;
				if (two_player == two_computer) bulls += 1; else if (two_player == one_computer || two_player == three_computer || two_player == four_computer) cow += 1;
				if (three_player == three_computer) bulls += 1; else if (three_player == one_computer || three_player == two_computer || three_player == four_computer) cow += 1;
				if (four_player == four_computer) bulls += 1; else if (four_player == one_computer || four_player == two_computer || four_player == three_computer) cow += 1;

				cout << "Быков: " << bulls << endl;
				cout << "Коров: " << cow << endl;
			} while (number_computer != number_player);

			
		}
	}
}




bool prost(int x)
{
	int r = 0;
	for (int i = 1; i <= x; i++)
	{
		if (x%i == 0)r++;
	}
	if (r == 2) return true;
	else return false;
}

void lsearch(int* arr, int len, int ch)
{
	int r = 0;
	for (int i = 0; i < len; i++)
	{
		if (arr[i] == ch)
		{
			printf("chislo %d", ch, i);
			r = 1;
			break;
		}
	}
	if (r == 0) printf("Chislo ne pravil'noe", ch);
}

void bsearch(int* arr, int len, int ch)
{
	int L = 0;
	int R = len - 1;
	int m;

	int r = 0;

	while (L <= R)
	{
		m = (R + L) / 2;
		if (ch > arr[m]) L = m;
		if (ch < arr[m]) R = m;
		if (ch == arr[m])
		{
			printf("Chsilo\n", ch);
			r = 1;
			break;
		}
	}
	if (r == 0)
	{
		printf("Chisla netu\n", ch);
	}
}

void sort(int* arr, int Len)
{
	int prom;
	for (int i = 0; i < Len; i++)
	{
		for (int j = 0; j < Len - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				prom = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = prom;
			}
		}
	}
}

