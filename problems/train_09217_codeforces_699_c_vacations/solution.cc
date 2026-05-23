#include <bits/stdc++.h>
using namespace std;
const int Max_N = 105;
int n, a[Max_N], mem[Max_N][3];
int solve(int ind, int prev) {
  if (ind == n) return 0;
  int &ret = mem[ind][prev];
  if (ret != -1) return ret;
  ret = 1 << 29;
  if (a[ind] == 0) {
    ret = 1 + solve(ind + 1, 0);
  } else if (a[ind] == 1) {
    if (prev == 1) {
      ret = solve(ind + 1, 0) + 1;
    } else {
      ret = min(solve(ind + 1, 1), 1 + solve(ind + 1, 0));
    }
  } else if (a[ind] == 2) {
    if (prev == 2) {
      ret = solve(ind + 1, 0) + 1;
    } else {
      ret = min(solve(ind + 1, 2), 1 + solve(ind + 1, 0));
    }
  } else {
    if (prev == 1) {
      ret = min(solve(ind + 1, 2), 1 + solve(ind + 1, 0));
    } else if (prev == 2) {
      ret = min(solve(ind + 1, 1), 1 + solve(ind + 1, 0));
    } else {
      ret = min(solve(ind + 1, 1), solve(ind + 1, 2));
    }
  }
  return ret;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  memset(mem, -1, sizeof mem);
  cout << solve(0, 0) << endl;
  return 0;
}
