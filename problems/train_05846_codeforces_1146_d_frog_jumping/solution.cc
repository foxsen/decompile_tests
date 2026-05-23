#include <bits/stdc++.h>
using namespace std;
long long m, a, b, d, x = 0;
long long repeat[100100];
long long sum(long long n) { return n * (n + 1) / 2; }
long long get(long long x, long long mod) {
  long long ans = 0;
  long long y = (x - mod) / a + 1;
  long long nxt = y * a + mod - 1;
  nxt = min(nxt, m);
  ans += (nxt - x + 1) * y;
  long long k = (m - mod) / a;
  if (k < y) return ans;
  ans += a * (sum(k) - sum(y)) + (m - k * a - mod + 1) * (k + 1);
  return ans;
}
int main() {
  cin >> m >> a >> b;
  long long initial = 0;
  memset(repeat, -1, sizeof repeat);
  while (repeat[initial % a] == -1) {
    repeat[initial % a] = x;
    while (initial < b && initial + a <= m) initial += a;
    x = max(x, initial);
    if (initial < b) break;
    initial -= b;
  }
  long long rez = 0;
  for (int i = 0; i < a; ++i)
    if (repeat[i] != -1) rez += get(repeat[i], i);
  cout << rez;
}
