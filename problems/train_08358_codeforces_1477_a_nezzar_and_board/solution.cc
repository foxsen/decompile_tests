#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c> {i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
  ~debug() { cerr << endl; }
  eni( != ) cerr << boolalpha << i; ris;
}
eni( == ) ris << range(begin(i), end(i));
}
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
  sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
#define int long long

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

void solve() {

  int n, k;
  cin >> n >> k;
  vector<int>a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int g = 0;

  sort(a.begin(), a.end());



  for (int i = 1; i < n; i++) {
    if (i == 1) {
      g = a[i] - a[i - 1];
      continue;
    }
    g = gcd(g, a[i] - a[i - 1]);
  }

  for (int i = 0; i < n; i++) {
    if (a[i] == k) {
      cout << "YES" << endl;
      return;
    }
    if (abs(a[i] - k) % g == 0) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;

}


int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }


}
