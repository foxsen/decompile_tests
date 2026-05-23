#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
vector<int> seg[4 * N];
int arr[N], n;
void build(int s, int e, int idx) {
  if (s == e) {
    seg[idx].push_back(arr[s]);
    return;
  }
  build(s, (s + e) / 2, idx * 2);
  build((s + e) / 2 + 1, e, idx * 2 + 1);
  seg[idx] = seg[idx * 2];
  for (int i = 0; i < seg[idx * 2 + 1].size(); i++)
    seg[idx].push_back(seg[idx * 2 + 1][i]);
  sort(seg[idx].begin(), seg[idx].end());
}
int get(int s, int e, int idx, int l, int r, int val) {
  if (s > r || e < l) return 0;
  if (s >= l && e <= r)
    return seg[idx].end() - lower_bound(seg[idx].begin(), seg[idx].end(), val);
  return get(s, (s + e) / 2, idx * 2, l, r, val) +
         get((s + e) / 2 + 1, e, idx * 2 + 1, l, r, val);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &arr[i]);
  }
  build(1, n, 1);
  long long ans = 0;
  for (int i = 2; i <= n; i++) {
    ans += get(1, n, 1, 1, min(i - 1, arr[i]), i);
  }
  cout << ans << endl;
  return 0;
}
