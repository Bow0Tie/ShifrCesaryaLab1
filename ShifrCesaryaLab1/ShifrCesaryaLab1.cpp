// ShifrCesaryaLab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

#define MESS_LENGTH 256

using namespace std;

int key = 0;
char mes[MESS_LENGTH];
char mesCoded[MESS_LENGTH];
char mesDecoded[MESS_LENGTH];

int main()
{
	setlocale(LC_ALL, "Russian");
	while (true)
	{
		cout << "Введите сообщение(только латиница)" << endl;
		cin.ignore();
		cin.getline(mes, MESS_LENGTH);
		cout << "Введите ключ шифра(от 1 до 25)" << endl;
		cin >> key;
		while (key < 1 || key > 25)
		{
			cin.clear();
			cin.ignore();
			cout << "Вы ввели неверный код шифра, поторите ввод" << endl;
			cin >> key;
		}
		// Кодируем
		for (size_t i = 0; i < MESS_LENGTH; i++)
		{
			if ((mes[i] >= 65 && mes[i] <= 90) || (mes[i] >= 97 && mes[i] <= 122))
			{
				if (((mes[i] + key) > 90 && (mes[i] + key) < 97) || (mes[i] + key) > 122)
				{
					mesCoded[i] = mes[i] + key - 26;
				}
				else
				{
					mesCoded[i] = mes[i] + key;
				}
			}
			else if (mes[i] != 0)
			{
				mesCoded[i] = mes[i];
			}
		}
		// Декодируем
		for (size_t i = 0; i < MESS_LENGTH; i++)
		{
			if ((mesCoded[i] >= 65 && mesCoded[i] <= 90) || (mesCoded[i] >= 97 && mesCoded[i] <= 122))
			{
				if (((mesCoded[i] - key) > 90 && (mesCoded[i] - key) < 97) || (mesCoded[i] - key) < 65)
				{
					mesDecoded[i] = mesCoded[i] - key + 26;
				}
				else
				{
					mesDecoded[i] = mesCoded[i] - key;
				}
			}
			else if (mesCoded[i] != 0)
			{
				mesDecoded[i] = mesCoded[i];
			}
		}
		cout << "Оригенальное сообщение:";
		cout << mes << endl;
		cout << "Закодированное сообщение:";
		cout << mesCoded << endl;
		cout << "Разкодированное сообщение:";
		cout << mesDecoded << endl;
		for (int i = 0; i < MESS_LENGTH; i++)
		{
			mes[i] = 0;
			mesCoded[i] = 0;
			mesDecoded[i] = 0;
		}
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
