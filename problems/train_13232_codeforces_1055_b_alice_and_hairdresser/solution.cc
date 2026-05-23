#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m, l;
  cin >> n >> m >> l;
  vector<long long> arr(n);
  long long count = 0;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    if (arr[i] > l && (i == 0 || arr[i - 1] <= l) &&
        (i == n - 1 || arr[i + 1] <= l)) {
      count++;
    }
  }
  for (int i = 0; i < m; ++i) {
    int x, pos, y;
    cin >> x;
    if (x) {
      cin >> pos >> y;
      if (arr[pos - 1] <= l && arr[pos - 1] + y > l) {
        if (pos - 2 >= 0 && arr[pos - 2] > l && pos < n && arr[pos] > l) {
          count--;
        } else if ((pos - 1 == 0 || arr[pos - 2] <= l) &&
                   (pos == n || arr[pos] <= l)) {
          count++;
        }
      }
      arr[pos - 1] += y;
    } else {
      cout << count << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cout.setf(ios::fixed);
  cout.precision(9);
  solve();
  return 0;
}
