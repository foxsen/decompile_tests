#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 100000 + 10, MOD = 1000 * 1000 * 1000 + 7,
          INF = 1000 * 1000 * 1000;
const double EPS = 1e-9, PI = 2. * acos(0.0);
int first[maxn];
pair<int, int> kit[maxn];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> kit[i].first >> kit[i].second;
    first[kit[i].first]++;
  }
  for (int i = 0; i < n; ++i) {
    int home = first[kit[i].second] + n - 1;
    cout << home << ' ' << 2 * (n - 1) - home << endl;
  }
  return 0;
}
