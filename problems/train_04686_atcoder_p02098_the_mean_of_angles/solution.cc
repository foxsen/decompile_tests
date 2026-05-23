#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


int main(){

	double degree1,degree2;
	scanf("%lf %lf",&degree1,&degree2);

	if(degree1 > degree2)swap(degree1,degree2);

	if(degree2-degree1 < 180.0){
		printf("%.10lf\n",(degree1+degree2)/2);
	}else{
		degree2 = degree2 - 360.0;

		double ans = (degree1+degree2)/2;
		if(ans < 0){
			ans += 360.0;
		}

		printf("%.10lf\n",ans);
	}

	return 0;
}