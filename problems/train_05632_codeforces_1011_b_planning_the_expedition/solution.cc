#include <bits/stdc++.h>
using namespace std;
const int N = 500500;
const long long INF = (1e17) + 777;
const int mod = (1e9) + 7;
int n, k, x, cnt[N];
vector<int> v;
int main() {
  ios_base::sync_with_stdio(0);
  ;
  cin >> k >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    cnt[x]++;
  }
  for (int i = 1; i <= 100; i++) {
    if (cnt[i] == 0)
      continue;
    else
      v.push_back(cnt[i]);
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  for (int j = 100; j >= 1; j--) {
    int ans = 0;
    for (int i = 0; i < v.size(); i++) ans += v[i] / j;
    if (ans >= k) {
      cout << j;
      return 0;
    }
  }
  cout << 0;
  return 0;
}
