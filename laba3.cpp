#include <iostream>
#include <string>
#include <cmath>
#include <exception>
#include <cctype>
#include <time.h>
//#include <regex>
using namespace std;
void menu() 
{
	cout << "Доступны следующие функции:"<<endl;
	cout << "0.Ввод" << endl;
	cout << "1.Показать" << endl;
	cout << "2.Добавление" << endl;
	cout << "3.Сортировка" << endl;
	cout << "4.Сброс" << endl;
	cout << "5.Выход" << endl;
}
void fmenu() 
{
	cout << "Выберите способ заполнения:" << endl;
	cout << "1.В ручную" << endl;
	cout << "2.Случайным образом" << endl;
}

struct circle 
{
	double x;
	double y;
	double r;
};
void show(circle* a, int n)
{  
     for (int i = 0; i < n; i++) 
     { 
      cout << a[i].x << "|"; cout.clear();
      cout << a[i].y << "|"; cout.clear();
      cout << a[i].r << "|"<<"\n"; cout.clear();
     }
	 system("pause>nul");
}
void shon(circle** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i]->x << "|"; cout.clear();
		cout << a[i]->y << "|"; cout.clear();
		cout << a[i]->r << "|" << "\n"; cout.clear();
	}
	system("pause>nul");
}
int main()
{	
	try {
		int n = 0;
		circle t;
		circle* z = NULL;
		circle* a = new circle[n];
		circle** s = new circle * [n];
		system("chcp 1251>nul");
		char result, choice;
		do
		{
			system("cls");
			menu();
			cin >> result; cin.clear();
			if (result == '0')
			{
				if (n != 0) { cout << "Окружности уже введены,выберите пункт меню 'Добавление'"; }
				else {
					cout << "Введите желаемое кол-во окружностей" << endl;
					cin >> n; cin.clear();
					delete[]a;
					a = new circle[n];
					fmenu();
					cin >> choice; cin.clear();
					if (choice == '1')
					{
						
						cout << "Последовательно введите x,y и r окружностей" << endl;//regex f=(@"^[+-] ? \d + (\.\d + ) ? $");
						for (int i = 0; i < n; i++)
						{
							cin >> a[i].x; cin.clear();
							cin >>a[i].y; cin.clear();
							cin >> a[i].r; cin.clear();
							if (a[i].r < 0)abs(a[i].r);
						}
						int g = 0;
						for (int i = 0; i < n; i++)
						{
							if ((a[i].x == 0) && (a[i].y == 0.0) && (a[i].r == 0.0))g++;
						}
						
						if (g == n) {  delete[] a;n = 0; a = new circle[n]; }
					
						continue;
			
					}
					if (choice == '2')
					{
						srand(time(0));
						for (int i = 0; i < n; i++)
						{
							a[i].x = rand() % 10;
							a[i].y = rand() % 10;
							a[i].r = rand() % 10;
						}continue;
					}
					else { cout << "Ошибка ввода" << endl; continue; }

				}
			}
			if (result == '1') { if (n == 0) { cout << "Массив не создан!" << endl; }  else if (z == NULL)show(a, n); else shon(s, n); continue; }
			if (result == '2')
			{
				if (n == 0) { cout << "Массив не создан!" << endl; continue; }
				else {
					cout << "Выберите кол-во окружностей на добавление" << endl;
					int j;
					cin >> j; cin.clear();
					
					circle* b = new circle[n + j];
					for (int i = 0; i < n; i++)
					{
						b[i].x = a[i].x;
						b[i].y = a[i].y;
						b[i].r = a[i].r;
					}
					cout << "Два варианта заполнения:" << endl;
					cout << "1.Заполнение вручную" << endl;
					cout << "2.Случайным образом" << endl;
					char mch; cin >> mch; cin.clear();
					if (mch == '1')
					{
						for (int i = n; i < n + j; i++)
						{
							cout << "x = "; cout.clear();
							scanf_s("%lf", &b[i].x);
							cout << "y = "; cout.clear();
							scanf_s("%lf", &b[i].y);
							cout << "r = "; cout.clear();
							scanf_s("%lf", &b[i].r);
						}
					}
					if (mch == '2') 
					{
						for (int i = n; i < n+j; i++)
						{
							b[i].x = rand() % 10;
							b[i].y = rand() % 10;
							b[i].r = rand() % 10;
						}
					}
					cout << "Ввод окончен" << endl;
					delete[]a;
					a = new circle[n + j];
					for (int i = 0; i < n + j; i++)
					{
						a[i].x = b[i].x;
						a[i].y = b[i].y;
						a[i].r = b[i].r;
					}
					delete[]b;
					n = n + j;
					cout << "Окружности добавлены" << endl;
					system("pause>nul");
					continue;
				}
			}
			if (result == '3')
			{ 
				if (n == 0) { cout << "Массив не создан!" << endl; continue; }
				if (z == NULL)show(a, n); else shon(s, n);
				cout << "Доступно:" << endl;
				cout << "0.Простой вариант:" << endl;
				cout << "1.Сложный вариант:" << endl;
				cin >> choice;
				if (choice == '0')
				{
					cout << "Сортировка:\n1.По возрастанию.\n2.По убыванию" << endl;
					char choice1, choice2;
					cin >> choice1; cin.clear();//1-x;2-y;3-r;
					if (choice1 == '1')//сортировка по возрастанию
					{
						cout << "Введите параметр для сортировки" << endl; cout.clear();
						cin >> choice2; cin.clear();
						if (choice2 == 'x')
						{
							for (int i = 0; i < n; i++)
							{
								for (int j = 0; j < n; j++)
								{
									if (a[i].x < a[j].x) { t = a[i]; a[i] = a[j]; a[j] = t; }
								}
							}continue;
						}
						if (choice2 == 'y')
						{
							for (int i = 0; i < n; i++)
							{
								for (int j = 0; j < n; j++)
								{
									if (a[i].y < a[j].y) { t = a[i]; a[i] = a[j]; a[j] = t; }
								}
							}continue;
						}
						if (choice2 == 'r')
						{
							for (int i = 0; i < n; i++)
							{
								for (int j = 0; j < n; j++)
								{
									if (a[i].r < a[j].r) { t = a[i]; a[i] = a[j]; a[j] = t; }
								}
							}
							continue;
						}
					}
					if (choice1 == '2') //сортировка по убыванию
					{
						cout << "Введите параметр для сортировки" << endl; cout.clear();
						cin >> choice2; cin.clear();
						if (choice2 == 'x')
						{
							for (int i = 0; i < n; i++)
							{
								for (int j = 0; j < n; j++)
								{
									if (a[i].x > a[j].x) { t = a[i]; a[i] = a[j]; a[j] = t; }
								}
							}
							continue;
						}
						if (choice2 == 'y')
						{
							for (int i = 0; i < n; i++)
							{
								for (int j = 0; j < n; j++)
								{
									if (a[i].y > a[j].y) { t = a[i]; a[i] = a[j]; a[j] = t; }
								}
							}continue;
						}
						if (choice2 == 'r')
						{
							for (int i = 0; i < n; i++)
							{
								for (int j = 0; j < n; j++)
								{
									if (a[i].r > a[j].r) { t = a[i]; a[i]= a[j]; a[j] = t; }
								}
							}continue;
						}

					}
					circle t;
				}
				if (choice == '1')
				{
					
					delete[]s;
				    s = new circle*[n];
					for (int i = 0; i < n; i++)
					{
						s[i] = &a[i];
					}
					cout << "Сортировка:\n1.По возрастанию.\n2.По убыванию" << endl;
					char choice1, choice2;
					cin >> choice1; cin.clear();
					if (z != NULL)z = NULL;//1-x;2-y;3-r;
					if (choice1 == '1')//сортировка по возрастанию
					{
						cout << "Введите параметр для сортировки" << endl; cout.clear();
						cin >> choice2; cin.clear();
						if (choice2 == 'x')
						{
							for (int i = 0; i < n; i++)
							{
								for (int j = 0; j < n; j++)
								{
									if (s[i]->x < s[j]->x) { z = s[i]; s[i] = s[j]; s[j] = z; }
								}
							}continue;
						}

						if (choice2 == 'y')
						{
							for (int i = 0; i < n; i++)
							{
								for (int j = 0; j < n; j++)
								{
									if (s[i]->y < s[j]->y) { z = s[i]; s[i] = s[j]; s[j] = z; }
								}
							}continue;
						}
						if (choice2 == 'r')
						{
							for (int i = 0; i < n; i++)
							{
								for (int j = 0; j < n; j++)
								{
									if (s[i]->r < s[j]->r) { z = s[i]; s[i] = s[j]; s[j] = z; }
								}
							}
							continue;
						}
					}
					if (choice1 == '2') //сортировка по убыванию
					{
						cout << "Введите параметр для сортировки" << endl; cout.clear();
						cin >> choice2; cin.clear();
						if (choice2 == 'x')
						{
							for (int i = 0; i < n; i++)
							{
								for (int j = 0; j < n; j++)
								{
									if (s[i]->x>s[j]->x) { z = s[i]; s[i] = s[j]; s[j] = z; }
								}
							}
							continue;
						}
						if (choice2 == 'y')
						{
							for (int i = 0; i < n; i++)
							{
								for (int j = 0; j < n; j++)
								{
									if (s[i]->y > s[j]->y) { z = s[i]; s[i] = s[j]; s[j] = z; }
								}
							}continue;
						}
						if (choice2 == 'r')
						{
							for (int i = 0; i < n; i++)
							{
								for (int j = 0; j < n; j++)
								{
									if(s[i]->r > s[j]->r) { z = s[i]; s[i] = s[j]; s[j] = z; }
								}
							}continue;
						}

					}
				}

				}

			if (result == '4')
			{
				if (n == 0) { cout << "Массив не создан!" << endl; continue; }
				cout << "Функция удаления:" << endl;
				cout << "1.Полный сброс массива" << endl;
				cout << "2.Удаление i-той окружности" << endl;
				cin >> choice; cin.clear();
				if (choice == '2') 
				{
					show(a, n);
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
					circle* b = new circle[n - 1];
					int g = 0;
					for (int i = 0; i < n; i++) { if (i != j) { b[g] = a[i]; g++; } else continue; }
					delete[]a;
					a = new circle[n - 1];
					for (int i = 0; i < n - 1; i++)
					{
						a[i] = b[i];
					}
					delete[]b;
					n = n - 1;
					system("pause>nul");
					continue;
					
			    }
				if (choice == '1')
				{
					delete[]a;
					n = 0;
					cout << "Массив удалён" << endl;
					system("pause>nul");
					a = new circle[n];
				}
				continue;
			}
			if (result == '5')
			{
				cout << "Завершение работы программы...";
				system("pause>nul");
				return 0;//esli ploho s golovoi to exit(0) no proishodot otchistka vsei ispolzuemoi pamyati a sut v delete[]a';
			}        
			
			else
			{
				printf("Некорректный ввод ,завершение  работы исходной программы...");
				cout << "\n";
				system("pause>nul");
				continue;
			}
		} while (1 != 0);
	}
	catch (invalid_argument error) { cout << "Ошибка ввода" << endl; }
	catch (exception error) { cout << "Ошибка ввода" << endl; }
	system("pause>nul");
}