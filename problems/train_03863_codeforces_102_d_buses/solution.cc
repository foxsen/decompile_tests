#include <bits/stdc++.h>
using namespace std;
const int P = 1000000007;
int n, m;
int s1[100100], s2[100100];
int un;
int uniq[200200];
vector<int> sset[200200];
int ways[200200];
int sum[200200];
int decr(int val) {
  int l = 0;
  int r = un;
  int m;
  while (r - l > 1) {
    m = (l + r) / 2;
    if (uniq[m] > val) {
      r = m;
    } else {
      l = m;
    }
  }
  return l;
}
int main() {
  int nn;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> s1[i] >> s2[i];
    uniq[un++] = s1[i];
    uniq[un++] = s2[i];
  }
  uniq[un++] = 0;
  uniq[un++] = n;
  sort(uniq, uniq + un);
  nn = 1;
  for (int i = 1; i < un; i++) {
    if (uniq[nn - 1] != uniq[i]) {
      uniq[nn++] = uniq[i];
    }
  }
  un = nn;
  for (int i = 0; i < m; i++) {
    s1[i] = decr(s1[i]);
    s2[i] = decr(s2[i]);
    sset[s2[i]].push_back(s1[i]);
  }
  sum[1] = 1;
  for (int i = 1; i < un; i++) {
    for (int j = 0; j < sset[i].size(); j++) {
      ways[i] = (ways[i] + (sum[i] + (P - sum[sset[i][j]]) % P) % P) % P;
    }
    sum[i + 1] = (sum[i] + ways[i]) % P;
  }
  cout << ways[un - 1];
  return 0;
}
