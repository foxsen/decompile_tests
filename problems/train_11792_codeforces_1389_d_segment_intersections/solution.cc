#include <bits/stdc++.h>
using namespace std;
void Solve() {
  int n, k;
  cin >> n >> k;
  int l1, r1, l2, r2;
  cin >> l1 >> r1 >> l2 >> r2;
  if (l1 > l2) {
    swap(l1, l2);
    swap(r1, r2);
  }
  vector<int> need(2, 0);
  long long exist_is = 0;
  int is = 0;
  if (l2 >= r1) {
    need[0] = l2 - r1;
    need[1] = r2 - l1;
  } else {
    need[0] = 0;
    need[1] = abs(l2 - l1) + abs(r2 - r1);
    exist_is = min(r1, r2) - max(l1, l2);
  }
  exist_is = exist_is * 1LL * n;
  if (exist_is >= k) {
    printf("0\n");
    return;
  }
  int left = k - (int)exist_is;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (left == 0) {
      break;
    }
    long long this_step = need[0];
    int cut = min(need[1], left);
    this_step += cut;
    if (i >= 1) {
      if (cut * 2LL < this_step) {
        break;
      }
    }
    ans += this_step;
    left -= cut;
  }
  if (left > 0) {
    ans += (left * 2LL);
  }
  printf("%lld\n", ans);
}
int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    Solve();
  }
  return 0;
}
