#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <complex>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#ifndef LOCAL
#define debug(x) ;
#else
#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;

template <typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}

template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  out << '{';
  for (const T &item : v) out << item << ", ";
  out << "\b\b}";
  return out;
}
#endif

#define mod 998244353 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 200010

ll power(ll k, ll n, int M){
  ll res = 1;
  while(n > 0) {
    if (n & 1) res = res * k % M;
    k = k * k % M;
    n /= 2;
  }
  return res;
}

/* Number Theoretic Transform */

namespace NTT {
  void DFT(int m, int root, vector<int> &a, bool rev = false) {
    int N = a.size();

    for(int i = 0, j = 1; j + 1 < N; j++) {
      for(int k = N >> 1; k > (i ^= k); k >>= 1);
      if(i > j) swap(a[i], a[j]);
    }

    int g = power(root, (mod - 1) / N, mod);
    if (rev) g = power(g, mod - 2, mod);

    for (int i = 1; i < N; i *= 2) {
      int base = power(g, N / i / 2, mod);
      ll w = 1;
      for (int j = 0; j < i; j++) {
        for (int k = 0; k < N; k += i*2) {
          int s = a[j+k], t = a[j+k+i] * w % m;
          a[j+k+0] = (s + t) % m;
          a[j+k+i] = (s - t + m) % m;
        }
        w = w * base % m;
      }
    }

    if (rev) {
      ll tmp = power(N, m-2, m);
      for(int &v : a) v = v * tmp % m;
    }
  }

  // (469762049, 3), (924844033, 5), (998244353, 3), (1012924417, 5)

  vector<int> conv(int _mod, int root, const vector<int> &a, const vector<int> &b) {
    int s = 1, t = a.size() + b.size() - 1;
    while(s < t) s *= 2;

    vector<int> F(s), G(s);
    for(int i = 0; i < (int)a.size(); i++) F[i] = a[i];
    for(int i = 0; i < (int)b.size(); i++) G[i] = b[i];
    DFT(_mod, root, F); DFT(_mod, root, G);

    for(int i = 0; i < s; i++) F[i] = (ll)F[i] * G[i] % _mod;
    DFT(_mod, root, F, true);

    return F;
  }
};

int N;
char S[SIZE];
int U[SIZE], M[SIZE], G[SIZE];

ll solve(int l, int r) {
  ll res = 0;

  if(r - l <= 2) return 0;

  vector<int> a(r-l), b(r-l);

  for(int i=l; i<r; i++) {
    if (i < (l+r)/2)
      a[i-l] = U[i];
    else
      b[i-l] = G[i];
  }

  auto UG = NTT::conv(mod, 5, a, b);

  for(int i=0; i<(r-l); i++) {
    res += (ll)UG[i*2] * M[i + l] % mod;
  }

  res += solve(l, (l+r)/2);
  res += solve((l+r)/2, r);

  return res % mod;
}

int main(){

  scanf("%s", S);
  N = strlen(S);

  int questions = 0;

  for (int i=0; i<N; i++)
    questions += S[i] == '?';

  ll base = power(3, questions, mod);
  ll inv3 = power(3, mod - 2, mod);

  for(int i=0; i<N; i++) {
    if(S[i] == 'U') U[i] = base;
    if(S[i] == 'M') M[i] = 1;
    if(S[i] == 'G') G[i] = 1;

    if(S[i] == '?') {
      U[i] = base * inv3 % mod;
      M[i] = G[i] = inv3;
    }
  }

  int ans = solve(0, N);

  printf("%d\n", ans);

  return 0;
}

