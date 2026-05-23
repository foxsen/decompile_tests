#include <bits/stdc++.h>
using namespace std;
int n, typ, t, x, ans, son;
map<int, int> tree[100111], H;
void update(int bas, int pos, int v) {
  for (int t = bas; t <= (1e9); t += t & -t) tree[pos][t] += v;
}
int get(int bas, int pos) {
  ans = 0;
  for (int t = bas; t > 0; t -= t & -t) ans += tree[pos][t];
  return ans;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> typ >> t >> x;
    if (typ == 1 && H.find(x) == H.end()) H[x] = ++son;
    if (typ <= 2) {
      update(t, H[x], (typ & 1) ? 1 : -1);
    } else {
      cout << get(t, H[x]) << endl;
    }
  }
}
