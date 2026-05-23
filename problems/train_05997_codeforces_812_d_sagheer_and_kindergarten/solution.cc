#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("-ffloat-store")
using namespace std;
clock_t time_p = clock();
void aryanc403() {
  time_p = clock() - time_p;
  cerr << "Time Taken : " << (float)(time_p) / CLOCKS_PER_SEC << "\n";
}
const long long int INF = 0xFFFFFFFFFFFFFFFL;
long long int seed;
mt19937 rng(seed = chrono::steady_clock::now().time_since_epoch().count());
inline long long int rnd(long long int l = 0, long long int r = INF) {
  return uniform_int_distribution<long long int>(l, r)(rng);
}
class CMP {
 public:
  bool operator()(pair<long long int, long long int> a,
                  pair<long long int, long long int> b) {
    return !(a.first < b.first || a.first == b.first && a.second <= b.second);
  }
};
void add(map<long long int, long long int> &m, long long int x,
         long long int cnt = 1) {
  auto jt = m.find(x);
  if (jt == m.end())
    m.insert({x, cnt});
  else
    jt->second += cnt;
}
void del(map<long long int, long long int> &m, long long int x,
         long long int cnt = 1) {
  auto jt = m.find(x);
  if (jt->second <= cnt)
    m.erase(jt);
  else
    jt->second -= cnt;
}
bool cmp(const pair<long long int, long long int> &a,
         const pair<long long int, long long int> &b) {
  return a.first < b.first || (a.first == b.first && a.second < b.second);
}
const long long int mod = 1000000007L;
const long long int maxN = 100000L;
long long int T, n, i, j, k, in, cnt, l, r, u, v, x, y;
long long int m, q, toy, cld;
string s;
vector<long long int> a;
long long int tin[maxN + 5], tout[maxN + 5], lst[maxN + 5], p[maxN + 5];
vector<long long int> e[maxN + 5];
bool root[maxN + 5];
bool isAnc(long long int u, long long int v) {
  return tin[u] <= tin[v] && tout[v] <= tout[u];
}
void dfs(long long int u) {
  tin[u] = ++T;
  for (auto x : e[u]) dfs(x);
  tout[u] = T;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  {
    cin >> n >> m >> k >> q;
    for (i = (1); i <= (n); ++i) root[i] = true;
    for (i = 0; i < (k); ++i) {
      cin >> cld >> toy;
      if (lst[toy]) {
        p[cld] = lst[toy];
        root[cld] = false;
      }
      lst[toy] = cld;
    }
    for (i = (1); i <= (n); ++i) e[p[i]].push_back(i);
    for (i = (1); i <= (n); ++i)
      if (root[i]) dfs(i);
    ;
    ;
    ;
    ;
    while (q--) {
      cin >> cld >> toy;
      n = lst[toy];
      ;
      if (isAnc(cld, n))
        cout << tout[cld] - tin[cld] + 1 << "\n";
      else
        cout << 0 << "\n";
    }
  }
  aryanc403();
  return 0;
}
