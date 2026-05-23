#include <bits/stdc++.h>
using namespace std;
const int ssize = 8001;
const char sl = '\n';
int n;
vector<int> bit;
void add(int idx, int delta) {
  for (; idx < n; idx = idx | (idx + 1)) bit[idx] += delta;
}
int sum(int r) {
  int ret = 0;
  for (; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r];
  return ret;
}
int sum(int l, int r) { return sum(r) - sum(l - 1); }
int byn(int l, int r, int key) {
  int mid;
  while (l < r) {
    mid = ((l + r) >> 1);
    if (sum(mid) < key)
      l = mid + 1;
    else
      r = mid;
  }
  return l;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int q;
  cin >> n >> q;
  n++;
  bit = vector<int>(n);
  for (int i = 1; i < n; ++i) {
    int x;
    cin >> x;
    add(x, 1);
  }
  for (int i = 0; i < q; ++i) {
    int x;
    cin >> x;
    if (x < 0) {
      int key = x * -1;
      int t = byn(0, n, key);
      add(t, -1);
    } else
      add(x, 1);
  }
  int ans = byn(0, n, 1);
  cout << (ans == n ? 0 : ans) << sl;
  return 0;
}
