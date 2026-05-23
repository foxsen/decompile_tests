#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[3005][3005];
int A,B,C,D,mod=998244353;
int main(){
	
	scanf("%d%d%d%d",&A,&B,&C,&D);
	f[A][B]=1;
	for (int i=A;i<=C;++i) {
		for (int j=B+(i==A);j<=D;++j) {
			f[i][j]=(f[i][j-1]*i+f[i-1][j]*j-f[i-1][j-1]*(i-1)%mod*(j-1))%mod;
		}
	}
	printf("%lld",(f[C][D]+mod)%mod);
	
	return 0;
}