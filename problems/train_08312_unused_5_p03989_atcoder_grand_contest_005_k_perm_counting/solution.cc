#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 4010
#define P 924844033

using namespace std;

int n,k,t;
int a[N];
int vis[N][2];
long long fac[N],g[N];
long long Ans;
long long f[N][N][2];

int main(){
  scanf("%d%d",&n,&k);
  for(int i=1;i<=n;i++)
    for(int j=0;j<2;j++)
      if(!vis[i][j]){
	int x=i,y=j,len=0;
	while(x<=n){
	  vis[x][y]=1;
	  len++;
	  x+=k; y^=1;
	}
	a[t+=len]=1;
      }
  f[1][0][0]=1;
  for(int i=1;i<=t;i++)
    for(int j=0;j<=n;j++){
      f[i+1][j][0]=(f[i][j][0]+f[i][j][1])%P;
      if(!a[i]) f[i+1][j+1][1]=f[i][j][0];
    }
  for(int i=1;i<=n;i++) g[i]=(f[t][i][0]+f[t][i][1])%P;
  fac[0]=1;
  for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%P;
  Ans=fac[n];
  for(int i=1,j=-1;i<=n;i++,j=-j) Ans=(Ans+P+j*g[i]*fac[n-i])%P;
  printf("%lld\n",Ans);
  return 0;
}
