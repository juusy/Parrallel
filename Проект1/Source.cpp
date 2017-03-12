#include <time.h>
#include "math.h"
#include <iostream>
using namespace std;
double My_F(double x, double y, double z)
{
	return 1.0 / (2 + sin(pow(x, 2) + pow(y, 2) + pow(x, 2)));
}
double Fun(double a, double b, double c, int N, double Func(double, double, double))
{
	double h = 1.0 / N;
	int k, i, j;
	double S1 = 0;
#pragma omp parallel  for  shared(a,b,c, h,N)  private(k,i,j) schedule(dynamic)\
		reduction(+:S1)  num_threads(4)
	for (i = 0; i <= N; i++)
		for (j = -(N-i); j < N; j++)
			for (k = -sqrt(pow(N-i,2)-pow(j,2)); k <= sqrt(pow(N-i,2)-pow(j,2)); k++) {
				
				S1 += Func(h*i, h*j, h*k);
				//cout << S1 << endl;
			}
	return pow(h, 3)*(Func(a, b, c));
}
int main() {
	double Tms = clock();
	double Solution1 = Fun(0, 0, 0, 1000, My_F);
	cout.precision(8);
	cout << "Solution for N=1000 :" << Solution1 << endl;
	double Solution2 = Fun(0, 0, 0, 1500, My_F);
	cout << "Solution for N=1500 :" << Solution2 << endl;
	double Solution3 = Fun(0, 0, 0, 2000, My_F);
	cout << "Solution for N=2000 :" << Solution3 << endl;

	Tms = (clock() - Tms) / CLOCKS_PER_SEC;
	cout << "Time=" << Tms << " sec" << endl;
	system("pause");
}