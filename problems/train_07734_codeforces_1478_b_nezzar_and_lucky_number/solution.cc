//May the force be with me
#include "bits/stdc++.h"
#define f first
#define s second
#define inf 1e18
#define ll long long
#define mod 1000000007
#define pb push_back
#define vll vector<long long int>
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(x) ((long long int)(x).size())
#define mll map<long long int, long long int>
#define pll pair<long long int, long long int>
#define endl "\n"
using namespace std;

void solve(){
	ll n, k;
	cin >> n >> k;
	vll a(n);
	for(auto &it:a)cin>>it;
	for(auto it:a){
		ll div = it/k, rem = it%k;
		bool f = false;
		for(ll i = 0; i <= min(10ll, div); i++){
			ll num = i*k+rem;
			while(num){
				if(num%10 == k) f = true;
				num /= 10;
			}
			if(f)break;
		}
		if(f)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(20);
  ll t = 1;
  cin >> t;
  while(t--){
    solve();
    cout << endl;
  }
  return 0;
}
