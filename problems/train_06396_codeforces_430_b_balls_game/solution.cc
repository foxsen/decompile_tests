#include <bits/stdc++.h>
using namespace std;
int a[1234];
int main() {
  int n, k, x;
  cin >> n >> k >> x;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int cnt = 0;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == x and a[i + 1] == x) {
      cnt = 2;
      int right = i + 1;
      right++;
      while (a[right] == x) {
        cnt++;
        right++;
      }
      int left = i - 1;
      ans = max(ans, cnt);
      if (a[left] == a[right] and
          (a[left] == a[left - 1] or a[left] == a[right + 1]) and left >= 1 and
          right <= n) {
        int Y = a[left];
        while (1) {
          while (a[left] == Y and left >= 1) left--, cnt++;
          while (a[right] == Y and right <= n) right++, cnt++;
          if (a[left] == a[right] and
              (a[left] == a[right + 1] or a[left] == a[left - 1]) and
              left >= 1 and right <= n)
            Y = a[left];
          else
            break;
        }
        ans = max(ans, cnt);
      }
    }
  }
  cout << ans;
}
