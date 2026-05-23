#include<stdio.h>
#include<algorithm>
using namespace std;
double dp[1100];
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	dp[0]=1;
	for(int i=0;i<a;i++){
		double ks=1;
		for(int j=1;j<=b&&i+j<=a;j++){
			dp[i+j]+=dp[i]*ks/(a-i-j+1);
			ks*=(double)(a-i-j)/(a-i-j+1);
		}
	}
	printf("%.12f\n",dp[a]);
}