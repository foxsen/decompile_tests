#include <bits/stdc++.h>
using namespace std;
const int MAX = 300009;
int n, m;
int P[MAX];
vector<int> v[MAX];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    P[a] = i;
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a = P[a];
    b = P[b];
    if (a > b) swap(a, b);
    v[b].push_back(a);
  }
  int mm = -1;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (int)v[i].size(); j++) mm = max(mm, v[i][j]);
    ans += mm + 1;
  }
  cout << (long long)n * (n + 1) / 2 - ans << endl;
  return 0;
}
