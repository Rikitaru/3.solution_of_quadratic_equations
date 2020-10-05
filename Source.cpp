#include <stdio.h>
#include <iostream>
#include <clocale>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
void calculations(vector <float> &vec, ofstream &output) {

	for (int i = 0; i < vec.size()/3; i++) {
		output << vec[i * 3] << "\t" << vec[i * 3 + 1] << "\t" << vec[i * 3 + 2] << endl;
	}
	output << "999999" << endl;

	for (int i = 0; i < vec.size() / 3; i++) {
		output << "Решение уравнения номер " << i << endl;

		if (vec[i * 3] != 0) {//определение не линейности корней
			float D = (pow(vec[i * 3 + 1], 2)) - 4*( vec[i * 3] * vec[i * 3 + 2]);

			output << "Перед нами квадратное уравнение." << endl;
			output << vec[i * 3] << "x^2";
			if (vec[i * 3 + 1] > 0) {
				output << "+";
			}
			output << vec[i * 3 + 1] << "x";
			if (vec[i * 3 + 2] > 0) {
				output << "+";
			}
			output << vec[i * 3 + 2] << " = 0" << endl;
			output << "D = " << vec[i * 3 + 1] << "^2 - 4 * ";
			if (vec[i * 3] < 0) {
				output << "(" << vec[i * 3] << ")" << " * ";
			}
			else {
				output << vec[i * 3] << " * ";
			}

			if (vec[i * 3 + 2] < 0) {
				output << "(" << vec[i * 3 + 2] << ")" << " = " << D << endl;
			}
			else {
				output << vec[i * 3 + 2] << " = " << D << endl;
			}

			if (D < 0) {
				output << "Так как у нас дискриминант отрицательный, то будем считать комплексные корни." << endl;

				if (vec[i * 3] > 0) {
					output << "X1 = " << (-vec[i * 3 + 1] / (2 * vec[i * 3])) << " + " << (pow(-D, 0.5) / (-2 * vec[i * 3])) << "i" << endl;
					output << "X2 = " << (-vec[i * 3 + 1] / (2 * vec[i * 3])) << " - " << (pow(-D, 0.5) / (-2 * vec[i * 3])) << "i" << endl;
				}
				else {
					output << "X1 = " << (-vec[i * 3 + 1] / (2 * vec[i * 3])) << " + " << (pow(-D, 0.5) / (-2 * vec[i * 3])) << "i" << endl;
					output << "X2 = " << (-vec[i * 3 + 1] / (2 * vec[i * 3])) << " - " << (pow(-D, 0.5) / (-2 * vec[i * 3])) << "i" << endl;
				}

			}
			else if (D == 0) {
				output << "У этого уравнения Дискриминант равен нулю, поэтому один корень второй степени кратности." << endl;
				output << "X = " << (-vec[i * 3 + 1]) / (2 * vec[i * 3]) << endl;
			}
			else if (D > 0) {
					output << "X1 = (" << -vec[i * 3 + 1] << "+" << pow(D, 0.5) << ") / (" << 2 * vec[i * 3] << ") = " << (-vec[i * 3 + 1] + pow(D, 0.5)) / (2 * vec[i * 3]) << endl;
					output << "X2 = (" << -vec[i * 3 + 1] << "-" << pow(D, 0.5) << ") / (" << 2 * vec[i * 3] << ") = " << (-vec[i * 3 + 1] - pow(D, 0.5)) / (2 * vec[i * 3]) << endl;
			}
		}
		else if ((vec[0] == 0) && (vec[1] == 0)) {
			output << "Перед нами НЕ уравнение. Решения нет." << endl;
		}
		else if (vec[0] == 0) {//перед нами линнейное уравнение
			//находим корни и оформляем файл
			output << "Перед нами линейное уравнение." << endl;
			output << vec[i * 3 + 1] << "x";

			if (vec[i * 3 + 2] > 0) {
				output << "+";
			}
			output << vec[i * 3 + 2] << " = 0" << endl;

			output << vec[i * 3 + 1] << "x = " << -(vec[i * 3 + 2]) << endl;
			output << "x = " << -(vec[i * 3 + 2]) << " / " << vec[i * 3 + 1] << " = " << (-(vec[i * 3 + 2])) / vec[i * 3 + 1] << endl;
		}
		
	}
}
void main() {
	setlocale(LC_ALL, "Russian");
	vector <float> coefficients;
	float temp;
	int flag = 0;
	ifstream input("Input.txt");
	try {
		if (!input.is_open()) {

			throw - 1;
		}
		if (input.peek() == EOF) {
			throw - 2;
		}

		while (input >> temp && temp != 999999.00) {
			coefficients.push_back(temp);
		}
		if (flag) {
			throw 1;
		}


		cout << "Хотите добавить еще коэффициенты для квадратного уравнения? 1-Да, 0-Нет" << endl;
		cin >> flag;
		if (flag != 1 && flag != 0) {
			throw 2;
		}
		else if (flag) {
			do {
				for (int i = 0; i < 3; i++) {
					cout << "Введите коэфициент " << i + 1 << endl;
					cin >> temp;
					coefficients.push_back(temp);
				}
				cout << "Хотите добавить еще коэффициенты для следующего квадратного уравнения? 1-Да, 0-Нет" << endl;
				cin >> flag;
			} while (flag);
		}
		cout << "Программа приступает к рассчетам." << endl;
		input.close();
		ofstream Otput("Input.txt");
		calculations(coefficients, Otput);


	}
	catch (int a) {
		switch (a) {
		case 1:
			cout << "Произошла ошибка чтения файла. Ошибка номер " << a << endl;
			break;
		case 2:
			cout << "Неверный ввод выбора. Ошибка номер " << a << endl;
			break;
		case -1:
			cout << "Входной файл Input.txt не существует в директории программы. Ошибка номер " << a << endl;
			break;
		case -2:
			cout << "Входной файл Input.txt пустой. Ошибка номер " << a << endl;
			break;
		}
	}
	getchar();
}