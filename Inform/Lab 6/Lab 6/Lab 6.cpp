#include <iostream>
#include <string.h>
#include <string>
#include <cstdio>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	bool flag = false;
	char line[255] = "", bufferChar[255] = "", bufferNumb[255] = "", numbers[11] = "0123456789", s[2] = "";
	gets_s(line);
	for (int i = 0; i < strlen(line); i++) {
		for (int j = 0; j < 11; j++) {
			if (line[i] == numbers[j]) {
				s[0] = line[i];
				strcat_s(bufferNumb, s);
				flag = true;
				break;
			}
		}
		if (!flag) {
			s[0] = line[i];
			strcat_s(bufferChar, s);
		}
		flag = false;
	}
	s[0] = ' ';
	strcat_s(bufferChar, s);
	strcat_s(bufferChar, bufferNumb);
	cout << "\n Результат: " << bufferChar;
}
