#include <bits/stdc++.h>
using namespace std;
template<class t> inline t read(t &x){
    char c=getchar();bool f=0;x=0;
    while(!isdigit(c)) f|=c=='-',c=getchar();
    while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
    if(f) x=-x;return x;
}
template<class t> inline void write(t x){
    if(x<0) putchar('-'),write(-x);
    else{if(x>9) write(x/10);putchar('0'+x%10);}
}

#define int long long

const int mod=1e9+7,N=2e5+5;
int n,a[N],s[N];

void doit(){
	int ans=0,sum;
	map<int,int> sf;
	read(n);
	for(int i=1;i<=n;i++) read(a[i]),s[i]=s[i-1]+a[i];
	sf[0]=sum=1;
	for(int i=1;i<=n;i++){
		int f=sum;
		(sum+=mod-sf[s[i-1]]+f)%=mod;
		sf.erase(s[i-1]);
		(sf[s[i]-a[i]]+=f)%=mod;
	}
	for(auto x:sf) (ans+=x.second)%=mod;
	write(ans);puts("");
}

signed main(){
	int t;
	read(t);
	while(t--) doit();
}