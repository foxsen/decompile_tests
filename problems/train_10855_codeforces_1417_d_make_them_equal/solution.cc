#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 7;
const long long mod = 1e9 + 7;
long long n, k;
long long a[N];
struct node {
  long long i, j, w;
  node(long long a, long long b, long long c) {
    i = a;
    j = b;
    w = c;
  }
};
struct node2 {
  long long i, x, w;
  node2(long long ii, long long xx, long long ww) {
    i = ii;
    x = xx;
    w = ww;
  }
};
vector<node> vt;
vector<node2> vt2;
bool cmp(node2 a1, node2 a2) {
  if (a1.w == a2.w) {
    return a1.x > a2.x;
  }
  return a1.w < a2.w;
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    vt.clear();
    vt2.clear();
    cin >> n;
    long long sum = 0;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    if (sum % n != 0) {
      cout << -1 << endl;
      continue;
    }
    long long ave = sum / n;
    for (long long i = 2; i <= n; i++) {
      if (a[i] % i) {
        vt.push_back(node(1, i, i - a[i] % i));
      }
      vt.push_back(node(i, 1, (a[i] + i - 1) / i));
    }
    for (long long i = 2; i <= n; i++) {
      vt.push_back(node(1, i, ave));
    }
    cout << vt.size() << endl;
    for (long long i = 0; i < vt.size(); i++) {
      cout << vt[i].i << " " << vt[i].j << " " << vt[i].w << endl;
    }
  }
  return 0;
}
