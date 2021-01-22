#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <clocale>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "rus");
	srand(time(0));
	const int n = 9;
	int m[n], index;
	for (int i = 0; i < n; i++) {
		m[i] = rand() % 50;
		cout << m[i] << "\t";
	}
	cout << "\n";
	int d = 0;
	cout << "Введите номер элемента который необходимо удалить ";
	cin >> index;
	for (int i = index; i < n; i++) {
		m[i] = m[i + 1];///Удалить элемент и сдвигаем массив
	}
	///Добавить после первого четного элемента массива элемент со значением M[ I-1 ]+2.
	for (int i = 0; i < n; i++) {
		if (m[i] % 2 == 0 && m[i] != 0) {
			for (int j = n; j > i + 1; j--) {
				m[j] = m[j - 1];
			}
			m[i + 1] = m[i - 1] + 2;
			break;
		}
	}
	cout << "Вывод массива: \n";
	for (int i = 0; i < n; i++)
	{
		cout << m[i] << "\t";
	}
	cout << "\n";
}
