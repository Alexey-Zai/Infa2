#include <iostream>
#include <math.h>
#include <locale>
using namespace std;
int main() {

	int n = 3;
	double c = 0, b = 0, a = 1;
	cout << "BBECTI b=0" << endl;
	cin >> b;

	while (a > b) {
		a = (1 / (pow(2, n))) + (1 / (pow(3, n)));
		c += a;
		n++;
	}
	cout << "summ = " << c;
	return 0;
}
