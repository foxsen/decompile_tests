#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, A, B;
  cin >> n >> A >> B;
  vector<long long> v(n);
  for (int(i) = 0; (i) < (n); ++i) cin >> v[i];
  long long sum = accumulate(v.begin(), v.end(), 0);
  long long flow = A * v[0] / sum;
  int ans = 0;
  sort(v.begin() + 1, v.end());
  reverse(v.begin() + 1, v.end());
  int i = 1;
  while (flow < B) {
    sum -= v[i];
    ans++;
    ++i;
    flow = A * v[0] / sum;
  }
  cout << ans << '\n';
  return 0;
}
