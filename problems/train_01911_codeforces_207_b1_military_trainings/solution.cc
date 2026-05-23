#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:60000000")
using namespace std;
template <class T>
T sqr(T x) {
  return x * x;
}
double const pi = 3.1415926535897932384626433832795;
int const inf = (int)1e9;
long long const inf64 = (long long)4e18;
const string name = "b";
const int NMAX = 10010;
int n, num, a[NMAX], ans, zn[NMAX], NEXT[NMAX], st[NMAX], lst[NMAX];
vector<int> seg[NMAX];
int main() {
  cin >> n;
  for (int i = 0; i < (int)n; i++) scanf("%d", &a[i]);
  ans = 0;
  for (int i = 0; i < (int)n; i++) {
    num = 0;
    memset(st, 255, sizeof(st));
    memset(NEXT, 255, sizeof(NEXT));
    for (int j = 0; j < (int)n; j++) {
      zn[num] = j;
      int tmp = max(0, j - a[j]);
      if (st[tmp] == -1)
        st[tmp] = num, lst[tmp] = num;
      else {
        NEXT[lst[tmp]] = num;
        lst[tmp] = num;
      }
      num++;
    }
    int now = 0, idx = 0, last = -1;
    while (idx < n - 1) {
      now++;
      int tmp = idx;
      for (int j = last + 1; j <= tmp; ++j)
        for (int f = st[j]; f != -1; f = NEXT[f]) idx = max(idx, zn[f]);
      last = tmp;
    }
    ans += now;
    for (int j = (int)n - 1; j >= 0; j--) a[j + 1] = a[j];
    a[0] = a[n];
  }
  cout << ans << endl;
  cerr << clock() << endl;
  return 0;
}
