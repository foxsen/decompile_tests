#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<long long int> arr[26];
  for (int i = 0; i < n; i++) {
    arr[s[i] - 97].push_back(i);
  }
  int t;
  cin >> t;
  while (t--) {
    string k;
    cin >> k;
    long long int cnt[26];
    int ans;
    ans = 0;
    for (int i = 0; i < 26; i++) {
      cnt[i] = 0;
    }
    for (int i = 0; i < k.length(); i++) {
      cnt[k[i] - 97] = cnt[k[i] - 97] + 1;
    }
    for (int i = 0; i < k.length(); i++) {
      int a = arr[k[i] - 97][cnt[k[i] - 97] - 1];
      ans = std::max(ans, a);
    }
    cout << ans + 1 << '\n';
  }
}
