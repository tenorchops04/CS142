#include <iostream>
#include <stdio.h>
#include <math.h>
#include <chrono>
#include <ctime>
#include <cilk/cilk.h>
#include <cilk/cilk_api.h>
#include "get_time.h"

//using namespace std::chrono;
using namespace std;

long double reduce(int* A, int n){
	long double segs = pow(10, 8);

	if(n == 1)
		return (sin(1+A[0]/segs) * log(1+A[0]/segs) + sin(1+(A[0]+1)/segs) * log(1+(A[0]+1)/segs)) / segs / 2;

	long double L, R;
	L = cilk_spawn reduce(A, n / 2);
	R = reduce(A + n/2, n - n/2);
	cilk_sync;
	
	return L + R;
}

int main(){
	int n = 100000000;
	long double sum = 0;
	int* A = new int[n];

	cilk_for(int i = 0; i < n; i++){
		A[i] = i;
	}

	timer t;
	sum = reduce(A, n);	
	t.stop();

	cout << "Duration: " << t.get_total() << endl;
	printf("%.10Lf\n", sum);

	delete[] A;
	return 0;
}
