#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,m;
int a[250],b[250];
ll dp[(1<<15)];
int cnt[(1<<15)];
ll bin[255];
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a[i]>>b[i];
		a[i]--; b[i]--;
	}
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<m;j++){
			if( ((i>>a[j])&1)+((i>>b[j])&1) == 2 ) cnt[i]++;
		}
	}
	bin[0] = 1;
	for(int i=1;i<255;i++) bin[i] = bin[i-1]*2LL%mod;
	for(int i=0;i<(1<<n);i++){
		int z = (((i>>0)&1));
		int o = (((i>>1)&1));
		if(z == o) continue;
		dp[i] = bin[cnt[i]];
		int j = i;
		while(j){
			j = (j-1)&i;
			if( ((j>>0)&1)+((j>>1)&1) == 1){
				dp[i] -= dp[j] * bin[cnt[i-j]] % mod;
			}
		}
		dp[i] = (dp[i]%mod+mod)%mod;
	}
	ll ans = 0;
	for(int mask=0;mask<(1<<n);mask++){
		if(((mask>>0)&1) == 0) continue;
		if(((mask>>1)&1) == 1) continue;
		int zan = (1<<n)-1-mask;
		while(1){
			if(((zan>>1)&1)){
				if(cnt[mask]+cnt[zan] == cnt[mask+zan]){
					ans += dp[mask]*dp[zan]%mod*bin[cnt[(1<<n)-1-mask-zan]]%mod;
					ans %= mod;
				}
			}
			if(zan == 0) break;
			zan = (zan-1)&((1<<n)-1-mask);
		}
	}
	cout << (bin[m]-ans+mod)%mod << endl;
}