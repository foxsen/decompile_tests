#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int M = 1e6 + 5;
const int INF = 0x3f3f3f3f;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  int n, h, a, b, k;
  cin >> n >> h >> a >> b >> k;
  for (int i = 1; i <= k; i++) {
    int ta, fa, tb, fb;
    cin >> ta >> fa >> tb >> fb;
    if (ta == tb) {
      cout << abs(fa - fb) << endl;
      continue;
    }
    long long ans = 0;
    if (fa < a) ans += abs(fa - a), fa = a;
    if (fa > b) ans += abs(fa - b), fa = b;
    ans += abs(tb - ta) + abs(fa - fb);
    cout << ans << endl;
  }
  return 0;
}
