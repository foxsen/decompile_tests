#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string first, second;
  cin >> first >> second;
  multiset<char> X, Y;
  for (char ch : first) {
    X.insert(ch);
  }
  for (char ch : second) {
    Y.insert(ch);
  }
  int n = ((int)(first).size());
  int half = n / 2 + (n & 1);
  while (((int)(X).size()) != half) {
    X.erase((--(X.end())));
  }
  while (((int)(Y).size()) != n - half) {
    Y.erase(Y.begin());
  }
  vector<char> ans(n);
  int left = 0, right = n - 1;
  int turn = 1;
  for (int i = 0; i < n; i++) {
    if (turn) {
      if (Y.empty()) {
        ans[left] = *X.begin();
        break;
      }
      char mx = *(--(Y.end()));
      char mn = *X.begin();
      if (mx > mn) {
        ans[left++] = mn;
        X.erase(X.begin());
      } else {
        mx = *(--(X.end()));
        ans[right--] = mx;
        X.erase(X.lower_bound(mx));
      }
    } else {
      char mx = *(--(Y.end()));
      if (X.empty()) {
        ans[left] = mx;
        break;
      }
      char mn = *X.begin();
      if (mx > mn) {
        ans[left++] = mx;
        Y.erase(Y.lower_bound(mx));
      } else {
        mn = *Y.begin();
        ans[right--] = mn;
        Y.erase(Y.begin());
      }
    }
    turn ^= 1;
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i];
  }
  cout << "\n";
}
