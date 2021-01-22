#include <iostream> 
using namespace std;
int main()
{
	int m, n;
	cout << "Vvedite znachenia m i n \n";
	cin >> m >> n;
	cout << "m - ++n \n" << (m - ++n) << "\n";
	cout << "++m > --n? \n" << (++m > --n) << "\n";
	cout << "--n < ++m? \n" << (--n < ++m) << "\n";
	return 0;
}
