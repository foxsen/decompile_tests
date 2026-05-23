#include <bits/stdc++.h>
using namespace std;
template <class T>
void _print(T t) {
  cerr << t;
}
template <class T>
void _print(array<T, 2> p) {
  cerr << "(";
  _print(p[0]);
  cerr << ",";
  _print(p[1]);
  cerr << ")";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    cerr << "{";
    _print(i.first);
    cerr << ":";
    _print(i.second);
    cerr << "} ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "{ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "}";
}
template <class T>
void _print(unordered_set<T> v) {
  cerr << "{ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "}";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "{ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "}";
}
const long long MOD = 1e9 + 7;
long long pow(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) (res *= x) %= MOD;
    (x *= x) %= MOD, y >>= 1;
  }
  return res;
}
void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  vector<int> B(n + 1, 0);
  vector<int> C, D;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    if (A[i] > n) {
      C.push_back(A[i]);
    } else if (B[A[i]]) {
      C.push_back(A[i]);
    } else {
      B[A[i]] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (B[i]) continue;
    D.push_back(i);
  }
  sort(C.begin(), C.end());
  int m = (int)C.size();
  for (int i = 0; i < m; i++) {
    int k = C[i] - D[i];
    if (C[i] % k != D[i]) {
      cout << "-1\n";
      return;
    }
  }
  cout << m << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    solve();
  }
  return 0;
}
