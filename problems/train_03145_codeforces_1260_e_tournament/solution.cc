#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n;
  cin >> n;
  long long int log = log2(n), rem;
  rem = log;
  vector<long long int> arr(n);
  for (long long int i = 0; i < n; i++) cin >> arr[i];
  reverse((arr).begin(), (arr).end());
  while (arr.back() != -1) arr.pop_back();
  arr.pop_back();
  reverse((arr).begin(), (arr).end());
  long long int win = n - arr.size();
  while (win > 1) {
    rem--;
    win /= 2;
  }
  if (arr.size() == 0) {
    cout << 0;
    return 0;
  }
  long long int ans = 0;
  long long int lose = n / 2;
  priority_queue<long long int, vector<long long int>, greater<long long int>>
      Q;
  Q.push(arr.back());
  arr.pop_back();
  while (rem > 0) {
    ans += Q.top();
    Q.pop();
    for (long long int i = 0; i < lose && !arr.empty(); i++) {
      Q.push(arr.back());
      arr.pop_back();
    }
    lose /= 2;
    rem--;
  }
  cout << ans;
}
