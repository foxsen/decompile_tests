#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T bigmod(T p, T e, T m) {
  T ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % m;
    p = (p * p) % m;
  }
  return (T)ret;
}
void solve() {
  int n, bag, k;
  cin >> n >> bag >> k;
  vector<int> items(n);
  for (int i = 0; i < n; i++) {
    cin >> items[i];
  }
  for (int i = 1; i < n; i++) {
    long long rem = items[i] - k;
    if (rem < 0) {
      rem = 0;
    }
    rem = items[i - 1] - rem;
    bag = bag + rem;
    if (bag < 0) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cout.setf(ios::fixed);
  cout.precision(10);
  cout.tie(nullptr);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  int pause;
  cin >> pause;
  return 0;
}
