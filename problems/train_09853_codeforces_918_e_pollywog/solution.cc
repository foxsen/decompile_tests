#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <class T>
inline bool setmin(T &a, T b) {
  if (a > b) return a = b, 1;
  return 0;
}
template <class T>
inline bool setmax(T &a, T b) {
  if (a < b) return a = b, 1;
  return 0;
}
template <class T>
inline T fast(T a, T b, T mod) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
template <class T>
istream &operator>>(istream &os, vector<T> &container) {
  for (auto &u : container) os >> u;
  return os;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &container) {
  for (auto &u : container) os << u << " ";
  return os;
}
template <class T>
inline T gcd(T a, T b) {
  while (b) swap(a %= b, b);
  return a;
}
const long long INF = 1e9 + 7;
const long long mod = 998244353;
const long long BIG_INF = 1e18 + 7;
const long long T = 1 << 20;
const long double inf = 1e18;
const long double eps = 1e-12;
long long n, m, q;
vector<vector<long long>> operator*(vector<vector<long long>> a,
                                    vector<vector<long long>> b) {
  vector<vector<long long>> ret(n, vector<long long>(n, BIG_INF));
  for (int i = 0; i < (n); i++)
    for (int j = 0; j < (n); j++)
      for (int k = 0; k < (n); k++)
        ret[i][j] = min(ret[i][j], a[i][k] + b[k][j]);
  return ret;
}
vector<vector<long long>> id(int x) {
  vector<vector<long long>> ret(x, vector<long long>(x, BIG_INF));
  for (int i = 0; i < (x); i++) ret[i][i] = 0;
  return ret;
}
vector<vector<long long>> operator^(vector<vector<long long>> a,
                                    long long pot) {
  vector<vector<long long>> ret = id((int)(a).size());
  while (pot) {
    if (pot & 1) ret = ret * a;
    a = a * a;
    pot /= 2;
  }
  return ret;
}
long long skok[10];
int cnt;
int mapa[300], mapa_rev[300];
vector<pair<long long, long long>> spec;
int X, K, N, Q;
void wypisz(vector<vector<long long>> xd) {
  for (auto &u : xd) {
    for (auto &v : u) {
      cout << (v != BIG_INF ? v : -1) << ' ';
    }
    cout << endl;
  }
}
int special(long long poz) {
  auto x = lower_bound((spec).begin(), (spec).end(), make_pair(poz, -INF));
  if (x != spec.end() and x->first == poz) return x->second;
  return 0;
}
vector<vector<long long>> macierz_przejscia;
void big_jump(vector<long long> &dp, int &poz, int kroki) {
  vector<vector<long long>> pom = macierz_przejscia ^ kroki;
  vector<vector<long long>> sjema(n, vector<long long>(n, BIG_INF));
  sjema[0] = dp;
  sjema = sjema * pom;
  dp = sjema[0];
  poz = poz + kroki;
}
void jump(vector<long long> &dp, int &poz) {
  vector<long long> nowe((int)(dp).size(), BIG_INF);
  for (int i = 0; i < cnt; i++) {
    int maska = mapa_rev[i];
    if (maska & 1) {
      for (int j = 1; j <= K; j++) {
        int bit = (1 << j);
        if (!(maska & bit)) {
          int new_poz = poz + j;
          int nowa_maska = (maska >> 1) + (bit >> 1);
          int id = mapa[nowa_maska];
          nowe[id] = min(nowe[id], dp[i] + skok[j] + special(new_poz));
        }
      }
    } else {
      int nowa_maska = (maska >> 1);
      int id = mapa[nowa_maska];
      nowe[id] = min(nowe[id], dp[i]);
    }
  }
  dp = nowe;
  poz++;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> X >> K >> N >> Q;
  spec.resize(Q);
  for (int i = 1; i <= K; i++) cin >> skok[i];
  for (int i = 0; i < (1 << K); i++) {
    if (__builtin_popcount(i) == X) {
      mapa[i] = cnt;
      mapa_rev[cnt] = i;
      cnt++;
    }
  }
  n = cnt;
  macierz_przejscia =
      vector<vector<long long>>(n, vector<long long>(n, BIG_INF));
  for (int i = 0; i < n; i++) {
    int maska = mapa_rev[i];
    if (maska & 1) {
      for (int j = 1; j <= K; j++) {
        int bit = (1 << j);
        if (!(maska & bit)) {
          int nowa_maska = (maska >> 1) + (bit >> 1);
          int id = mapa[nowa_maska];
          macierz_przejscia[i][id] = skok[j];
        }
      }
    } else {
      int nowa_maska = (maska >> 1);
      int id = mapa[nowa_maska];
      macierz_przejscia[i][id] = 0;
    }
  }
  vector<long long> dp(n);
  fill((dp).begin(), (dp).end(), BIG_INF);
  dp[0] = 0;
  for (int i = 0; i < (Q); i++) cin >> spec[i].first >> spec[i].second;
  spec.push_back({INF, -1337});
  sort((spec).begin(), (spec).end());
  int poz = 1, nast = 0;
  while (poz < N - X + 1) {
    if (spec[nast].first - poz > K) {
      int ile = min(spec[nast].first - poz - K, (long long)N - X + 1 - poz);
      big_jump(dp, poz, ile);
    } else {
      int xd = spec[nast].first - poz;
      for (int j = 0; j < (xd); j++) {
        jump(dp, poz);
        if ((long long)N - X + 1 == poz) {
          break;
        }
      }
      nast++;
    }
  }
  cout << dp[0] << '\n';
}
