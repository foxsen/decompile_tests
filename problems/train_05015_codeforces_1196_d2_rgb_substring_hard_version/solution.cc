#include <bits/stdc++.h>
using namespace std;
template <typename... T>
void read(T&... args) {
  ((cin >> args), ...);
}
template <typename... T>
void write(T&&... args) {
  ((cout << args << " "), ...);
}
template <typename... T>
void writen(T&&... args) {
  ((cout << args << "\n"), ...);
}
long long bin(long long a, long long b, long long mod) {
  if (b == 0) return 1;
  if (b % 2 == 0) return bin((a * a) % mod, b / 2, mod) % mod;
  return ((a % mod) * (bin((a * a) % mod, b / 2, mod) % mod)) % mod;
}
void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  read(s);
  string con = "RGB";
  int temp[n + 1];
  temp[0] = 0;
  int start = 0;
  for (int i = 1; i < n + 1; i++) {
    if (s[i - 1] != con[start % 3]) {
      temp[i] = temp[i - 1] + 1;
    } else {
      temp[i] = temp[i - 1];
    }
    start++;
  }
  int ans = INT_MAX;
  for (int i = 0; i + k < n + 1; i++) {
    ans = min(ans, temp[i + k] - temp[i]);
  }
  start = 1;
  for (int i = 1; i < n + 1; i++) {
    if (s[i - 1] != con[start % 3]) {
      temp[i] = temp[i - 1] + 1;
    } else {
      temp[i] = temp[i - 1];
    }
    start++;
  }
  for (int i = 0; i + k < n + 1; i++) {
    ans = min(ans, temp[i + k] - temp[i]);
  }
  start = 2;
  for (int i = 1; i < n + 1; i++) {
    if (s[i - 1] != con[start % 3]) {
      temp[i] = temp[i - 1] + 1;
    } else {
      temp[i] = temp[i - 1];
    }
    start++;
  }
  for (int i = 0; i + k < n + 1; i++) {
    ans = min(ans, temp[i + k] - temp[i]);
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
