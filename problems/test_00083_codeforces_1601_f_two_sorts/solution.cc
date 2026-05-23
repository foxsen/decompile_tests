#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &t) {
  t = 0;
  char ch = getchar();
  int f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  do {
    (t *= 10) += ch - '0';
    ch = getchar();
  } while ('0' <= ch && ch <= '9');
  t *= f;
}
template <typename T>
void write(T t) {
  if (t < 0) {
    putchar('-');
    write(-t);
    return;
  }
  if (t > 9) write(t / 10);
  putchar('0' + t % 10);
}
template <typename T>
void writeln(T t) {
  write(t);
  puts("");
}
const int mod = 998244353;
const int mod2 = (1e9) + 7;
long long n, cnt;
int ans, sum[10];
vector<int> vec[10];
void update(int &x, int y) {
  x += y;
  if (x >= mod2) x -= mod2;
}
void dfs1(int dep, int val) {
  if (val > n) return;
  cnt++;
  vec[dep].push_back((cnt - val + mod) % mod);
  if (dep == 6) return;
  for (int i = 0; i < 10; i++) dfs1(dep + 1, val * 10 + i);
}
void dfs2(int dep, long long val) {
  if (val > n) return;
  if (dep >= 1) {
    if ((long long)val * 1000000 > n / 10 &&
        (long long)val * 1000000 + 999999 <= n) {
      long long tmp = val;
      for (int i = 0; i <= 6; i++) {
        int cur = (cnt % mod - tmp % mod + mod) % mod;
        update(ans, (long long)cur * (int)vec[i].size() % mod2);
        int pos =
            vec[i].end() - lower_bound(vec[i].begin(), vec[i].end(), mod - cur);
        update(ans, (sum[i] - (long long)pos * mod % mod2 + mod2) % mod2);
        tmp *= 10;
      }
      for (int i = 0; i <= 6; i++) cnt += (int)vec[i].size();
      return;
    }
    cnt++;
    update(ans, (cnt % mod - val % mod + mod) % mod);
  }
  for (int i = (dep == 0 ? 1 : 0); i < 10; i++)
    dfs2(dep + 1, (long long)val * 10 + i);
}
int main() {
  read(n);
  dfs1(0, 0);
  for (int i = 0; i <= 6; i++) {
    sort(vec[i].begin(), vec[i].end());
    for (int &x : vec[i]) update(sum[i], x);
  }
  cnt = 0;
  dfs2(0, 0);
  printf("%d\n", ans);
  return 0;
}
