#include <iostream>
#include <cstdio>
using namespace std;

int main(void){
	double s[11];
	while(cin>>s[1]){
		for(int i=2;i<11;i++)s[i]=((i%2==0)?(s[i-1]*2):(s[i-1]/3));
		double sum=0;
		for(int i=1;i<11;i++)sum+=s[i];
		printf("%.8lf\n",sum);
	}
	return 0;
}