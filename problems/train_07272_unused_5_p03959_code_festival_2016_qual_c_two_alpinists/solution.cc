#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll const MOD = 1e9 + 7;
int main() {
  ll n;
  cin >> n;
  vector<ll> t(n), a(n), poss(n);
  for(int i=0;i<n;i++) cin >> t[i];
  for(int i=0;i<n;i++) cin >> a[i];
  ll ans = 1;
  if(t[n-1] != a[0]) {
    ans = 0;
  }
  poss[0] = poss[n-1] = 1;
  for(int i=1;i<n-1;i++) {
    if(t[i] > t[i-1])
      poss[i] = 1;
    else
      poss[i] = t[i];
  }
  for(int i=n-2;i>=0;i--) {
    if(a[i] > a[i+1]) {
      if(poss[i] == 1 && t[i] != a[i])
        ans = 0;
      if(poss[i] != 1 && t[i] < a[i])
        ans = 0;
      poss[i] = 1;
    } else {
      poss[i] = min<ll>(poss[i], a[i]);
    }
  }

  for(int i=0;i<n;i++) {
    ans *= poss[i];
    ans %= MOD;
  }
  cout << ans << endl;
}
