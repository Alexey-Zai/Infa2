#include <iostream>
#include <math.h>
using namespace std;
int main() {

    float a = 1000, b = 0.0001, n, d, e, f;
    double a1 = 1000, b1 = 0.0001, n1, d1, e1, f1;

    d = pow(a - b, 3);
    e = pow(a, 3) - 3 * a * pow(b, 2);
    f = pow(b, 3) - 3 * b * pow(a, 2);
    n = (d - e) / f;

	d1 = pow(a1 - b1, 3);
	e1 = pow(a1, 3) - 3 * a1 * pow(b1, 2);
	f1 = pow(b1, 3) - 3 * b1 * pow(a1, 2);
	n1 = (d1 - e1) / f1;

    cout << "OTVET: " << n << "\n" <<  "OTVET2: " << n1;
	
	cin >> n;
    return 0;
}
