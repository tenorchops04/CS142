#include <iostream>
#include <stdio.h>
#include <math.h>
#include <ctime>
#include "get_time.h"

using namespace std;

int main(){
	long double segs = pow(10,8);
	long double sum = 0;

	//auto start = high_resolution_clock::now(); 
	
	timer t;
	for(int i = 0; i < segs; i++){
		sum += (sin(1 + i/segs) * log(1+i/segs) + sin(1+(i+1)/segs) * log(1 + (i + 1)/segs)) / segs /2;
	}
	
	t.stop();
	//auto stop = high_resolution_clock::now(); 

	//auto duration = duration_cast<milliseconds>(stop - start);

	cout << "Duration: " << t.get_total() << endl;
	printf("%.10Lf\n", sum);

	return 0;
}
