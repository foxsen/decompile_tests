#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
const int mod = 1000000007;
const int INF = 1000000010;
int n;
char S[5020];
int L[5010];
int C[5010];
int RV;
pair<int, int> RM;
int lookup[5010];
int val[5010][15];
int hp[5010][5010];
int H[13][(1 << 13) + 3];
void kmr() {
  for (int i = (0); i < (n); ++i) H[0][i] = S[i] - '0';
  pair<pair<int, int>, int> T[n];
  for (int s = (0); s < (12); ++s) {
    int d = (1 << s);
    for (int i = (0); i < (n); ++i)
      T[i] = make_pair(pair<int, int>(H[s][i], i + d < n ? H[s][i + d] : 0), i);
    sort(T, T + n);
    d = 0;
    for (int i = (0); i < (n); ++i) {
      if (i && T[i - 1].first != T[i].first) ++d;
      H[s + 1][T[i].second] = d;
    }
  }
}
bool eq(pair<int, int> a, pair<int, int> b) {
  if (a.second - a.first != b.second - b.first) return 0;
  return hp[a.first][a.second] == hp[b.first][b.second];
}
int cmp_d;
bool cmp(pair<int, int> a, pair<int, int> b) {
  int ha = hp[a.first][a.second];
  int hb = hp[b.first][b.second];
  if (ha == hb) return a.first < b.first;
  return ha < hb;
}
int diff(pair<int, int> a, pair<int, int> b) {
  if (max(a.second - a.first, b.second - b.first) > 12) {
    if (!eq(pair<int, int>(a.first, a.second - 12),
            pair<int, int>(b.first, b.second - 12)))
      return INF;
    a.first = a.second - 12;
    b.first = b.second - 12;
  }
  return val[a.first][a.second - a.first] - val[b.first][b.second - b.first];
}
vector<pair<int, pair<int, int> > > P;
pair<int, pair<int, int> > prep(pair<int, int> p) {
  return make_pair(hp[p.first][p.second], p);
}
int main() {
  scanf("%s", S);
  n = strlen(S);
  for (int i = (1); i < (n + 1); ++i) {
    int d = 0;
    while ((1 << (d + 1)) < i) ++d;
    lookup[i] = d;
  }
  for (int i = (0); i < (n); ++i) {
    val[i][0] = 0;
    for (int d = (1); d < (14); ++d)
      val[i][d] = val[i][d - 1] * 2 + S[i + d - 1] - '0';
  }
  kmr();
  for (int i = (0); i < (n); ++i)
    for (int j = (i + 1); j < (n + 1); ++j)
      hp[i][j] = (H[lookup[j - i]][i] << 16) +
                 H[lookup[j - i]][j - (1 << lookup[j - i])];
  for (int d = (1); d < (n + 1); ++d) {
    int m = P.size();
    for (int i = (0); i < (n + 1 - d); ++i)
      if (S[i] == '1') P.push_back(prep(pair<int, int>(i, i + d)));
    sort(P.begin() + m, P.end());
  }
  C[0] = 1;
  for (int i = (1); i < (n + 1); ++i) L[i] = INF;
  RV = INF;
  for (pair<int, pair<int, int> > p_ : P) {
    pair<int, int> p = p_.second;
    if (L[p.first] == INF) continue;
    C[p.second] = (C[p.second] + C[p.first]) % mod;
    L[p.second] = min(L[p.second], L[p.first] + 1);
    if (p.second == n) {
      if (RV == INF) {
        RV = L[n];
        RM = p;
      } else {
        if (diff(p, RM) < RV - L[n]) {
          RM = p;
          RV = L[n];
        }
      }
    }
  }
  printf("%d\n", C[n]);
  int r = 0;
  for (int i = (RM.first); i < (RM.second); ++i) r = (2 * r + S[i] - '0') % mod;
  r = (r + RV) % mod;
  printf("%d\n", r);
  return 0;
}
