/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll t1,t2, r1, r2;
	cin >> t1 >> t2 >> r1 >> r2;
	if(r1 == -1 || r2 == -1){
		if(t1 == t2){
			print("Draw");
		}else if(t1 < t2){
			print("Alice");
		}else{
			print("Bob");
		}
	}else{
		if(r1 == r2){
			print("Draw");
		}else if(r1 > r2){
			print("Alice");
		}else{
			print("Bob");
		}
	}
	
}
