#include <bits/stdc++.h>
const long double eps = 1e-9;
using namespace std;
template <class T>
inline T MAX(const T &_a, const T &_b) {
  return ((_a > _b) ? _a : _b);
}
template <class T>
inline T MIN(const T &_a, const T &_b) {
  return ((_a < _b) ? _a : _b);
}
template <class T>
inline T MAX3(const T &_a, const T &_b, const T &_c) {
  return MAX(MAX(_a, _b), _c);
}
template <class T>
inline T MIN3(const T &_a, const T &_b, const T &_c) {
  return MIN(MIN(_a, _b), _c);
}
template <class T>
inline T MAX4(const T &_a, const T &_b, const T &_c, const T &_d) {
  return MAX(MAX3(_a, _b, _c), _d);
}
template <class T>
inline T MIN4(const T &_a, const T &_b, const T &_c, const T &_d) {
  return MIN(MIN3(_a, _b, _c), _d);
}
template <class T>
inline T ABS(const T &_a) {
  return ((_a < 0) ? -_a : _a);
}
template <class T>
inline T SQR(const T &_a) {
  return _a * _a;
}
template <class T>
inline T gcd(T _a, T _b) {
  for (T _r; (_r = _a % _b); _b = _r) _a = _b;
  return _b;
}
template <class T>
inline T lcm(const T &_a, const T &_b) {
  return (_a / gcd(_a, _b)) * _b;
}
template <class T>
inline bool BETW(const T &_a, const T &_b, const T &_c) {
  return (_a >= MIN(_b, _c) && _a <= MAX(_b, _c));
}
template <class T>
inline bool EXT(const T &_a, const T &_b, const T &_c) {
  return !BETW(_a, _b, _c);
}
const int MAXN = 100010, MAXS = 300010;
int N, b[MAXS];
vector<int> adj[MAXN];
string S[MAXN], ss;
long long ans;
inline void KMP_preprocess() {
  int i = 0, j = b[0] = -1;
  while (i < ((int)ss.size())) {
    while (j >= 0 && ss[i] != ss[j]) j = b[j];
    ++i;
    ++j;
    b[i] = j;
  }
}
inline int KMP_match(string &T, int j) {
  int i = 0;
  while (i < ((int)T.size())) {
    while (j >= 0 && T[i] != ss[j]) j = b[j];
    i++;
    j++;
    if (j == ((int)ss.size())) ans++, j = b[j];
  }
  return j;
}
void dfs(int node, int state) {
  for (int i = 0; i < ((int)adj[node].size()); ++i)
    dfs(adj[node][i], KMP_match(S[adj[node][i]], state));
}
int main() {
  int i, f;
  ios::sync_with_stdio(false);
  cin >> N;
  for (i = 2; i <= N; ++i) {
    cin >> f >> S[i];
    adj[f].push_back(i);
  }
  cin >> ss;
  KMP_preprocess();
  dfs(1, 0);
  cout << ans;
  return 0;
}
