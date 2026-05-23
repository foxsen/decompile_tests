#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 300000

const LL mod=1000000007;
LL n,m,p,ans,f[N];
char s[N];

void upd(LL &x,LL y){x=(x+y)%mod;}

int main(){
	scanf("%lld%lld%s",&n,&m,s+1);
	if (s[1]=='B') for (LL i=1;i<=m;++i) s[i]=s[i]=='B'?'R':'B';
	p=n;
	ans=1;
	for (LL i=1,j=0,fst=0;i<=m;++i){
		if (s[i]=='R') ++j;
		else{
			ans=0;
			if (!fst) p=min(p,j&1?j:j+1);
			fst=1;
			if (j&1) p=min(p,j);
			j=0;
		}
	}
	if (!ans&&(n&1)){puts("0"); return 0;}
	if (ans){
		ans=0;
		f[1]=1;
		for (LL i=2;i<=n;++i) f[i]=(f[i-1]+f[i-2])%mod;
		upd(ans,f[n]+f[n-1]*2);
	}
	else{
		p=(p+1)/2;
		f[0]=1;
		for (LL i=1,j=0,k=0;i<=n/2;++i){
			upd(k,f[i-1]);
			if (j<i-p){upd(k,-f[j]); ++j;}
			upd(f[i],k);
		}
		for (LL i=2;i<=n&&i<=p*2;i+=2) upd(ans,i*f[(n-i)/2]);
	}
	printf("%lld\n",(ans+mod)%mod);
	
	return 0;
}
			