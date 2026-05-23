#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  while (TESTS--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
      if (s[i] == '-')
        ans--;
      else
        ans++;
      long long c = 0;
      ans = max(c, ans);
    }
    cout << ans;
  }
  return 0;
}
