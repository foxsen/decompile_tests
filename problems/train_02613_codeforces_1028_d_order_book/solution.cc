#include <bits/stdc++.h>
#pragma GCC optimaze("Ofast");
#pragma GCC optimize("unroll-loops")
using namespace std;
const long long mod = 1e9 + 7;
int main() {
  srand(time(NULL));
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  set<int> mis1, mis2;
  vector<int> we;
  long long ans = 1;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (s == "ADD") {
      int a;
      cin >> a;
      we.push_back(a);
    } else {
      int a;
      cin >> a;
      sort(we.begin(), we.end());
      if (mis2.size() != 0) {
        while (we.size() && we.back() > (*mis2.begin())) {
          mis2.insert(we.back());
          we.pop_back();
        }
      }
      if (mis1.size() != 0) {
        reverse(we.begin(), we.end());
        while (we.size() && we.back() < *(--mis1.end())) {
          mis1.insert(we.back());
          we.pop_back();
        }
        reverse(we.begin(), we.end());
      }
      if ((mis1.size() && a < *(--mis1.end())) ||
          (mis2.size() && a > (*mis2.begin()))) {
        cout << "0";
        return 0;
      }
      if (mis1.size() && a == *(--mis1.end())) {
        for (int i = 0; i < we.size(); i++) mis2.insert(we[i]);
        we.clear();
        mis1.erase(--mis1.end());
      } else if (mis2.size() && a == (*mis2.begin())) {
        for (int i = 0; i < we.size(); i++) mis1.insert(we[i]);
        we.clear();
        mis2.erase(mis2.begin());
      } else {
        for (int i = 0; i < we.size(); i++) {
          if (we[i] < a)
            mis1.insert(we[i]);
          else if (we[i] > a)
            mis2.insert(we[i]);
        }
        we.clear();
        ans = (ans * 2) % mod;
      }
    }
  }
  sort(we.begin(), we.end());
  if (mis2.size() != 0) {
    while (we.size() && we.back() > (*mis2.begin())) {
      mis2.insert(we.back());
      we.pop_back();
    }
  }
  if (mis1.size() != 0) {
    reverse(we.begin(), we.end());
    while (we.size() && we.back() < *(--mis1.end())) {
      mis1.insert(we.back());
      we.pop_back();
    }
    reverse(we.begin(), we.end());
  }
  if (we.size()) ans = (ans * ((long long)we.size() + 1)) % mod;
  cout << ans;
}
