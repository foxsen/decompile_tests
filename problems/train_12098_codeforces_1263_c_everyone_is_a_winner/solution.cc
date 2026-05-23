#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    set<int> s;
    s.insert(0);
    s.insert(1);
    s.insert(n);
    for (int i = 2; i <= sqrt(n); i++) {
      s.insert(i);
      s.insert(n / i);
    }
    cout << s.size() << endl;
    for (auto i : s) cout << i << " ";
    cout << endl;
  }
}
