#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
ll N=400;
string S;
int main(){
	cin.tie(0);
	cin.sync_with_stdio(false);
	map<char,ll> cnt;
	cin>>N>>S;
	ll ans=0;
	REP(i,N){
		cnt[S[i]]++;
	}
	ans=cnt['R']*cnt['G']*cnt['B'];
	REP(i,N){
		FOR(j,i+1,N){
			ll k=2*j-i;
			if(S[i]==S[j])continue;
			if(k<N && S[k]!=S[i]&&S[k]!=S[j]){
				ans--;
			}
		}
	}
	cout<<ans<<endl;
}
