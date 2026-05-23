#include <bits/stdc++.h>
using namespace std;
bool isBitSet(int x, int i) { return x & (1 << i); }
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int k = 0;
    for (int i = 30; i >= 0; i--) {
      if (isBitSet(m + 1, i)) {
        if (!isBitSet(n, i)) k |= (1 << i);
      } else {
        if (isBitSet(n, i)) break;
      }
    }
    cout << k << "\n";
  }
  cerr << "Run time: " << fixed << setprecision(3)
       << (double)clock() / CLOCKS_PER_SEC << "s" << endl;
  return 0;
}
