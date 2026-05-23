#include <bits/stdc++.h>
using namespace std;
long long arr[200005];
long long tree[3 * 200005];
long long lazy[3 * 200005];
void init(int b, int e, int nd = 1) {
  if (b == e) {
    tree[nd] = arr[b];
    return;
  }
  int left = nd * 2;
  int right = nd * 2 + 1;
  int mid = (b + e) / 2;
  init(b, mid, left);
  init(mid + 1, e, right);
  tree[nd] = min(tree[left], tree[right]);
}
long long query(int b, int e, int i, int j, int nd = 1) {
  if (b > j || e < i) return 1LL << 62;
  if (b >= i && e <= j) return min(lazy[nd], tree[nd]);
  int left = nd * 2;
  int right = nd * 2 + 1;
  int mid = (b + e) / 2;
  return min(lazy[nd],
             min(query(b, mid, i, j, left), query(mid + 1, e, i, j, right)));
}
void update(int b, int e, int i, int j, long long val, int nd = 1) {
  if (b > j || e < i) return;
  if (b >= i && e <= j) {
    lazy[nd] = min(lazy[nd], val);
    return;
  }
  int left = nd * 2;
  int right = nd * 2 + 1;
  int mid = (b + e) / 2;
  update(b, mid, i, j, val, left);
  update(mid + 1, e, i, j, val, right);
  tree[nd] = min(min(tree[left], tree[right]), min(lazy[left], lazy[right]));
}
int main() {
  for (int i = 0; i < 600005; i++) lazy[i] = 1LL << 62;
  for (int i = 0; i < 200005; i++) arr[i] = 1LL << 62;
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  init(1, n);
  for (int i = 1; i <= n; i++) {
    if (s[i - 1] == '0') {
      long long prev = i > 1 ? query(1, n, i - 1, i - 1) : 0;
      update(1, n, i, i, prev + i);
    } else {
      long long prev = i - k > 1 ? query(1, n, i - k - 1, i - k - 1) : 0;
      update(1, n, max(1, i - k), min(n, i + k), prev + i);
    }
  }
  cout << query(1, n, n, n) << "\n";
  return 0;
}
