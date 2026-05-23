#include <bits/stdc++.h>
using namespace std;
int unluck = 0;
int n, k;
map<int, int> luck;
long long dp[1500][1500];
long long sol = 0;
long long fak[100005];
long long invfak[100005];
long long ste(int x, int y) {
  if (y == 0) return 1;
  if (y % 2 == 0) {
    long long h = ste(x, y / 2) % 1000000007;
    return (h * h) % 1000000007;
  } else
    return (ste(x, y - 1) * x) % 1000000007;
}
void precalc() {
  fak[0] = 1;
  invfak[0] = ste(fak[0], 1000000007 - 2);
  for (int i = 1; i <= n; i++) {
    fak[i] = i * fak[i - 1];
    fak[i] %= 1000000007;
    invfak[i] = ste(fak[i], 1000000007 - 2);
  }
}
bool isLuck(int x) {
  bool t = true;
  while (x > 0) {
    if (x % 10 != 4 && x % 10 != 7) t = false;
    x /= 10;
  }
  return t;
}
long long bc(int n, int k) {
  return (((fak[n] * invfak[k]) % 1000000007) * invfak[n - k]) % 1000000007;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (isLuck(x))
      luck[x]++;
    else
      unluck++;
  }
  precalc();
  int len = luck.size();
  if (len == 0) {
    cout << bc(n, k) << endl;
    return 0;
  }
  int br = 0;
  for (auto x : luck) {
    if (br == 0) {
      dp[br][1] = x.second;
      dp[br][0] = 1;
      br++;
      continue;
    }
    dp[br][0] = 1;
    for (int i = 1; i <= k; i++) {
      dp[br][i] = dp[br - 1][i - 1] * x.second + dp[br - 1][i];
      dp[br][i] %= 1000000007;
    }
    br++;
  }
  for (int i = 0; i <= min(len, k); i++) {
    if (k - i <= unluck) sol += dp[len - 1][i] * bc(unluck, k - i);
    sol %= 1000000007;
  }
  cout << sol << endl;
  return 0;
}
