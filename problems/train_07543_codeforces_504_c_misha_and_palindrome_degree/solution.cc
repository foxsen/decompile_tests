#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], cnt[N];
int n;
bool isPali() {
  for (int i = 1; i <= n; i++) {
    if (a[i] != a[n + 1 - i]) return false;
  }
  return true;
}
bool canPali() {
  int odd = 0;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] & 1) odd++;
  }
  return (n & 1) ? (odd <= 1) : (odd == 0);
}
bool ck(int x, int pos) {
  int mid = (1 + n) / 2;
  for (int i = mid; i > x; i--) {
    if (a[i] != a[n + 1 - i]) return false;
  }
  memset(cnt, 0, sizeof cnt);
  for (int i = pos; i <= x; i++) {
    cnt[a[i]]++;
  }
  for (int i = max(n + 1 - x, x + 1); i <= n + 1 - pos; i++) {
    cnt[a[i]]--;
  }
  for (int i = 1; i <= n; i++) {
    if (cnt[i] < 0) return false;
  }
  return true;
}
long long solve(int pos) {
  int l = pos, r = n + 1 - pos, ans;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ck(mid, pos)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return (long long)pos * (n + 1 - ans);
}
long long solve() {
  int pos = 1;
  for (int i = 1; i <= n; i++) {
    if (a[i] != a[n + 1 - i]) {
      pos = i;
      break;
    }
  }
  long long ans = -(long long)(pos) * (pos);
  ans += solve(pos);
  reverse(a + 1, a + n + 1);
  ans += solve(pos);
  return ans;
}
int main() {
  while (scanf("%d", &n) == 1) {
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      cnt[a[i]]++;
    }
    if (isPali()) {
      printf("%I64d\n", (long long)n * (n + 1) / 2);
    } else if (!canPali()) {
      puts("0");
    } else {
      printf("%I64d\n", solve());
    }
  }
  return 0;
}
