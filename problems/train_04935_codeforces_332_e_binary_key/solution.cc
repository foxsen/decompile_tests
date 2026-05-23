#include <bits/stdc++.h>
using namespace std;
const int MAXS = 200;
const int MAXP = 1e6;
const int MAXK = 2000;
bool canTake[MAXS + 5][MAXK + 5][MAXS + 5];
char s[MAXS + 5], p[MAXP + 5];
int S, P, K;
bool best[MAXK + 5][MAXS + 5];
bool vis[MAXK + 5][MAXS + 5];
bool decision[MAXK + 5][MAXS + 5];
int ones;
bool solve(int i_p, int i_s) {
  if (i_p == K && i_s == ones) return true;
  if (i_s > ones) return false;
  if (i_p == K) return false;
  bool& ret = best[i_p][i_s];
  if (vis[i_p][i_s]) return ret;
  vis[i_p][i_s] = true;
  decision[i_p][i_s] = 0;
  ret = solve(i_p + 1, i_s);
  if (!ret && canTake[ones][i_p][i_s] && solve(i_p + 1, i_s + 1)) {
    ret = 1;
    decision[i_p][i_s] = 1;
  }
  return ret;
}
void pre() {
  for (int ones = 1; ones <= S; ones++) {
    for (int i1 = 0; i1 < K; i1++) {
      for (int i2 = 0; i2 < ones; i2++) {
        int j1, j2;
        for (j1 = i1, j2 = i2; j1 < P && j2 < S && p[j1] == s[j2];
             j1 += K, j2 += ones)
          ;
        canTake[ones][i1][i2] = j1 >= P && j2 >= S;
      }
    }
  }
}
string construct() {
  string ret = "";
  int i1, i2 = 0;
  for (i1 = 0; i1 < K; i1++) {
    ret += '0' + decision[i1][i2];
    i2 += decision[i1][i2];
  }
  return ret;
}
int main() {
  int c, c2;
  gets(p);
  gets(s);
  scanf("%d", &K);
  P = strlen(p);
  S = strlen(s);
  pre();
  string ret;
  for (ones = 1; ones <= S; ones++) {
    memset(vis, 0, sizeof(vis));
    if (solve(0, 0)) {
      string cur = construct();
      if (ret.size() == 0 || ret > cur) ret = cur;
    }
  }
  if (ret.size() == 0) ret = "0";
  printf("%s\n", ret.c_str());
  return 0;
}
