#include <iostream>
#include <fstream>
#include "fun.h"
#include <string>
#include <cmath>
#include <exception>
#include <time.h>
using namespace std;
int main()
{
	try {
		int n = 0;
		double* a = new double[n];
		system("chcp 1251>nul");
		char result, choice;
		do
		{
			system("cls");
			menu();
			cin >> result; cin.clear();
			if (result == '0')
			{
				mcreate();
				cin >> choice;
			     /*if (choice =='0')
				{
					if (n != 0) { cout << "Массив уже создан"; continue; }
					else {
						string input;
						cout << "Введите имя файла: ";
						cin >> input;
						cout << endl;
						ifstream f;
						f.open(input.c_str(), std::ifstream::in);
						if (!f.is_open()) {
							cout << "Файл не открыт" << endl;
							cout << "Попробуйте другой способ заполнения массива";
							system("pause>nul"); continue;
						}
						else {
							for (int i = 0;;n++, i++)
							{
								if (!f.eof())
								{
									f >> a[i];
								}
								else cout << "Файл не считан" << endl;
								continue;
							}
						}
						f.close();
					}
			}*/
				if (choice == '1')
				{
					if (n != 0) { cout << "Массив уже создан"; continue; }
					else {
						cout << "Введите желаемую размерность";
						cin >> n;
						delete[]a;
						a = new double[n];
						srand(time(0));
						for (int i = 0; i < n; i++)
						{
							a[i] = rand() % 10;
						}
						//n = n1; 
						continue;
					}
				}
				if (choice == '2')
				{
					if (n != 0) { cout << "Массив уже создан"; continue; }
					else {
						cout << "Введите размерность массива n = "; cin >> n;
						delete[]a;
						a = new double[n];
						cout << "\n" << "Введите массив в ручную" << endl;
						for (int i = 0; i < n; i++)
						{
							cin >> a[i];
						}
						cin.clear();
						//n = n1;
						continue;
					}
				}
			}
			if (result == '1')
			{
				if (n == 0) { cout << "Массив не создан"; continue; }
				else {
					showmass(a, n);
					system("pause>nul");
					continue;
				}
			}
			if (result == '2')
			{
				if (n == 0) { cout << "Массив не создан"; continue; }
				else
				{
					cout << "Введите кол-во элементов на добавление";
					int j;  cin >> j; cin.clear(); cout.clear();
					double* b = new double[n + j];

					for (int i = 0; i < n + j; i++)
					{
						if (i < n) { b[i] = a[i]; }
						else
						{
							cout << "\n" << "Введите новый элемент";
							cin >> b[i];
						}
					}
					delete[]a;
					a = new double[n + j];
					for (int i = 0; i < n + j; i++) { a[i] = b[i]; }
					delete[]b;
					n = n + j;
					system("pause>nul");
					continue;
				}
			}
			if (result == '3')
			{
				if (n == 0) { cout << "Массив не создан"; continue; }
				else {
					dely();
					char choice1;
					cin >> choice1; cin.clear();
					if (choice1 == '1')
					{
						//for (int i = 0; i < n; i++) { cout << i << "|"; }
						//cout << "\n";
						showm(a, n);
						cout << "\n" << "Введите индекс удаляемого элемента";
						int j;
						for (int i = 0;; i++)
						{
							cin >> j;
							if ((j < 0) || (j > n))
							{
								cout << "Индекс вне границ массива" << "\n" << "Повторите ввод.." << endl;
							}
							else break;
						}
						cin.clear(); cout.clear();
						double* b = new double[n - 1];
						int g = 0;
						for (int i = 0; i < n; i++) { if (i != j) { b[g] = a[i]; g++; } else continue; }
						delete[]a;
						a = new double[n - 1];
						for (int i = 0; i < n - 1; i++)
						{
							a[i] = b[i];
						}
						delete[]b;
						n = n - 1;
						system("pause>nul");
						continue;
					}
					if (choice1 == '2')
					{
						delete[]a; n = 0;
						a = new double[n];

						continue;
					}
					if (choice1 == 'q')
					{
						cout << "Нажмите q для выхода из программы" << "\n";
						continue;
					}
				}
			}
			if (result == '4')
			{
				if (n == 0) { cout << "Массив не создан"; continue; }
				else {
					int x, y;
					showm(a, n);
					cout << "\n";
					cout << "Введите индексы первого элемента" << "\n"; cout.clear();
					cin >> x; cin.clear();
					cout << "Введите индекс второго элемента" << "\n"; cout.clear();
					cin >> y; cin.clear();
					if (((x < 0) || (x > n - 1)) || ((y < 0) || (y > n - 1))) { cout << "Индексы вне границ массива" << endl; system("pause>nul"); }
					else { double z = a[x]; a[x] = a[y]; a[y] = z; }
					continue;
				}
			}
			if (result == '5')
			{
				if (n == 0) { cout << "Массив не создан"; continue; }
				else {
					msort();
					double t = 0.0;
					char k; cin >> k; cin.clear();
					if (k == '1')
					{
						for (int i = 0; i < n; i++)
						{
							for (int j = 0; j < n; j++)
							{
								if (a[i] < a[j]) { t = a[i]; a[i] = a[j]; a[j] = t; }
							}

						}
					}
					if (k == '2')
					{
						for (int i = 0; i < n; i++)
						{
							for (int j = 0; j < n; j++)
							{
								if (a[i] > a[j]) { t = a[i]; a[i] = a[j]; a[j] = t; }
							}

						}
					}
					if ((k != '1') && (k != '2'))cout << "Ошибка ввода" << "\n";
					system("pause>nul");
					cout.clear();
					continue;
				}
			}
			if (result == '6')
			{
				if (n == 0) { cout << "Массив не создан"; continue; }
				else {
					double aveg = average(a, n);
					cout << "Среднее арифметическое массива = " << aveg;
					system("pause>nul");
					cout.clear();
					continue;
				}
			}
			if (result == '7')
			{
				if (n == 0) { cout << "Массив не создан"; continue; }
				else {
					double diff = raznost(a, n);
					cout << "Максимальная разность = " << diff;
					system("pause>nul");
					cout.clear();
					continue;
				}
			}
			if (result == '8')
			{
				if (n == 0) { cout << "Массив не создан"; continue; }
				else {
					double fl = avgsqr(a, n);
					cout << "Максимальное среднеквадратичное отклонение = " << abs(fl);
					system("pause>nul");
					cout.clear();
					continue;
				}
			}
			if (result == '9')
			{
				if (n == 0) { cout << "Массив не создан"; continue; }
				else {
					double raz = razavg(a, n);
					cout << "Разница между средними = " << abs(raz);
					system("pause>nul");
					cout.clear();
					continue;

				}
			}
			if (result == 'q')
			{
				cout << "Завершение работы программы...";
				system("pause>nul");
				return 0;
			}        //esli ploho s golovoi to exit(0) no proishodot otchistka vsei ispolzuemoi pamyati
			//else { cout << "Ошибка ввода"<<"\n"; }
			printf("Некорректный ввод ,завершение  работы исходной программы...");
			cout << "\n";
			system("pause>nul");
			printf("Перезапуск программы...");
		} while (1!=0);
	}
	//chto-to hz, nafig ono zdes nado,syuda voobhe ne prihodit
	catch (invalid_argument error) { cout << "Ошибка ввода"; }
	catch (exception error) { cout << "Ошибка в ходе выполнения"; }
	catch (runtime_error eror) { cout << "Ошибка выполнения"; }
	system("pause>nul");
}



	
		

		
			
		