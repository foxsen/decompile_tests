#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define p 1000000007
using namespace std;
namespace ywy{
	int c[4044][4044],f[4044][4044],g[4044][4044];
	inline void pre(int n){
		c[0][0]=1;for(register int i=1;i<=n;i++){
			c[i][0]=1;for(register int j=1;j<=i;j++)c[i][j]=(c[i-1][j-1]+c[i-1][j])%p;
		}for(register int i=0;i<=n;i++){
			g[i][0]=c[i][0];for(register int j=1;j<=n;j++)g[i][j]=(g[i][j-1]+c[i][j])%p;
		}for(register int i=0;i<=n;i++){
			f[i][0]=g[i][0];for(register int j=1;j<=n;j++)f[i][j]=(f[i][j-1]+g[i][j])%p;
		}
	}
	void ywymain(){
		int A,B;cin>>A>>B;pre(A+B);ll ans=0;for(register int t=1;t<=A+1;t++){
			for(register int i=0;i<t;i++){
				if(i==0){
					ans++;continue;
				}ans=(ans+(ll)c[B-1][i]*f[i-1][t-i-1])%p;
			}
		}cout<<ans<<endl;
	}
}
int main(){
	ywy::ywymain();return(0);
}