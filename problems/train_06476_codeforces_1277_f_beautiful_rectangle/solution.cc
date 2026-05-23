#include <bits/stdc++.h>
using namespace std;
const int N = (int)4e5 + 1;
int cnt[N], mem, kek[N];
vector<pair<int, int> > b;
vector<int> sum;
int test(int n, int m) {
  if (n > m) {
    swap(n, m);
  }
  if (b[0].first > n) {
    return (int)b.size() * n;
  }
  int l = 0, r = (int)b.size(), mid;
  while (r - l > 1) {
    mid = (l + r) / 2;
    if (b[mid].first <= n) {
      l = mid;
    } else {
      r = mid;
    }
  }
  return sum[l] + ((int)b.size() - 1 - l) * n;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int idx = 1;
  unordered_map<int, int> _unordered_map;
  kek[0] = a[0];
  _unordered_map[a[0]] = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i] != a[i - 1]) {
      kek[idx] = a[i];
      _unordered_map[a[i]] = idx++;
    }
  }
  for (int i = 0; i < n; ++i) {
    ++cnt[_unordered_map[a[i]]];
  }
  b.push_back({cnt[_unordered_map[a[0]]], a[0]});
  for (int i = 1; i < n; ++i) {
    if (a[i] != a[i - 1]) {
      b.push_back({cnt[_unordered_map[a[i]]], a[i]});
    }
  }
  sort(b.begin(), b.end());
  sum.push_back(b[0].first);
  for (int i = 1; i < (int)b.size(); ++i) {
    sum.push_back(sum.back() + b[i].first);
  }
  int ansH = 1, ansW = 1;
  for (int h = 1; h <= b.size(); ++h) {
    int l = 1, r = n / h + 1, m;
    while (r - l > 1) {
      m = (l + r) / 2;
      if (test(h, m) >= h * m) {
        l = m;
      } else {
        r = m;
      }
    }
    if (l * h > ansH * ansW) {
      ansH = h;
      ansW = l;
    }
  }
  if (ansH > ansW) {
    swap(ansH, ansW);
  }
  cout << ansH * ansW << '\n' << ansH << ' ' << ansW << '\n';
  vector<vector<int> > ans(ansH, vector<int>(ansW, 0));
  reverse(b.begin(), b.end());
  int ind = 0;
  int k = 0;
  for (int x = 0; x < ansW; ++x) {
    int y = 0;
    for (int i = 0; i < ansH; ++i) {
      ans[(y + i) % ansH][(x + i) % ansW] = b[ind].second;
      ++k;
      if (k == min(b[ind].first, ansH)) {
        ++ind;
        k = 0;
      }
    }
  }
  for (int i = 0; i < ansH; ++i) {
    for (int j = 0; j < ansW; ++j) {
      cout << ans[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
