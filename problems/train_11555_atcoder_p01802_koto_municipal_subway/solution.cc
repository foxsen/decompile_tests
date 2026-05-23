#define _USE_MATH_DEFINES
#include<stdio.h>
#include<string>
#include<iostream>
#include<cctype>
#include<cstdio>
#include<vector>
#include<stack>
#include <algorithm>
#include<math.h>
#include<set>
#include<map>
#include<iomanip>
using namespace std;



int main(){
	
int n,m;
while(1){
	cout<<setprecision(20);
	cin>>n>>m;
	if(!n&&!m)break;
	double a=n,b=0,h=99999999999999;
	for(int i=0;i<=n/2;i++){
		double x=i,y=n-i;
		h=min(h,abs(sqrt(x*x+y*y)-m));


	}
	cout<<h<<endl;

}

	return 0;
}