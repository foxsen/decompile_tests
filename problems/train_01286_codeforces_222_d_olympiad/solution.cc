#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cout << *it << " = " << a << "\n";
  err(++it, args...);
}
const long long M = 1e9 + 7, inf = 1e9;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n, k;
  cin >> n >> k;
  int a[n], b[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  ;
  for (int i = 0; i < n; i++) cin >> b[i];
  ;
  multiset<int> s;
  for (int i = 0; i < n; i++) {
    s.insert(a[i]);
  }
  int x = inf;
  for (int i = 0; i < n; i++) {
    auto it = s.lower_bound(k - b[i]);
    if (it != s.end()) {
      x = min(x, b[i] + *it);
    }
  }
  int beh = 0;
  for (int i = 0; i < n; i++) {
    auto it = s.lower_bound(x - b[i]);
    if (it != s.end()) {
      s.erase(it);
    } else {
      beh++;
    }
  }
  cout << 1 << " " << n - beh;
}
