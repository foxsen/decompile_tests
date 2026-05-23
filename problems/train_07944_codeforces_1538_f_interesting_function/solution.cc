#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using namespace std;
ll func(ll n){
    ll ans = 0;
    while(n){
        ans += n;
        n /= 10;
    }
    return ans;
}
void solve(){
    ll l,r;
    cin >> l >> r;
    cout << func(r) - func(l) << endl;
}
int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   int t = 1;
   cin>>t;
   while(t--){
      solve();
   }
} 
