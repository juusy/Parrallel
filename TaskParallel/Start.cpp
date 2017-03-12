#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>
#include "Cycle.h"
using namespace std;
double My_F(double x, double y, double z)
{
	return 1.0 / (2 + sin(pow(x, 2) + pow(y, 2) + pow(x, 2)));
}
int main(void)
{
	double Tms = clock();
	double Solution1 = Simps(0, 0, 0, 1000, My_F);
	cout.precision(8);
	cout << "Solution for N=1000 :" << Solution1 << endl;
	double Solution2 = Simps(1.0, 2.0, 0, 1500, My_F);
	cout << "Solution for N=1500 :" << Solution2 << endl;
	double Solution3 = Simps(1.0, 2.0, 0, 2000, My_F);
	cout << "Solution for N=2000 :" << Solution3 << endl;

	Tms = (clock() - Tms) / CLOCKS_PER_SEC;
	cout << "Time=" << Tms << " sec" << endl;
	system("pause");
}