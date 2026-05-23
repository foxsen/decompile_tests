#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const long long mod = 1000000007;
int A[N], rmq[N][25], getL[N];
void go(int n) {
  for (int i = 0; i < n; i++) rmq[i][0] = i;
  for (int i = 1; i < N; i++) getL[i] = log2(i);
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 0; i + (1 << j) - 1 < n; i++) {
      if (A[rmq[i][j - 1]] < A[rmq[i + (1 << (j - 1))][j - 1]]) {
        rmq[i][j] = rmq[i][j - 1];
      } else {
        rmq[i][j] = rmq[i + (1 << (j - 1))][j - 1];
      }
    }
  }
}
int getmin(int i, int j) {
  int k = getL[j - i + 1];
  if (A[rmq[i][k]] < A[rmq[j - (1 << k) + 1][k]]) {
    return A[rmq[i][k]];
  }
  return A[rmq[j - (1 << k) + 1][k]];
}
vector<pair<int, int> > v;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, d, m;
  cin >> d >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    v.push_back(make_pair(x, y));
  }
  v.push_back(make_pair(d, 0));
  sort(v.begin(), v.end());
  int st = 0, fuel = n;
  for (int i = 0; i < v.size(); i++) A[i] = v[i].second;
  go(m + 1);
  long long cst = 0;
  for (int i = 0; i < v.size(); i++) {
    if (v[i].first - st > n) {
      cst = -1;
      break;
    }
    fuel -= (v[i].first - st);
    int l = i + 1, r = v.size() - 1, res = i;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (v[mid].first - v[i].first <= fuel) {
        l = mid + 1;
        res = mid;
      } else
        r = mid - 1;
    }
    int nxtmin = i;
    l = i + 1, r = v.size() - 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (getmin(i + 1, mid) <= v[i].second) {
        r = mid - 1;
        nxtmin = mid;
      } else
        l = mid + 1;
    }
    st = v[i].first;
    if (res >= nxtmin) {
      continue;
    }
    cst += (min(n, v[nxtmin].first - v[i].first) - fuel) * 1LL * v[i].second;
    fuel = min(n, v[nxtmin].first - v[i].first);
  }
  cout << cst;
  return 0;
}
