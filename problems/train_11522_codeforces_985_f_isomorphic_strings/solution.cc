#include <bits/stdc++.h>
using namespace std;
const long long B = 131;
const long long P = 1e9 + 9;
int n, m;
char s[200000 + 10];
long long h[26][200000 + 10];
long long t[200000 + 10];
long long add(long long a, long long b) { return (a + b) % P; }
long long sub(long long a, long long b) {
  long long c = (a - b) % P;
  if (c < 0) c += P;
  return c;
}
long long mul(long long a, long long b) { return a * b % P; }
bool calc(int x, int y, int len) {
  long long a[26], b[26];
  for (int i = 0; i < 26; i++) {
    a[i] = sub(h[i][x + len - 1], mul(x > 0 ? h[i][x - 1] : 0, t[len]));
    b[i] = sub(h[i][y + len - 1], mul(y > 0 ? h[i][y - 1] : 0, t[len]));
  }
  sort(a, a + 26);
  sort(b, b + 26);
  for (int i = 0; i < 26; i++) {
    if (a[i] != b[i]) return false;
  }
  return true;
}
void solve() {
  t[0] = 1;
  for (int i = 1; i < n; i++) {
    t[i] = mul(t[i - 1], B);
  }
  for (int i = 0; i < 26; i++) {
    h[i][0] = (s[0] == i + 'a');
    for (int j = 1; j < n; j++) {
      h[i][j] = add(mul(h[i][j - 1], B), s[j] == i + 'a');
    }
  }
  for (int x, y, len; m--;) {
    scanf("%d %d %d", &x, &y, &len);
    puts(calc(x - 1, y - 1, len) ? "YES" : "NO");
  }
}
int main() {
  scanf("%d %d %s", &n, &m, s);
  solve();
  return 0;
}
