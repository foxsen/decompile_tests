#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
	
	double l, r;
	
	int a[4], b[4];
	
	for(int i = 0; i < 4; i++){
		a[i] = 0;
		b[i] = 0;
	}
	
	while(scanf("%lf %lf", &l, &r) != EOF){
		if(l >= 1.1){
			a[0]++;
		}else if(l >= 0.6){
			a[1]++;
		}else if(l >= 0.2){
			a[2]++;
		}else{
			a[3]++;
		}
		if(r >= 1.1){
			b[0]++;
		}else if(r >= 0.6){
			b[1]++;
		}else if(r >= 0.2){
			b[2]++;
		}else{
			b[3]++;
		}
	}
	
	for(int i = 0; i < 4; i++){
		printf("%d %d\n", a[i], b[i]);
	}
	
	return 0;
}