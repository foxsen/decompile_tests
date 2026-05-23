#include<iostream>
#include<stdio.h>
#include<cmath>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#define oo 0x3f3f3f3f
#define OO 0x3f3f3f3f3f3f3f3f
#define LL long long 
#define res register int
#define STP system("pause")
using namespace std;
const int N=5e3;
LL f[N+5][N+5];
int a[N+5],b[N+5];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		f[i][i]=0;
	}
	for(int i=1;i<=n;++i){
		scanf("%d",&b[i]);
	}
	LL ans=0;
	for(int k=2;k<=n;++k){
		for(int i=1;i<=n-k+1;++i){
			f[i][i+k-1]=f[i+1][i+k-2]+(LL)(a[i]-a[i+k-1])*(b[i]-b[i+k-1]);
			ans=min(ans,f[i][i+k-1]);
		}
	}
//	cout<<ans<<'\n';
//	STP;
	for(int i=1;i<=n;++i)
		ans-=(LL)a[i]*b[i];
	cout<<-ans<<'\n';
	return 0;
}