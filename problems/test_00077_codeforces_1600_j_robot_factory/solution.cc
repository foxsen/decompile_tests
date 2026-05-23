#include <bits/stdc++.h>
using namespace std;
void solve(long long int** arr, long long int** ans, long long int i,
           long long int j, long long int n, long long int m, long long int x) {
  if (i == n || j == m || i < 0 || j < 0) {
    return;
  }
  if (ans[i][j] != -1)
    return;
  else {
    ans[i][j] = x;
    if ((arr[i][j] & 4) == 0 && (arr[i][j + 1] & 1) == 0) {
      solve(arr, ans, i, j + 1, n, m, x);
    }
    if ((arr[i][j] & 2) == 0 && (arr[i + 1][j] & 8) == 0) {
      solve(arr, ans, i + 1, j, n, m, x);
    }
    if ((arr[i][j] & 8) == 0 && (i - 1 >= 0) && (arr[i - 1][j] & 2) == 0) {
      solve(arr, ans, i - 1, j, n, m, x);
    }
    if ((arr[i][j] & 1) == 0 && (j - 1 >= 0) && (arr[i][j - 1] & 4) == 0)
      solve(arr, ans, i, j - 1, n, m, x);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, m;
  cin >> n >> m;
  long long int** arr = new long long int*[n];
  long long int** ans = new long long int*[n];
  for (long long int i = 0; i < n; i++) {
    arr[i] = new long long int[m];
    ans[i] = new long long int[m];
    for (long long int j = 0; j < m; j++) {
      cin >> arr[i][j];
      ans[i][j] = -1;
    }
  }
  long long int x = 0;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      if (ans[i][j] == -1) {
        solve(arr, ans, i, j, n, m, x);
        x++;
      }
    }
  }
  map<long long int, long long int> mp;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) mp[ans[i][j]]++;
  }
  map<long long int, long long int>::iterator it;
  it = mp.begin();
  vector<long long int> v;
  while (it != mp.end()) {
    v.push_back(it->second);
    it++;
  }
  sort(v.begin(), v.end());
  for (long long int i = v.size() - 1; i >= 0; i--) cout << v[i] << " ";
}
