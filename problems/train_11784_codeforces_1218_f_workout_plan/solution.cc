#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  long long int a[n];
  for (int i = 0; i < n; ++i) cin >> a[i];
  long long int A;
  cin >> A;
  long long int temp;
  priority_queue<int, vector<int>, greater<int>> pq;
  long long int ans = 0;
  for (int i = 0; i < n; ++i) {
    cin >> temp;
    pq.push(temp);
    while (k < a[i]) {
      if (pq.empty()) {
        cout << -1;
        return 0;
      }
      k += A;
      ans += pq.top();
      pq.pop();
    }
  }
  cout << ans;
  return 0;
}
