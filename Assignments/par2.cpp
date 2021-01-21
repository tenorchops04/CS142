#include <ctime>
#include <cilk/cilk.h>
#include <cilk/cilk_api.h>
#include "get_time.h"
#include <math.h>

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
	long segs = pow(10,8);
	int n = 10000;
	long double sum = 0;
	int* A = new int[10000];

	timer t;
	for(int l = 0; l < 10000; l++){
		cilk_for(int i=(long)l*segs/10000; i<(long)(l+1)*segs/10000; i++){
			A[i - (long)l*segs/10000] = i;
		}
		sum += reduce(A, n);
	}

	t.stop();

	cout << "Duration: " << t.get_total() << endl;
	printf("%.10Lf\n", sum);

	delete[] A;
	return 0;
}
