#include <bits/stdc++.h>
const int Inf = 2 * 1000 * 1000 * 1000;
long long LINF = (long long)4e18;
using namespace std;
int cnt[26];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<string> a(n);
  map<int, int> bit;
  vector<int> masks(n);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (auto &c : a[i]) {
      cnt[c - 'a']++;
    }
    int mask = 0;
    for (int j = 0; j < 26; j++) {
      if (cnt[j] & 1) mask |= (1 << j);
    }
    bit[mask]++;
    masks[i] = mask;
    memset(cnt, 0, sizeof(cnt));
  }
  for (int i = 0; i < n; i++) {
    ans += bit[masks[i]] - 1;
    for (int j = 0; j < 26; j++) {
      int tmp = masks[i] ^ (1 << j);
      ans += bit[tmp];
    }
  }
  cout << ans / 2;
  return 0;
}
