#include <bits/stdc++.h>
using namespace std;
const int MIF = 1e9 + 7;
const double PI = 4 * atan(1);
inline long long in() {
  long long x = 0;
  int n = 1;
  char c = getchar();
  while (!isdigit(c)) {
    n = (c == '-') ? -1 : 1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * n;
}
inline char inc() {
  char c = getchar();
  while (!isalnum(c)) c = getchar();
  return c;
}
inline string ins() {
  string s = "";
  char c = getchar();
  while (!isalnum(c)) c = getchar();
  while (isalnum(c)) s = s + c, c = getchar();
  return s;
}
inline void out(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) out(x / 10);
  putchar(x % 10 + '0');
}
void fre() {
  ofstream fre("42.inp");
  {
    fre << R"(
6 7
0 1 2
4 2 4
2 0 1
3 0 9
2 5 7
)";
  }
  fre.close();
  freopen(
      "42"
      ".inp",
      "r", stdin);
}
const int N = 100005;
typedef long long ar_N[N];
ar_N wei, dep, di, ve, bac10;
long long PHI, res;
int n, M;
vector<pair<int, int> > g[N];
bool ct[N];
map<long long, int> mp, mp2, null;
void DFS_WEI(int first, int last) {
  wei[first] = 1;
  for (auto& i : g[first])
    if (!ct[i.first] && i.first != last) {
      DFS_WEI(i.first, first);
      wei[first] += wei[i.first];
    }
}
int CT_FIND(int first) {
  int halfwei = wei[first] / 2;
  while (1) {
    int last = first;
    for (auto& i : g[first])
      if (!ct[i.first] && halfwei < wei[i.first] && wei[i.first] < wei[first]) {
        first = i.first;
        break;
      }
    if (first == last) return first;
  }
}
long long POW(int first, long long second) {
  long long res = 1, xx = first;
  while (second > 0) {
    if (second & 1) res = (res * xx) % M;
    second >>= 1;
    xx = (xx * xx) % M;
  }
  return res;
}
void GET(long long Di, long long Dep) {
  Di = -Di;
  while (Di < 0) Di += M;
  Dep = POW(PHI, Dep);
  res += mp[(Di * Dep) % M] - mp2[(Di * Dep) % M];
}
void CT_CAL(int first, int last) {
  for (auto& i : g[first])
    if (!ct[i.first] && i.first != last) {
      dep[i.first] = dep[first] + 1;
      ve[i.first] = ((i.second * bac10[dep[first]]) % M + ve[first]) % M;
      di[i.first] = (di[first] * 10 + i.second) % M;
      if (di[i.first] == 0) res++;
      if (ve[i.first] == 0) res++;
      mp[ve[i.first]]++;
      CT_CAL(i.first, first);
    }
}
void CT_GET(int first, int last) {
  GET(di[first], dep[first]);
  for (auto& i : g[first])
    if (!ct[i.first] && i.first != last) CT_GET(i.first, first);
}
void CT_UPDATE(int first, int last) {
  mp2[ve[first]]++;
  for (auto& i : g[first])
    if (!ct[i.first] && i.first != last) CT_UPDATE(i.first, first);
}
void CT_SOLVE(int first) {
  mp = null;
  DFS_WEI(first, first);
  first = CT_FIND(first);
  dep[first] = ve[first] = di[first] = 0;
  CT_CAL(first, first);
  for (auto& i : g[first])
    if (!ct[i.first]) {
      mp2 = null;
      CT_UPDATE(i.first, first);
      CT_GET(i.first, first);
    }
  ct[first] = true;
  for (auto& i : g[first])
    if (!ct[i.first]) CT_SOLVE(i.first);
}
void MAKE_PHI() {
  long long m = M;
  PHI = m;
  for (int i = 2; i * i <= m; i++)
    if (m % i == 0) {
      PHI = ((PHI / i) * (i - 1));
      while (m % i == 0) m /= i;
    }
  if (m > 1) PHI = ((PHI / m) * (m - 1));
  PHI--;
  PHI = POW(10, PHI);
}
int main() {
  n = in(), M = in();
  bac10[0] = 1;
  for (int i = 1; i <= 100000; i++) bac10[i] = (bac10[i - 1] * 10) % M;
  MAKE_PHI();
  for (int i_ = 1; i_ <= n - 1; i_++) {
    int first = in(), second = in(), z = in();
    g[first].emplace_back(second, z);
    g[second].emplace_back(first, z);
  }
  CT_SOLVE(1);
  out(res);
}
