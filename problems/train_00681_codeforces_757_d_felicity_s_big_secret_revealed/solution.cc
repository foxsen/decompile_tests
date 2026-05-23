#include <bits/stdc++.h>
using namespace std;
int n;
long long b[30];
string s;
int mod;
int memo[602222][76];
long long solve(int mask, int i) {
  if (i == n) {
    for (int j = 0; j < 30; j++) {
      if (mask == b[j]) {
        return 1;
      }
    }
    return 0;
  }
  int &ret = memo[mask][i];
  if (ret != -1) return ret;
  int sum = 0;
  for (int j = 0; j < 75; j++) {
    if (i + j <= n) {
      int num = 0;
      for (int k = 0; k < j; k++) {
        num = num * 2 + (s[i + k] - '0');
        if (num > 20) break;
      }
      num -= 1;
      if (num <= 18 && num >= 0) {
        sum += solve(mask | (1 << num), i + j);
        sum %= mod;
        if (i + j != n) sum += solve(mask | (1 << num), n);
      }
      sum = sum % mod;
    }
  }
  ret = sum;
  return sum;
}
int main() {
  memset(memo, -1, sizeof(memo));
  mod = 1e9 + 7;
  for (int j = 0; j < 30; j++) {
    b[j] = (1 << (j + 1)) - 1;
  }
  cin >> n >> s;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += solve(0, i);
    sum %= mod;
  }
  cout << sum << endl;
}
