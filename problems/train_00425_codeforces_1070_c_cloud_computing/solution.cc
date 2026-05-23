#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
const int N = 200005;
long long int tree[2 * N];
long long int tree1[2 * N];
vector<long long int> e(N, 0);
vector<long long int> cos1(N, 0);
int m;
vector<pair<pair<int, int>, pair<int, int>>> plan;
void updateTreeNode(int p, long long int value) {
  int n = m;
  tree[p + n] = value;
  p = p + n;
  for (int i = p; i > 1; i >>= 1) tree[i >> 1] = tree[i] + tree[i ^ 1];
}
long long int query(int l, int r) {
  int n = m;
  long long int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res += tree[l++];
    if (r & 1) res += tree[--r];
  }
  return res;
}
void updateTreeNode1(int p, long long int value) {
  int n = m;
  tree1[p + n] = value;
  p = p + n;
  for (int i = p; i > 1; i >>= 1) tree1[i >> 1] = tree1[i] + tree1[i ^ 1];
}
long long int query1(int l, int r) {
  int n = m;
  long long int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res += tree1[l++];
    if (r & 1) res += tree1[--r];
  }
  return res;
}
void solve() {
  int n;
  long long int k;
  cin >> n >> k >> m;
  for (int i = 0; i < 2 * N; i++) {
    tree[i] = 0;
    tree1[i] = 0;
  }
  for (int i = 0; i < m; i++) {
    int l, r, c, p;
    cin >> l >> r >> c >> p;
    plan.push_back(make_pair(make_pair(p, l), make_pair(r, c)));
  }
  sort(plan.begin(), plan.end());
  vector<vector<int>> d(1000000 + 5);
  for (int i = 0; i < m; i++) {
    d[plan[i].first.second - 1].push_back(i);
    d[plan[i].second.first].push_back(-i - 1);
  }
  long long int tot = 0;
  for (int i = 0; i < n; i++) {
    for (auto &j : d[i]) {
      if (j >= 0) {
        e[j] += (long long int)plan[j].second.second;
        cos1[j] += (long long int)plan[j].second.second *
                   (long long int)plan[j].first.first;
      } else {
        j *= -1;
        j -= 1;
        e[j] -= (long long int)plan[j].second.second;
        cos1[j] -= (long long int)plan[j].second.second *
                   (long long int)plan[j].first.first;
      }
      updateTreeNode(j, e[j]);
      updateTreeNode1(j, cos1[j]);
    }
    if (query(0, m) <= k) {
      tot += query1(0, m);
      continue;
    }
    if (query(0, 1) >= k) {
      tot += (long long int)plan[0].first.first * k;
      continue;
    }
    int st = 0;
    int end = m - 1;
    int w = m - 2;
    while (st <= end) {
      int mid = (st + end) / 2;
      if (query(0, mid + 1) <= k) {
        w = mid;
        st = mid + 1;
      } else {
        end = mid - 1;
      }
    }
    tot += query1(0, w + 1);
    int left = k - query(0, w + 1);
    tot += (long long int)plan[w + 1].first.first * left;
  }
  cout << tot << endl;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  srand(time(NULL));
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  int c = 0;
  while (t--) {
    solve();
    c += 1;
  }
  return 0;
}
