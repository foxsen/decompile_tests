#include <bits/stdc++.h>
using namespace std;
long long mod2 = 1e9 + 7;
long long mod = 998244353;
const long long N = 2e3 + 12;
bool vis[2005][2005];
int n, k, a[10][2005];
string s[] = {"1110111", "0010010", "1011101", "1011011", "0111010",
              "1101011", "1101111", "1010010", "1111111", "1111011"},
       ans;
bool func(int idx, int cnt) {
  if (cnt > k) return 0;
  if (idx == n) return (cnt == k);
  if (vis[idx][cnt]) return 0;
  vis[idx][cnt] = 1;
  for (int i = 9; i >= 0; i--) {
    if (func(idx + 1, cnt + a[i][idx])) {
      ans += i + '0';
      return 1;
    }
  }
  return 0;
}
void solve() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    string x;
    cin >> x;
    for (int j = 0; j < 10; j++) {
      for (int l = 0; l < 7; l++) {
        a[j][i] += (x[l] != s[j][l]);
        if (x[l] == '1' && s[j][l] == '0') a[j][i] = 1e9;
      }
    }
  }
  if (func(0, 0)) {
    reverse(ans.begin(), ans.end());
    cout << ans;
  } else
    cout << "-1";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
