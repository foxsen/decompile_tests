#include <bits/stdc++.h>
using namespace std;
const int max_n = 100000;
const int max_val = 100000;
const int mod = 1000000007;
int mod_val(int a) {
  a %= mod;
  if (a < 0) a += mod;
  return a;
}
int times_mod(int a, int b) {
  long long int x = a;
  x *= b;
  x %= mod;
  return mod_val(x);
}
int power_mod(int a, int b) {
  if (b == 0)
    return 1;
  else if (b == 1)
    return mod_val(a);
  int tmp = power_mod(a, b / 2);
  tmp = times_mod(tmp, tmp);
  if (b % 2)
    return times_mod(tmp, a);
  else
    return tmp;
}
int n;
int a[max_n];
void get_input() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
}
int dist[max_val + 1];
vector<int> divisor[max_val + 1];
void make_dist() {
  for (int i = 0; i <= max_val; i++) dist[i] = 0;
  for (int i = 0; i < n; i++) dist[a[i]]++;
  for (int i = max_val - 1; i >= 0; i--) dist[i] += dist[i + 1];
}
void make_divisor() {
  for (int i = 0; i <= max_val; i++) divisor[i].clear();
  for (int d = 1; d <= max_val; d++)
    for (int v = d; v <= max_val; v += d) divisor[v].push_back(d);
}
int ans;
void process() {
  make_dist();
  make_divisor();
  ans = 1;
  for (int X = 2; X <= max_val; X++) {
    int big = 1;
    int sz = divisor[X].size();
    for (int j = 0; j < sz - 1; j++)
      big = times_mod(
          big, power_mod(j + 1, dist[divisor[X][j]] - dist[divisor[X][j + 1]]));
    big = times_mod(big, power_mod(sz, dist[divisor[X][sz - 1]]));
    int small = 1;
    for (int j = 0; j < sz - 2; j++)
      small = times_mod(small, power_mod(j + 1, dist[divisor[X][j]] -
                                                    dist[divisor[X][j + 1]]));
    small = times_mod(small, power_mod(sz - 1, dist[divisor[X][sz - 2]]));
    ans = mod_val(ans + mod_val(big - small));
  }
}
void print_output() { printf("%d\n", ans); }
int main() {
  get_input();
  process();
  print_output();
  return 0;
}
