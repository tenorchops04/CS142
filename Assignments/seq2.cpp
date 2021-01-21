#include <iostream>
#include <stdio.h>
#include <math.h>
#include <ctime>
#include "get_time.h"

using namespace std;

int main(){
	long double segs = pow(10,8);
	long double sum = 0;
	timer t;

	for(int l = 0; l < 10000; l++){
		for(int i = (long)l*segs/10000; i < (long)(l+1)*segs/10000; i++) {
			sum += (sin(1+i/segs) * log(1+i/segs) +	sin(1+(i+1)/segs) * log(1+(i+1)/segs)) / segs / 2;
		}
	}
	t.stop();

	cout << "Duration: " << t.get_total() << endl;
	printf("%.10Lf/n", sum);

	return 0;
}
