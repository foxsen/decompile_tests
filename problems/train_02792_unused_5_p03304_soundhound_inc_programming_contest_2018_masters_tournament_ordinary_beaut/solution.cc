#include<cstdio>
#include<iostream>
#define ld long double
using namespace std;
ld n,m,d;
int main(){
	cin>>n>>m>>d;
	ld a=2.0;
	if(!d) a=1.0;
	printf("%.7Lf",(a*(n-d)*(m-1))/(n*n));
	return 0;
}