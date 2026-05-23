#include <bits/stdc++.h>
using namespace std;

int main(){
	double a, b, x, tan;
	scanf("%lf%lf%lf", &a, &b, &x);
	x /= a;
	if(x <= a * b / 2){
		tan = b * b / (2 * x);
	}
	else{
		tan = 2 * (a * b - x) / (a * a);
	}
	printf("%.10lf\n", atan(tan) * 180 / acos(-1));
	return 0;
}