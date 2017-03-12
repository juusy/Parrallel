#include "Cycle.h"
#include "math.h"
#include "omp.h"
double Simps(double a, double b, double c, int N, double Func(double, double, double))
{
	double h = 1.0 / N;
	int k, i, j;
	double S1 = 0, Tmp1, Tmp2, Tmp3;

#pragma omp parallel  for  shared(a,b,c, h,N)  private(k,i,j, Tmp1, Tmp2, Tmp3) schedule(dynamic)\
		reduction(+:S1)  num_threads(4)
	for (i = 0; i<N; i++)
		for (j = 0; j<N; j++)
			for (k = 1; k<N; k++) {
				Tmp1 = i + 1.0 / 2.0;
				Tmp2 = j + 1.0 / 2.0;
				Tmp3 = k + 1.0 / 2.0;
				S1 += Func(h*Tmp1, h*Tmp2, h*Tmp3);
			}
	//S1 += Func();
	return pow(h, 3)*(Func(a, b, c));
}