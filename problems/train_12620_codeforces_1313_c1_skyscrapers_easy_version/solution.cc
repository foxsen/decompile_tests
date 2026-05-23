#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> v(n + 2);
  for (long long int i = 1; i < (n + 1); i++) cin >> v[i];
  vector<long long int> left(n + 1), right(n + 2);
  vector<long long int> h;
  h.push_back(0);
  for (long long int i = 1; i < (n + 1); i++) {
    while (v[h.back()] > v[i]) {
      h.pop_back();
    }
    left[i] = left[h.back()] + (i - h.back()) * v[i];
    h.push_back(i);
  }
  h = vector<long long int>(0);
  h.push_back(n + 1);
  for (long long int i = n; i >= (1); i--) {
    while (v[h.back()] > v[i]) {
      h.pop_back();
    }
    right[i] = right[h.back()] + (h.back() - i) * v[i];
    h.push_back(i);
  }
  long long int best = 1, sum = 0;
  for (long long int i = 1; i < (n + 1); i++) {
    if (left[i] + right[i] - v[i] > sum) {
      sum = left[i] + right[i] - v[i];
      best = i;
    }
  }
  vector<long long int> ans = v;
  for (long long int i = best - 1; i >= (1); i--) {
    ans[i] = min(ans[i + 1], v[i]);
  }
  for (long long int i = best + 1; i < (n + 1); i++) {
    ans[i] = min(ans[i - 1], v[i]);
  }
  for (long long int i = 1; i < (n + 1); i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int t;
  t = 1;
  while (t--) solve();
  return 0;
}
