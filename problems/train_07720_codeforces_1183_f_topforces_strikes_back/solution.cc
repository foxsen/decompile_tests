#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    set<int> a;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a.insert(x);
    }
    int ans1 = *a.rbegin();
    if (ans1 % 2 == 0 && ans1 % 3 == 0 && ans1 % 5 == 0)
      if (a.count(ans1 / 2) && a.count(ans1 / 3) && a.count(ans1 / 5))
        ans1 = ans1 / 2 + ans1 / 3 + ans1 / 5;
    vector<int> elements;
    elements.push_back(*a.rbegin());
    a.erase(--a.end());
    for (auto it = a.rbegin(); it != a.rend() && elements.size() < 3; it++) {
      bool ok = true;
      for (auto i : elements)
        if (i % *it == 0) ok = false;
      if (ok) elements.push_back(*it);
    }
    int ans = max(ans1, accumulate(elements.begin(), elements.end(), 0));
    cout << ans << '\n';
  }
}
