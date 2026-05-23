#include <bits/stdc++.h>
using namespace std;
int h, m, n, vn;
map<int, pair<int, int> > M;
int group[222222], pos[222222], host[222222];
vector<int> v[222222], first[222222];
inline void add(int i, int x, int d) {
  int m = first[i].size();
  while (x < m) {
    first[i][x] += d;
    x = x | (x + 1);
  }
}
inline int sum(int i, int x) {
  int m = first[i].size(), res = 0;
  while (x >= 0) {
    res += first[i][x];
    x = (x & (x + 1)) - 1;
  }
  return res;
}
int main() {
  memset(host, -1, sizeof(host));
  scanf("%d%d%d\n", &h, &m, &n);
  memset(group, -1, sizeof(group));
  for (int i = 0; i < h; ++i)
    if (group[i] == -1) {
      for (int j = i; group[j] == -1; j = (j + m) % h) {
        pos[j] = v[vn].size();
        group[j] = vn;
        v[vn].push_back(j);
      }
      ++vn;
    }
  for (int i = 0; i < vn; ++i) {
    first[i].resize(int(v[i].size()));
    for (int j = 0; j < v[i].size(); ++j) add(i, j, 1);
  }
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    char ch;
    int id, hash;
    scanf("%c %d", &ch, &id);
    if (ch == '+') {
      scanf("%d", &hash);
      int j = group[hash];
      int k = pos[hash];
      int l = k - 1, r = v[j].size();
      int base = sum(j, k - 1);
      while (r - l > 1) {
        int mid = (l + r) / 2;
        if (sum(j, mid) > base)
          r = mid;
        else
          l = mid;
      }
      if (r < v[j].size()) {
        M[id] = make_pair(j, r);
        add(j, r, -1);
        res += r - k;
      } else {
        l = -1, r = k;
        while (r - l > 1) {
          int mid = (l + r) / 2;
          if (sum(j, mid) > 0)
            r = mid;
          else
            l = mid;
        }
        M[id] = make_pair(j, r);
        add(j, r, -1);
        res += v[j].size() - k + r;
      }
    } else if (ch == '-') {
      int j = M[id].first;
      int k = M[id].second;
      add(j, k, 1);
    }
    scanf("\n");
  }
  cout << res << endl;
  return 0;
}
