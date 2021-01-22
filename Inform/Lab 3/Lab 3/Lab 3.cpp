#include <iostream>
#include <cmath>
#define N 25
#define EPS 0.0001
#define PI 3.1415926535897932384626433832795
#define a 0.1
#define b 1
using namespace std;

int factorial(int x)
{
	if (x == 0) return 1;
	return x * factorial(x - 1);
}

int main()
{
	double x, dx, d = 0, y = 0;
	dx = (b - a) / 10;
	cout << "\tX\t\t\tSN\t\tSE\t\tY\t" << endl;
	for (x = a; x < b; x += dx)
	{
		double SN = 0, SE = 0;
		y = exp(x * cos(PI / 4.)) * cos(x * sin(PI / 4.));
		for (int i = 0; i <= N; i++)
		{
			SN += (cos(i * PI / 4.) / factorial(i)) * pow(x, i);
		}
		int i = 0;
		do {
			d = (cos(i * PI / 4.) / factorial(i)) * pow(x, i);
			SE += d;
			++i;
		} while (d > EPS);
		cout << "\t" << x << "\t\t\t" << SN << "\t\t" << SE << "\t\t" << y << "\n";
	}
	return 0;
}
