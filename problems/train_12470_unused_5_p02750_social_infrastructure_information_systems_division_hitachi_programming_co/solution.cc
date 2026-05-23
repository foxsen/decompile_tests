#include<bits/stdc++.h>
#define sz(x) ((int)x.size())
#define pb push_back
#define ii pair<int,int>
#define ppb pop_back
#define orta ((bas+son)>>1)
#define st first
#define nd second
#define ll long long
#define N 200005
#define inf 1000000005
#define MOD 1000000007
#define LOG 29
#define EPS 0.000000001
#define M 305
using namespace std;

struct shop {
	int a,b;
} s[N];

int n,t;
int dp[34][N];

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);	

	cin>>n>>t;
	for(int i=1;i<=n;i++) { 
		cin>>s[i].a>>s[i].b;
	}
	sort(s+1,s+1+n,[](shop i,shop j) {
		return (ll)(j.a)*(i.b+1)<(ll)(i.a)*(j.b+1);
	});
	int b=n;
	for(int i=n;i>=1;i--) {
		if(s[i].a!=0) 
			break ;
		--b;
	}
	int magic=32;
	for(int tot=1;tot<=magic;tot++) {
		fill(dp[tot],dp[tot]+b+1,inf);
		for(int i=1;i<=b;i++) {
			dp[tot][i]=dp[tot][i-1];
			ll prv=dp[tot-1][i-1];
			ll nt=(prv+1)*(s[i].a+1)+s[i].b;
			if(nt>t) 
				nt=inf;
			dp[tot][i]=min((ll)dp[tot][i],nt);
		}
	}
	sort(s+b+1,s+1+n,[](shop i,shop j) {
		return i.b<j.b;
	});
	int res=0;
	for(int tot=0;tot<=magic;tot++) {
		int ct=dp[tot][b];
		if(ct>t) continue ;
		int ans=tot;
		for(int i=b+1;i<=n;i++) {
			if((ct+=s[i].b+1)>t) 
				break ;
			ans++; 
		}
		res=max(res,ans);
	}
	cout<<res;

}