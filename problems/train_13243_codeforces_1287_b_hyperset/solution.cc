#include <bits/stdc++.h>
using namespace std;
bool *Seive(long long n, bool *p) {
  memset(p, 1, sizeof(p));
  long long i, j;
  for (i = 2; i <= n; i++) {
    if (p[i] == 1)
      for (j = i * i; j <= n; j += i) {
        p[j] = 0;
      }
  }
  p[1] = 0;
  return p;
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long modexp(long long x, long long y) {
  if (y == 0)
    return 1;
  else if (y % 2 == 0) {
    return modexp((x * x) % (long long)998244353, y / 2);
  } else {
    return (x * modexp((x * x) % (long long)998244353, (y - 1) / 2)) %
           (long long)998244353;
  }
}
long long fact(long long n) {
  long long f = 1;
  for (long long i = 2; i <= n; i++) {
    f = (i % (long long)998244353 * f % (long long)998244353) %
        (long long)998244353;
  }
  return f;
}
long long nCr(long long n, long long r) {
  return (fact(n) * modexp((fact(n - r) * fact(r)) % (long long)998244353,
                           (long long)998244353 - 2)) %
         (long long)998244353;
}
void showlist(list<int64_t> g) {
  list<int64_t>::iterator it;
  for (it = g.begin(); it != g.end(); ++it) cout << *it << " ";
  cout << '\n';
}
void swap(int64_t &a, int64_t &b) {
  int64_t t;
  t = a;
  a = b;
  b = t;
}
void build(int64_t l, int64_t r, int64_t i) {
  if (l == r) {
  } else {
    int64_t mid = (l + r) / 2;
    build(l, mid, 2 * i);
    build(mid + 1, r, 2 * i + 1);
  }
}
void update(int64_t p, int64_t l, int64_t r, int64_t i) {
  if (l == r) {
  } else {
    int64_t mid = (l + r) / 2;
    if (p <= mid) {
      update(p, l, mid, 2 * i);
    } else {
      update(p, mid + 1, r, 2 * i + 1);
    }
  }
}
void query(int64_t y, int64_t z, int64_t l, int64_t r, int64_t i) {
  if (y <= l && z >= r) {
  } else {
    int64_t mid = (l + r) / 2;
    if (z <= mid) {
      query(y, z, l, mid, 2 * i);
    } else if (y > mid) {
      query(y, z, mid + 1, r, 2 * i + 1);
    } else {
      query(y, z, l, mid, 2 * i);
      query(y, z, mid + 1, r, 2 * i + 1);
    }
  }
}
void make_set(int64_t v) {}
int64_t find_set(int64_t v) {}
void union_sets(int64_t a, int64_t b) {}
int64_t dfs(int64_t r, int64_t *d, int64_t &e, int64_t l,
            vector<vector<int64_t>> &adj, int64_t *v, int64_t a[][2]) {
  a[r][1] = e + d[r];
  e = a[r][1];
  l = e;
  int64_t j = 0;
  for (int64_t i = 0; i < adj[r].size(); i++) {
    if (v[adj[r][i]] == 0) {
      v[adj[r][i]] = 1;
      a[adj[r][i]][0] = l - (j + 1);
      dfs(adj[r][i], d, e, l, adj, v, a);
      j++;
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int64_t n, k, i, j, w;
  cin >> n >> k;
  string s;
  set<string> g;
  for (i = 0; i < n; i++) {
    cin >> s;
    g.insert(s);
  }
  vector<string> v;
  for (auto it = g.begin(); it != g.end(); it++) {
    v.push_back(*it);
  }
  int64_t sum = 0;
  for (i = 0; i < n - 2; i++) {
    string q;
    q = v[i];
    set<string> t;
    for (j = i + 1; j < n; j++) {
      t.insert(v[j]);
    }
    for (j = i + 1; j < n; j++) {
      string z;
      z = v[j];
      string d;
      for (w = 0; w < k; w++) {
        if (q[w] == z[w]) {
          d += q[w];
        } else {
          char a;
          if (q[w] == 'S' && z[w] == 'T' || z[w] == 'S' && q[w] == 'T') {
            a = 'E';
          } else if (q[w] == 'E' && z[w] == 'T' || z[w] == 'E' && q[w] == 'T') {
            a = 'S';
          } else if (q[w] == 'E' && z[w] == 'S' || z[w] == 'E' && q[w] == 'S') {
            a = 'T';
          }
          d += a;
        }
      }
      if (t.find(d) != t.end()) {
        sum++;
        t.erase(d);
        t.erase(z);
      } else {
        t.erase(z);
      }
    }
  }
  cout << sum << "\n";
  return 0;
}
