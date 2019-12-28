#include "pch.h"
#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <exception>
using namespace std;

int main()
{
	system("chcp 1251>nul");
	double y;
	string xmin, xmax, dx;
	int k;
	do
	{
		try 
	{ system("cls");
		cout << "Введите xmin = "; cin >> xmin;
		cout.clear(); cin.clear();
		cout << "Введите xmax = "; cin >> xmax;
		cout.clear(); cin.clear();
		cout << "Введите dx = "; cin >> dx;
		cout.clear(); cin.clear();
		cout << "xmin = " <<xmin <<endl;
		cout.clear();
		cout << "xmax = " <<xmax<<endl;
		cout.clear();
		cout << "dx = "<<dx<<endl;
		cout.clear();
		double xk=stod(xmax);
		double h = stod(dx);
		
		for (double x = stod(xmin); x < xk; x +=h)
		{
			y = ((x + log(pow(x, x) + 1))*(x + cos(x))) / ((x*x) + pow(2.3, x));
			cout << "x=" << x << " " << "y=" << y << "\n";
		}
		cout << "Нажмите 5 для продолжения работы" << endl;
        scanf("%i",&k);
	}
    catch(std::exception error) { cout << "Ошибка ввода" << "\n"; }
	catch (std::runtime_error error) { cout << "Ошибка ввода" << "\n"; }
    catch (std::invalid_argument error) { cout << "Ошибка ввода" << "\n"; }
	} while (k == 5);
system("pause>nul");
return 0;
}







