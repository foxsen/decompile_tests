#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans = 1;
  cin >> n;
  map<int, int> m;
  m.insert(pair<int, int>(0, 0));
  for (int i = 1; i <= n; i++) {
    int temp;
    cin >> temp;
    if (m.find(temp) != m.end()) {
      m.erase(m.find(temp));
    } else {
      ans++;
    }
    m.insert(pair<int, int>(i, 0));
  }
  cout << ans;
}
