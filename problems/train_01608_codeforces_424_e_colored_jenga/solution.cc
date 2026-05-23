#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &s, const pair<A, B> &p) {
  return s << "(" << p.first << "," << p.second << ")";
}
template <typename T>
ostream &operator<<(ostream &s, const vector<T> &c) {
  s << "[ ";
  for (auto it : c) s << it << " ";
  s << "]";
  return s;
}
int N, second;
const int MAXS = 1510101;
const double INF = 1E20;
const double prob[3] = {1. / 6., 1. / 3., 1. / 3.};
char arr[6][4];
long long states[MAXS];
unordered_map<long long, int> mp;
double dp[MAXS];
bool isterm[MAXS];
vector<int> trans[MAXS][3];
vector<int> ladd[64][3], ldel[64][3];
bool lok[64], lfull[64];
long long zv[64], yv[64];
long long lrand() { return (rand() * (long long)RAND_MAX) + rand(); }
long long llrand() {
  return lrand() * (long long)RAND_MAX * RAND_MAX + lrand();
}
int lmin(int z) {
  int n = (z & 0xc) | ((z & 0x3) << 4) | ((z & 0x30) >> 4);
  return min(n, z);
}
void makel() {
  for (int i = 0; i < 64; i++) {
    lok[i] = (i & 0xf) and (i & 0x3c) and i == lmin(i);
    lfull[i] = (i & 0x3) and (i & 0xc) and (i & 0x30);
    zv[i] = llrand() % (long long)1e16;
    yv[i] = llrand() % (long long)1e16;
  }
  for (int i = 0; i < 64; i++) {
    for (int p = 0; p < 3; p++) {
      if (!lok[i]) continue;
      int clr = (i >> (2 * p)) & 3;
      if (!clr) continue;
      int ns = lmin(i - (clr << (2 * p)));
      if (lok[ns]) ldel[i][clr - 1].push_back(ns);
    }
    for (int p = 0; p < 3; p++) {
      if ((i >> (2 * p)) & 3) continue;
      for (int c = 0; c < 3; c++) {
        int ns = lmin(i + ((c + 1) << (2 * p)));
        ladd[i][c].push_back(ns);
      }
    }
    for (int c = 0; c < 3; c++) {
      sort(begin(ladd[i][c]), end(ladd[i][c]));
      sort(begin(ldel[i][c]), end(ldel[i][c]));
      ladd[i][c].resize(unique(begin(ladd[i][c]), end(ladd[i][c])) -
                        ladd[i][c].begin());
      ldel[i][c].resize(unique(begin(ldel[i][c]), end(ldel[i][c])) -
                        ldel[i][c].begin());
    }
  }
}
vector<int> decode(long long x) {
  vector<int> ret;
  while (x) {
    ret.push_back(x & 0x3fLL);
    x >>= 6;
  }
  return ret;
}
long long encode(const vector<int> &v) {
  long long res = 0;
  int sz = ((int)(v).size());
  for (int i = sz - 1; i >= 0; i--) res = (res << 6) + v[i];
  return res;
}
long long enhash(const vector<int> &v) {
  int sz = ((int)(v).size());
  long long res = yv[v[sz - 1]];
  for (int i = 0; i < sz - 1; i++)
    if ((v[i] & 0xc) and ((v[i] & 0x30) or (v[i] & 0x3))) res += zv[v[i]];
  return res;
}
vector<int> normalize(vector<int> v) {
  int sz = ((int)(v).size());
  vector<int> nv;
  for (int i = 0; i < sz - 1; i++)
    if ((v[i] & 0xc) and ((v[i] & 0x30) or (v[i] & 0x3))) nv.push_back(v[i]);
  sort(begin(nv), end(nv));
  nv.push_back(v[sz - 1]);
  return nv;
}
double go(int s) {
  if (dp[s] != INF) return dp[s];
  if (trans[s][0].empty() and trans[s][1].empty() and trans[s][2].empty()) {
    dp[s] = 0;
  } else {
    double best[3] = {INF, INF, INF};
    for (int j = 0; j < 3; j++)
      for (auto ns : trans[s][j]) best[j] = min(best[j], go(ns));
    double okprob = 0, pg = 0;
    for (int j = 0; j < 3; j++)
      if (best[j] != INF) okprob += prob[j], pg += prob[j] * best[j];
    dp[s] = (1. + pg) / okprob;
  }
  return dp[s];
}
string s2s(vector<int> v) {
  string ret = "\n";
  int sz = ((int)(v).size());
  for (int j = sz - 1; j >= 0; j--) {
    int x = v[j];
    for (int i = 0; i < 3; i++) {
      int y = x & 3;
      ret.push_back(y == 1 ? 'R' : (y == 2 ? 'G' : (y == 0 ? ' ' : 'B')));
      x >>= 2;
    }
    ret += "\n";
  }
  ret.pop_back();
  return ret;
}
double calc() {
  makel();
  vector<int> sv;
  for (int i = 0; i < N; i++) {
    int a[3];
    for (int j = 0; j < 3; j++)
      a[j] = (arr[i][j] == 'R' ? 1 : (arr[i][j] == 'G' ? 2 : 3));
    int z = (a[0] + (a[1] << 2) + (a[2] << 4));
    sv.push_back(lmin(z));
  }
  long long hs = enhash(sv);
  sv = normalize(sv);
  long long hv = encode(sv);
  second = 0;
  states[second] = hv;
  mp[hs] = second;
  second++;
  for (int pos = 0; pos < second; pos++) {
    long long h = states[pos];
    vector<int> v = decode(h);
    int sz = ((int)(v).size());
    if (sz == 1) continue;
    int nxt = sz - 1;
    if (lfull[v[sz - 1]]) {
      v.push_back(0);
      nxt++;
    }
    for (int i = 0; i < sz - 1; i++) {
      for (int c = 0; c < 3; c++) {
        for (auto x : ldel[v[i]][c]) {
          int ov = v[i];
          v[i] = x;
          for (auto y : ladd[v[nxt]][c]) {
            int on = v[nxt];
            v[nxt] = y;
            long long hh = enhash(v);
            if (!mp.count(hh)) {
              vector<int> ns = normalize(v);
              long long nh = encode(ns);
              states[second] = nh;
              mp[hh] = second;
              second++;
            }
            int nid = mp[hh];
            trans[pos][c].push_back(nid);
            v[nxt] = on;
          }
          v[i] = ov;
        }
      }
    }
    for (int c = 0; c < 3; c++)
      trans[pos][c].resize(unique(begin(trans[pos][c]), end(trans[pos][c])) -
                           trans[pos][c].begin());
  }
  for (int i = 0; i < second; i++)
    isterm[i] =
        (trans[i][0].empty() and trans[i][1].empty() and trans[i][2].empty());
  for (int i = 0; i < second; i++) dp[i] = INF;
  double ans = go(0);
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  double ans = calc();
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}
