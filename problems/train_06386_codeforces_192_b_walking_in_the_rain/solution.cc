#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e3 + 10, INF = 1e18;
int T, c_;
long long int n, a[N], visited[N];
bool check(int days) {
  int i = 0;
  while (i < n) {
    if (a[i] < days) {
      return false;
    }
    if (i + 2 < n && a[i + 2] >= days)
      i += 2;
    else if (i + 1 < n && a[i + 1] >= days)
      i++;
    else
      break;
  }
  return i == n - 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int low = 0, hi = 1e3 + 5;
  while (hi - low > 1) {
    int mid = (hi + low) / 2;
    if (check(mid)) {
      low = mid;
    } else
      hi = mid;
  }
  cout << low;
}
