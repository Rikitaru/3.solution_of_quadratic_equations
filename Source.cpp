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
		output << "������� ��������� ����� " << i << endl;

		if (vec[i * 3] != 0) {//����������� �� ���������� ������
			float D = (pow(vec[i * 3 + 1], 2)) - 4*( vec[i * 3] * vec[i * 3 + 2]);

			output << "����� ���� ���������� ���������." << endl;
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
				output << "��� ��� � ��� ������������ �������������, �� ����� ������� ����������� �����." << endl;

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
				output << "� ����� ��������� ������������ ����� ����, ������� ���� ������ ������ ������� ���������." << endl;
				output << "X = " << (-vec[i * 3 + 1]) / (2 * vec[i * 3]) << endl;
			}
			else if (D > 0) {
					output << "X1 = (" << -vec[i * 3 + 1] << "+" << pow(D, 0.5) << ") / (" << 2 * vec[i * 3] << ") = " << (-vec[i * 3 + 1] + pow(D, 0.5)) / (2 * vec[i * 3]) << endl;
					output << "X2 = (" << -vec[i * 3 + 1] << "-" << pow(D, 0.5) << ") / (" << 2 * vec[i * 3] << ") = " << (-vec[i * 3 + 1] - pow(D, 0.5)) / (2 * vec[i * 3]) << endl;
			}
		}
		else if ((vec[0] == 0) && (vec[1] == 0)) {
			output << "����� ���� �� ���������. ������� ���." << endl;
		}
		else if (vec[0] == 0) {//����� ���� ��������� ���������
			//������� ����� � ��������� ����
			output << "����� ���� �������� ���������." << endl;
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


		cout << "������ �������� ��� ������������ ��� ����������� ���������? 1-��, 0-���" << endl;
		cin >> flag;
		if (flag != 1 && flag != 0) {
			throw 2;
		}
		else if (flag) {
			do {
				for (int i = 0; i < 3; i++) {
					cout << "������� ���������� " << i + 1 << endl;
					cin >> temp;
					coefficients.push_back(temp);
				}
				cout << "������ �������� ��� ������������ ��� ���������� ����������� ���������? 1-��, 0-���" << endl;
				cin >> flag;
			} while (flag);
		}
		cout << "��������� ���������� � ���������." << endl;
		input.close();
		ofstream Otput("Input.txt");
		calculations(coefficients, Otput);


	}
	catch (int a) {
		switch (a) {
		case 1:
			cout << "��������� ������ ������ �����. ������ ����� " << a << endl;
			break;
		case 2:
			cout << "�������� ���� ������. ������ ����� " << a << endl;
			break;
		case -1:
			cout << "������� ���� Input.txt �� ���������� � ���������� ���������. ������ ����� " << a << endl;
			break;
		case -2:
			cout << "������� ���� Input.txt ������. ������ ����� " << a << endl;
			break;
		}
	}
	getchar();
}