#include <iostream>
#include <stdio.h>
#include <math.h>
#include <chrono>
#include <cilk/cilk.h>
#include <cilk/cilk_api.h>

using namespace std::chrono;
using namespace std;

int main(){
	int segs = pow(10,8);
	long double sum = 0;

	auto start = high_resolution_clock::now(); 

	cilk_for(int i = 0; i < segs; i++){
		sum += (sin(1 + i/segs) * log(1 + (i + 1)/segs)) / segs /2;
	}

	auto stop = high_resolution_clock::now(); 

	auto duration = duration_cast<milliseconds>(stop - start);

	cout << "Duration: " << duration.count() << endl;
	printf("%.10Lf\n", sum);

	return 0;
}
