#include <bits/stdc++.h>
using namespace std;
vector<long long> a, b, k;
vector<int> p;
vector<int> action;
int n, u, r;
const long long INFTY = 0x3F003F003F003F00LL;
long long THE_BEST_SUM = -INFTY;
void ggg(int already_performed_ops, const vector<long long>& a_before) {
  if ((u - already_performed_ops) % 2 == 0) {
    long long curr_sum = 0;
    for (int i = 1; i <= n; i++) curr_sum += a_before[i] * k[i];
    if (curr_sum > THE_BEST_SUM) THE_BEST_SUM = curr_sum;
  }
  vector<long long> a_after(a_before);
  if (already_performed_ops < u) {
    if (already_performed_ops == 0 || action[already_performed_ops - 1] != 0) {
      action[already_performed_ops] = 0;
      for (int i = 1; i <= n; i++) a_after[i] ^= b[i];
      ggg(already_performed_ops + 1, a_after);
    }
    action[already_performed_ops] = 1;
    for (int i = 1; i <= n; i++) a_after[i] = a_before[p[i]] + r;
    ggg(already_performed_ops + 1, a_after);
  }
}
int main(int argc, char* argv[]) {
  cin >> n >> u >> r;
  a.resize(n + 1);
  b.resize(n + 1);
  k.resize(n + 1);
  p.resize(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int i = 1; i <= n; i++) cin >> k[i];
  for (int i = 1; i <= n; i++) cin >> p[i];
  action.resize(u);
  ggg(0, a);
  cout << THE_BEST_SUM << endl;
  return 0;
}
