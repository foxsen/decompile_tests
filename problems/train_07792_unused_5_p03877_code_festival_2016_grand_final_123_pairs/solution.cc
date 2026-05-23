#include<bits/stdc++.h>
#define N 10005
#define LL long long
using namespace std;
const int mo=1e9+7;
int n,a,b,c; LL fc[N],xf[N],ans;
LL fpm(LL x,LL y){ LL s=1; while(y){ if(y&1) s=(s*x)%mo; y>>=1,x=(x*x)%mo;} return s;}
LL C(int n,int m){ return fc[n]*xf[m]%mo*xf[n-m]%mo;}
LL f(int n,int m)
{
	if(!n) return (m==0);
	else return xf[n]*C(m+n-1,n-1)%mo;
}
int main()
{
	int i,j,p,q,r,s,v;
	cin>>n>>a>>b>>c;
	if(b&1){ printf("0"); return 0;}
	fc[0]=xf[0]=1;
	for(i=1;i<N;i++){
		fc[i]=(fc[i-1]*i)%mo;
		xf[i]=fpm(fc[i],mo-2);
	  }
	for(i=0;i<=a&&i<=c;i++)
		for(j=0;i+3*j<=c;j++){
			p=a-i,q=i,r=j,s=b/2,v=c-i-3*j;
			ans=(ans+fc[p+q+r+s]*xf[p]%mo*xf[q]%mo*xf[r]%mo*f(s,v))%mo;
		  }
	cout<<ans;
	return 0;
}
