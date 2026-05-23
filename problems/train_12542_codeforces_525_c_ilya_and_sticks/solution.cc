#include <bits/stdc++.h>
using namespace std;
bool comp(int a, int b) { return a < b; }
int main() {
  int n, i;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  long long int ans = 0;
  sort(a, a + n, comp);
  vector<int> arr;
  for (i = n - 1; i > 0; i--) {
    if (a[i] - a[i - 1] < 2) {
      arr.push_back(a[i - 1]);
      i--;
    }
  }
  if (arr.size() < 2) {
    cout << ans << endl;
    return 0;
  }
  for (i = 0; i < arr.size() - 1; i += 2) {
    ans += (long long int)arr[i] * arr[i + 1];
  }
  cout << ans << endl;
  return 0;
}
