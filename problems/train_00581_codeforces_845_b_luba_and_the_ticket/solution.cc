#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9 + 7;
const int N = 1e5 + 5;
long long n, k;
long long A[N], B[N];
int main() {
  long long i, j, ans = inf, cnt, a = 0, b = 0, l;
  string s, t;
  cin >> s;
  for (i = 0; i < 6; i++) A[i] = s[i] - '0';
  for (i = 0; i < 3; i++) a += A[i];
  for (i = 3; i < 6; i++) b += A[i];
  if (a > b) {
    k = 1;
    swap(a, b);
  }
  multiset<long long> st[2];
  for (i = 3; i < 6; i++) st[1 - k].insert(A[i]);
  for (i = 0; i < 3; i++) st[k].insert(A[i]);
  while (a < b) {
    long long c, d;
    c = *st[0].begin();
    d = *st[1].rbegin();
    if (9 - c > d) {
      a += 9 - c;
      st[0].erase(st[0].begin());
    } else {
      a += d;
      st[1].erase(st[1].find(d));
    }
    ans++;
  }
  cout << ans - inf;
}
