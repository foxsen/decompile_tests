#include <bits/stdc++.h>
using namespace std;
int n, k;
string str;
int solve() {
  int left = -1, cnt = 0, ans = 0;
  for (int right = 0; right < n; right++) {
    cnt += (str[right] == 'b');
    while (left <= right && cnt > k) cnt -= (str[++left] == 'b');
    ans = max(ans, right - left);
  }
  return ans;
}
int main() {
  cin >> n >> k >> str;
  int ans = solve();
  for (auto &c : str) c = c ^ 'a' ^ 'b';
  cout << max(ans, solve()) << endl;
}
