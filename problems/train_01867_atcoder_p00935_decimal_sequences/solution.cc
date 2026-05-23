#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

int main(void) {
  ll N;
  cin >> N;
  vector<ll> D(N);
  REP(i, 0, N) cin >> D[i];

  vector<bool> ok(N * N + 1, true);
  REP(i, 0, N) {
    ll x = 0;
    REP(j, i, N) {
      x = x * 10 + D[j];
      if(x > N * N) break;
      ok[x] = false;
    }
  }

  REP(i, 0, N * N + 1) {
    if(ok[i]) {
      cout << i << endl;
      break;
    }
  }
}
