#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stdlib.h>
#include<cassert>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=500000004;
const double EPS=1e-6;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
long long dp[110][11000];
long long inv[110000];
int K;
long long calc(int a,int b){
	if(dp[a][b]>=0)return dp[a][b];
	if(a==0)return dp[a][b]=0;
	long long ret=0;
	for(int i=0;i<=K;i++){
		int f=(b+i)/a;
		int h=(b+i)%a;
		if(i>a){
			f=0;h=b+i;
		}
		ret=(ret+inv[K+1]*(calc(a-1,b+f)+h))%mod;
	}
	return dp[a][b]=ret;
}
int main(){
	inv[1]=1;
	for(int i=2;i<110000;i++)inv[i]=(mod-(mod/i)*inv[mod%i]%mod)%mod;
	int a,b;scanf("%d%d",&a,&b);
	K=b;
	for(int i=0;i<110;i++)for(int j=0;j<11000;j++)dp[i][j]=-1;
	long long ret=calc(a,0);
	for(int i=0;i<a;i++)ret=ret*(b+1)%mod;
	printf("%lld\n",ret);
}