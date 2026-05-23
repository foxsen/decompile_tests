#include <iostream>
#include <cstdio>
using namespace std;

long maxn=100000;
double f[100005][10];
double ans[100005];
double jie[10];
long n;
int main(){
	f[1][1]=1;
	jie[0]=1;
	for (int i=1;i<=10;i++) jie[i]=jie[i-1]/2;
	for (int i=1;i<=maxn;i++){
		ans[i]=ans[i-1]+1-f[i][0];
		//cout<<i<<": "<<ans[i]<<endl;
		for (int j=0;j<10;j++){
			f[i+1][j+1]+=f[i][j]*jie[j];
			f[i+1][0]+=f[i][j]*(1-jie[j]);
		}
	}
	while (cin>>n && n){
		printf("%.10f\n",ans[n]);
	}
}