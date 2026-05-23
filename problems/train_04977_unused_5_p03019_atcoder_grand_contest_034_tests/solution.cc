#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  do {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  } while (false);
  int n, X;
  cin >> n >> X;
  vector<int> arr(n), L(n), R(n), order(n);
  vector<ll> val(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i] >> L[i] >> R[i];
    val[i] = (ll)arr[i] * L[i] + (ll)(X - arr[i]) * R[i];
    order[i] = i;
  }
  sort(order.begin(), order.end(), [&] (int x, int y) {
    return val[x] > val[y];
  });
  ll goal = 0;
  for (int i = 0; i < n; i++) {
    goal += (ll)arr[i] * L[i];
  }
  int idx = 0;
  while (idx < n && goal > val[order[idx]]) {
    goal -= val[order[idx]];
    idx++;
  }
  ll ans = X;
  for (int i = idx; i < n; i++) {
    if (goal <= (ll)arr[order[i]] * L[order[i]]) {
      ans = min(ans, (goal + L[order[i]] - 1) / L[order[i]]);
    } else {
      ans = min(ans, (goal - (ll)arr[order[i]] * L[order[i]] + R[order[i]] - 1) / R[order[i]] + arr[order[i]]);
    }
  }
  ans += (ll)X * idx;
  if (idx < n) {
    goal -= val[order[idx]];
    for (int i = 0; i < idx; i++) {
      goal += val[order[i]];
      if (goal <= (ll)arr[order[i]] * L[order[i]]) {
        ans = min(ans, (ll)X * idx + (goal + L[order[i]] - 1) / L[order[i]]);
      } else {
        ans = min(ans, (ll)X * idx + (goal - (ll)arr[order[i]] * L[order[i]] + R[order[i]] - 1) / R[order[i]] + arr[order[i]]);
      }
      goal -= val[order[i]];
    }
  }
  cout << ans << endl;
  return 0;
}
