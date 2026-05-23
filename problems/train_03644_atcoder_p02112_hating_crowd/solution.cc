#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
#define MAXCH(a, b) a = max(a, b);
#define INF (1LL << 30)
using namespace std;
typedef long long ll;

ll N, M[100], D[100], V[100], S[100];

int main(void) {
  cin >> N;
  REP(i, 0, N) cin >> M[i] >> D[i] >> V[i] >> S[i];

  vector<ll> crowd(360, 0);
  REP(i, 0, N) {
    ll t = (M[i] - 1) * 30 + (D[i] - 1);
    REP(j, 0, V[i]) MAXCH(crowd[(t + j) % 360], S[i]);
    REP(j, 0, S[i]) MAXCH(crowd[(t + V[i] + j) % 360], S[i] - j - 1);
    REP(j, 0, S[i]) MAXCH(crowd[(t + 360 - j - 1) % 360], S[i] - j - 1);
  }

  // REP(i, 0, 360) cout << crowd[i] << " ";
  // cout << endl;

  cout << *min_element(crowd.begin(), crowd.end()) << endl;
}