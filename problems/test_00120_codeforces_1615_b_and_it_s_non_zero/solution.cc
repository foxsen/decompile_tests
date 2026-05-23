#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
using pii = pair<int, int>;
using vec = vector<int>;
using veg = vector<pii>;
template <typename T>
T read() {
  T x = 0;
  bool f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
  return f ? -x : x;
}
template <typename T>
void chkmax(T &x, const T &y) {
  x = x > y ? x : y;
}
template <typename T>
void chkmin(T &x, const T &y) {
  x = x < y ? x : y;
}
const int N = 3e5 + 10;
const int V = 2e5 + 10;
int s[25][N];
void solve() {
  int l = read<int>(), r = read<int>(), ans = 0;
  for (int i = (0); i <= (20); i++) {
    chkmax(ans, s[i][r] - s[i][l - 1]);
  }
  printf("%d\n", r - l + 1 - ans);
}
int main() {
  for (int i = (0); i <= (20); i++)
    for (int j = (1); j <= (V); j++) s[i][j] = s[i][j - 1] + (j >> i & 1);
  int T = read<int>();
  while (T--) solve();
  return 0;
}
