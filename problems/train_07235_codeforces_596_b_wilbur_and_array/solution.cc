#include <bits/stdc++.h>
using namespace std;
long long arr[200099];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  long long k = 0, ans = 0;
  ans = k = abs(arr[0]);
  for (int i = 1; i < n; i++) {
    ans += abs(arr[i] - arr[i - 1]);
  }
  cout << ans << endl;
}
