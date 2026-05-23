#include <bits/stdc++.h>
using namespace std;
int ab(int x) {
  if (x < 0) return -x;
  return x;
}
int get_bit(int id, int mask) {
  int tmp = 1;
  for (int i = 1; i < id; i++) tmp *= 10;
  return (mask / tmp) % 10;
}
int ltm[5];
vector<int> tmv;
int on_bit(int x, int mask) {
  tmv.clear();
  tmv.push_back(x);
  for (int i = 1; i <= 4; i++) {
    int dum = mask % 10;
    mask /= 10;
    if (dum == 0) continue;
    tmv.push_back(dum);
  }
  sort(tmv.begin(), tmv.end());
  int ret = 0;
  for (int i = 0; i < tmv.size(); i++) {
    ret *= 10;
    ret += tmv[i];
  }
  return ret;
}
const int INF = 1e7;
int n;
int mas[2005];
int kel[2005];
int memo[2002][750][10];
int tmp[5];
int kode[10005];
bool cek(int x) {
  int awal = x;
  for (int i = 0; i < 4; i++) {
    ltm[i] = x % 10;
    x /= 10;
  }
  sort(ltm, ltm + 4);
  int ret = 0;
  for (int i = 0; i < 4; i++) {
    ret *= 10;
    ret += ltm[i];
  }
  return awal == ret;
}
void pre() {
  memset(kode, 0, sizeof(kode));
  int cun = 0;
  for (int i = 0; i < 10000; i++) {
    if (cek(i)) {
      cun++;
      kode[i] = cun;
    }
  }
  return;
}
int dp(int id, int mask, int lt) {
  if (kode[mask] == 0)
    while (1)
      ;
  if (id > n && mask == 0) {
    return 0LL;
  }
  int ret = INF;
  if (memo[id][kode[mask]][lt] != -1) return memo[id][kode[mask]][lt];
  if (mask < 1000 && id <= n) {
    ret = min(
        ret, dp(id + 1, on_bit(kel[id], mask), mas[id]) + ab(lt - mas[id]) + 1);
  }
  int mul = 1;
  for (int i = 1; i <= 4; i++) {
    int now = get_bit(i, mask);
    if (now == 0) continue;
    ret =
        min(ret, dp(id, on_bit(0, mask - (now * mul)), now) + ab(lt - now) + 1);
    mul *= 10;
  }
  return memo[id][kode[mask]][lt] = ret;
}
int main() {
  pre();
  memset(memo, -1, sizeof(memo));
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &mas[i], &kel[i]);
  }
  int ans = dp(1, 0, 1);
  printf("%d\n", ans);
  return 0;
}
