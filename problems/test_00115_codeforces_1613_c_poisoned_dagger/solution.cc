#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long int llINF = (long long)(1e18) + 100;
const int MAXN = 4e5 + 10;
long long int n, a[200], h;
bool test(long long int val) {
  long long int hp = h;
  for (int i = 0; i < n - 1; i++) {
    long long int aux = min(val, a[i + 1] - a[i]);
    hp -= aux;
    if (hp <= 0) return true;
  }
  return hp <= val;
}
void solve() {
  cin >> n >> h;
  for (int i = 0; i < n; i++) cin >> a[i];
  long long int ini = 1, fim = llINF, bst = llINF;
  while (ini <= fim) {
    long long int meio = (ini + fim) / 2;
    if (test(meio)) {
      bst = meio;
      fim = meio - 1;
    } else
      ini = meio + 1;
  }
  cout << bst << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;
  while (T--) solve();
}
