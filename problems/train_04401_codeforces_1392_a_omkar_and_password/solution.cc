#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, -1, 1, 1, -1};
inline int nxt() {
  int a;
  scanf("%d", &a);
  return a;
}
inline long long int NXT() {
  long long int a;
  scanf("%lld", &a);
  return a;
}
template <typename T>
string NumberToString(T Number) {
  ostringstream second;
  second << Number;
  return second.str();
}
template <class T>
inline T bigmod(T p, T e, T m) {
  T ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % m;
    p = (p * p) % m;
  }
  return (T)ret;
}
template <class T>
inline T biton(T n, T pos) {
  return n | ((T)1 << pos);
}
template <class T>
inline T bitoff(T n, T pos) {
  return n & ~((T)1 << pos);
}
template <class T>
inline T bitcheck(T n, T pos) {
  return (bool)(n & ((T)1 << pos));
}
template <class T>
inline T gcd(T a, T b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
void solve() {
  int n = nxt();
  int last = -1;
  bool allSame = true;
  for (int i = 0; i < n; i++) {
    int x = nxt();
    if (i == 0)
      last = x;
    else {
      if (x != last) allSame = false;
    }
  }
  cout << (allSame ? n : 1) << endl;
}
int main() {
  int t = nxt();
  while (t--) {
    solve();
  }
  return 0;
}
