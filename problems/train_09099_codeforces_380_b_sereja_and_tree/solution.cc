#include <bits/stdc++.h>
using namespace std;
int n, m;
int L[150000];
int R[150000];
int used[1000001];
vector<int> a[7001][3];
int main() {
  cin >> n >> m;
  L[1] = 1;
  R[1] = 2;
  for (int i = 1; i <= 1000000; i++) {
    used[i] = false;
  }
  for (int i = 2; i < 150000; i++) {
    if (__builtin_popcount(i) == 1) {
      L[i] = R[i - 1] + 1;
      R[i] = L[i] + 1;
    } else {
      L[i] = -1;
      R[i] = R[i - 1] + 1;
    }
  }
  for (int q = 0; q < m; q++) {
    int t;
    fscanf(stdin, "%d", &t);
    if (t == 1) {
      int l, left, right, x;
      fscanf(stdin, "%d %d %d %d", &l, &left, &right, &x);
      a[l][0].push_back(left);
      a[l][1].push_back(right);
      a[l][2].push_back(x);
    } else {
      int level, pos;
      fscanf(stdin, "%d %d", &level, &pos);
      vector<int> rem;
      long long res = 0;
      int lo = pos;
      int hi = pos;
      for (int l = level; l <= n; l++) {
        for (int i = 0; i < a[l][0].size(); i++) {
          if (a[l][0][i] <= lo && lo <= a[l][1][i] ||
              a[l][0][i] <= hi && hi <= a[l][1][i] ||
              lo <= a[l][0][i] && a[l][1][i] <= hi) {
            if (!used[a[l][2][i]]) {
              res++;
              used[a[l][2][i]] = true;
              rem.push_back(a[l][2][i]);
            }
          }
        }
        if (L[lo] == -1) {
          lo = R[lo];
        } else {
          lo = L[lo];
        }
        hi = R[hi];
      }
      fprintf(stdout, "%d\n", res);
      for (int i = 0; i < rem.size(); i++) {
        used[rem[i]] = false;
      }
    }
  }
  return 0;
}
