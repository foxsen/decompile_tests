#include <bits/stdc++.h>
using namespace std;
long long int b[1030][15], arr[1030];
long long int solve(long long int t, long long int j, long long int n) {
  vector<int> st;
  for (int i = 0; i < n; ++i) {
    st.push_back(arr[i] ^ t);
  }
  sort(st.begin(), st.end());
  int flag = 0;
  for (int i = 0; i < n; ++i) {
    if (st[i] != arr[i]) {
      flag = 1;
      break;
    }
  }
  if (flag == 0 && t != 0)
    return t;
  else {
    long long int ans = 1e18;
    for (int i = j + 1; i < 11; ++i) {
      ans = min(ans, solve(t + (long long int)(pow(2, i)), i, n));
    }
    return ans;
  }
}
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr + n);
    for (int i = 0; i < n; ++i) {
      long long int t = arr[i];
      for (int j = 0; j < 11; ++j) {
        b[i][j] = t % 2;
        t /= 2;
      }
    }
    long long int a1 = solve(0, 0, n);
    long long int a2 = solve(1, 0, n);
    if (a1 == 1e18 && a2 == 1e18)
      cout << -1 << endl;
    else if (a1 == 1e18)
      cout << a2 << endl;
    else if (a2 == 1e18)
      cout << a1 << endl;
    else
      cout << min(a1, a2) << endl;
  }
}
