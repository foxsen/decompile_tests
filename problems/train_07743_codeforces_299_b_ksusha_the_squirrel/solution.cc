#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("fma")
using namespace std;
vector<long long> ttr;
void tree_build(vector<int> &a, int v, int tl, int tr) {
  if (tl == tr)
    ttr[v] = a[tl];
  else {
    int tm = (tl + tr) / 2;
    tree_build(a, v * 2, tl, tm);
    tree_build(a, v * 2 + 1, tm + 1, tr);
    ttr[v] = ttr[v * 2] + ttr[v * 2 + 1];
  }
}
long long tree_sum(int v, int tl, int tr, int l, int r) {
  if (l > r) return 0;
  if (l == tl && r == tr) return ttr[v];
  int tm = (tl + tr) / 2;
  return tree_sum(v * 2, tl, tm, l, min(r, tm)) +
         tree_sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}
void tree_update(int v, int tl, int tr, int pos, int new_val) {
  if (tl == tr)
    ttr[v] = new_val;
  else {
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      tree_update(v * 2, tl, tm, pos, new_val);
    else
      tree_update(v * 2 + 1, tm + 1, tr, pos, new_val);
    ttr[v] = ttr[v * 2] + ttr[v * 2 + 1];
  }
}
long long binpow(long long a, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res *= a;
    a *= a;
    n >>= 1;
  }
  return res;
}
bool prime(long long n) {
  for (long long i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int gcd(int a, int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  set<int> a, b;
  int n, k;
  std::cin >> n >> k;
  string s;
  std::cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == '.') {
      a.insert(i);
    } else {
      b.insert(i);
    }
  }
  set<int>::iterator it;
  if (b.size() == 0) {
    std::cout << "YES";
  } else {
    bool flag = false;
    int temp = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '#') {
        it = a.upper_bound(i);
        if (*it - temp > k) {
          flag = true;
          break;
        }
      } else {
        temp = i;
      }
    }
    if (flag) {
      std::cout << "NO";
    } else {
      std::cout << "YES";
    }
  }
}
