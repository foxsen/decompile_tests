#include <bits/stdc++.h>
using namespace std;
long long sum;
long long a[1000000], ans[1000000];
long n;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sum = 0;
  for (int i = n; i >= 1; i--) {
    if (sum > 0) {
      sum -= a[i];
      ans[i] = 0;
    } else {
      sum += a[i];
      ans[i] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (ans[i] == 0 && sum >= 0)
      cout << '-';
    else if (ans[i] != 0 && sum < 0)
      cout << '-';
    else
      cout << '+';
  }
}
