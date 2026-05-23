#include <bits/stdc++.h>
using namespace std;
template <class T, size_t N>
ostream& operator<<(ostream& os, const array<T, N>& v);
template <class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  bool f = 1;
  os << "[";
  for (auto& i : v) {
    if (!f) os << ", ";
    os << i;
    f = 0;
  }
  return os << "]";
}
template <class T, size_t N>
ostream& operator<<(ostream& os, const array<T, N>& v) {
  bool f = 1;
  os << "[";
  for (auto& i : v) {
    if (!f) os << ", ";
    os << i;
    f = 0;
  }
  return os << "]";
}
template <class T1, class T2>
ostream& operator<<(ostream& os, const set<T1, T2>& v) {
  bool f = 1;
  os << "[";
  for (auto& i : v) {
    if (!f) os << ", ";
    os << i;
    f = 0;
  }
  return os << "]";
}
template <class T1, class T2>
ostream& operator<<(ostream& os, const multiset<T1, T2>& v) {
  bool f = 1;
  os << "[";
  for (auto& i : v) {
    if (!f) os << ", ";
    os << i;
    f = 0;
  }
  return os << "]";
}
template <class T1, class T2, class T3>
ostream& operator<<(ostream& os, const map<T1, T2, T3>& v) {
  bool f = 1;
  os << "[";
  for (auto& ii : v) {
    if (!f) os << ", ";
    os << "(" << ii.first << " -> " << ii.second << ") ";
    f = 0;
  }
  return os << "]";
}
template <class T1, class T2>
ostream& operator<<(ostream& os, const multimap<T1, T2>& v) {
  bool f = 1;
  os << "[";
  for (auto& ii : v) {
    if (!f) os << ", ";
    os << "(" << ii.first << " -> " << ii.second << ") ";
    f = 0;
  }
  return os << "]";
}
template <class T1, class T2>
ostream& operator<<(ostream& os, priority_queue<T1, T2> v) {
  bool f = 1;
  os << "[";
  while (!v.empty()) {
    auto x = v.top();
    v.pop();
    if (!f) os << ", ";
    f = 0;
    os << x;
  }
  return os << "]";
}
template <class T1, class T2>
void printarray(const T1& a, T2 sz, T2 beg = 0) {
  for (T2 i = beg; i < sz; i++) cout << a[i] << " ";
  cout << endl;
}
void cio() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
}
const long long mod = 1e9 + 9;
void die() {
  printf("No\n");
  exit(0);
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
struct segTree {
  int n;
  vector<int> d;
  void init(int x) {
    n = 1;
    while (n < x) n *= 2;
    d.resize(n * 2 + 10, 1);
  }
  void update(int x, int val) {
    x += n - 1;
    d[x] = val;
    for (x >>= 1; x; x >>= 1) d[x] = gcd(d[x * 2], d[x * 2 + 1]);
  }
  int query(int l, int r) {
    int res = -1;
    for (l += n - 1, r += n - 1; l <= r; l >>= 1, r >>= 1) {
      if (l & 1) {
        res = (res == -1) ? d[l] : gcd(res, d[l]);
        l++;
      }
      if (!(r & 1)) {
        res = (res == -1) ? d[r] : gcd(res, d[r]);
        r--;
      }
    }
    return res;
  }
};
map<int, vector<int>> mp;
int p[100500];
int N, Q;
int main() {
  scanf("%d", &N);
  segTree tree;
  tree.init(N);
  for (int i = 1; i <= N; i++) scanf("%d", &p[i]);
  for (int i = 1; i <= N; i++) {
    tree.update(i, p[i]);
    mp[p[i]].push_back(i);
  }
  scanf("%d", &Q);
  while (Q--) {
    int L, R;
    scanf("%d%d", &L, &R);
    int G = tree.query(L, R);
    if (mp.find(G) == mp.end()) {
      printf("%d\n", R - L + 1);
      continue;
    }
    int d = upper_bound(mp[G].begin(), mp[G].end(), R) -
            lower_bound(mp[G].begin(), mp[G].end(), L);
    printf("%d\n", R - L + 1 - d);
  }
}
