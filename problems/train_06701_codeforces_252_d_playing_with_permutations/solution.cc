#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int32_t x;
  scanf("%d", &x);
  return x;
}
inline string get() {
  char ch[1001000];
  scanf("%s", ch);
  return ch;
}
const long long maxn = 1e6 + 10;
const long long base = 29;
const long long MAX_LG = 21;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long maxq = 2e5 + 10;
long long p[maxn], q[maxn], t[maxn], s[maxn], res1, res2;
long long n, k;
inline long long doJob(bool id = 0) {
  long long ret = -1;
  for (long long i = 0; i <= k; i++) {
    bool fl = true;
    for (long long j = 0; j < n; j++) fl &= (p[j] == s[j]);
    if (fl) {
      ret = i;
      break;
    }
    if (!id)
      for (long long j = 0; j < n; j++) t[j] = p[q[j] - 1];
    else
      for (long long j = 0; j < n; j++) t[q[j] - 1] = p[j];
    for (long long j = 0; j < n; j++) p[j] = t[j];
  }
  if ((k - ret) % 2) ret = -1;
  return ret;
}
int32_t main() {
  n = in(), k = in();
  for (long long i = 0; i < n; i++) q[i] = in();
  for (long long i = 0; i < n; i++) s[i] = in();
  for (long long i = 1; i <= n; i++) p[i - 1] = i;
  res1 = doJob();
  for (long long i = 1; i <= n; i++) p[i - 1] = i;
  res2 = doJob(1);
  if (!res1 || (res1 == -1 && res2 == -1) || (res1 == 1 && res2 == 1 && k != 1))
    return cout << "NO", 0;
  return cout << "YES", 0;
}
