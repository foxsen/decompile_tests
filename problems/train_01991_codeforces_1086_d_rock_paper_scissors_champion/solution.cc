#include <bits/stdc++.h>
using namespace std;
inline long long mod(long long n, long long m) {
  long long ret = n % m;
  if (ret < 0) ret += m;
  return ret;
}
long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b)); }
long long exp(long long a, long long b, long long m) {
  if (b == 0) return 1;
  if (b == 1) return mod(a, m);
  long long k = mod(exp(a, b / 2, m), m);
  if (b & 1) {
    return mod(a * mod(k * k, m), m);
  } else
    return mod(k * k, m);
}
struct Bit {
  vector<long long> BIT;
  long long N;
  Bit() {}
  Bit(long long n) {
    BIT.resize(n + 100, 0);
    N = n + 10;
  }
  void update(long long x, long long v) {
    while (x < N) {
      BIT[x] += v;
      x += (x & -x);
    }
  }
  long long sum(long long x) {
    long long r = 0;
    while (x > 0) {
      r += BIT[x];
      x -= (x & -x);
    }
    return r;
  }
  long long query(long long l, long long r) { return sum(r) - sum(l - 1); }
};
long long mat[200100];
set<long long> S[3];
vector<Bit> BIT;
void upd(long long pos, long long c, long long f) {
  if (f) {
    BIT[c].update(pos, 1);
    S[c].insert(pos);
  } else {
    long long last = mat[pos];
    BIT[last].update(pos, -1);
    S[last].erase(pos);
    mat[pos] = c;
    BIT[c].update(pos, 1);
    S[c].insert(pos);
  }
}
long long n, q;
void ask() {
  for (long long i = 0; i < 3; i++) {
    if (S[i].size() == 0) {
      if (i == 2) {
        cout << S[1].size() << "\n";
        return;
      }
      if (i == 0) {
        if (S[2].size() == 0) {
          cout << S[1].size() << "\n";
        } else
          cout << S[2].size() << "\n";
        return;
      }
      if (i == 1) {
        cout << S[0].size() << "\n";
        return;
      }
      return;
    }
  }
  long long res = n;
  for (long long i = 0; i < 3; i++) {
    if (i == 0) {
      long long l = *S[1].begin();
      long long r = *S[2].begin();
      if (l <= r) res -= BIT[i].query(l, r);
      r = *S[1].rbegin();
      l = *S[2].rbegin();
      if (l <= r) res -= BIT[i].query(l, r);
    }
    if (i == 1) {
      long long l = *S[2].begin();
      long long r = *S[0].begin();
      if (l <= r) res -= BIT[i].query(l, r);
      r = *S[2].rbegin();
      l = *S[0].rbegin();
      if (l <= r) res -= BIT[i].query(l, r);
    }
    if (i == 2) {
      long long l = *S[0].begin();
      long long r = *S[1].begin();
      if (l <= r) res -= BIT[i].query(l, r);
      r = *S[0].rbegin();
      l = *S[1].rbegin();
      if (l <= r) res -= BIT[i].query(l, r);
    }
  }
  cout << res << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> q;
  map<char, long long> mp;
  mp['P'] = 0;
  mp['S'] = 1;
  mp['R'] = 2;
  BIT = vector<Bit>(3);
  for (long long i = 0; i < 3; i++) {
    BIT[i] = Bit(n);
    for (long long j = 0; j < n + 10; j++) {
      BIT[i].BIT[j] = 0;
    }
  }
  for (long long i = 1; i <= n; i++) {
    char cc;
    cin >> cc;
    mat[i] = mp[cc];
    upd(i, mat[i], 1);
  }
  ask();
  while (q--) {
    long long p;
    char cc;
    cin >> p >> cc;
    long long c = mp[cc];
    upd(p, c, 0);
    ask();
  }
}
