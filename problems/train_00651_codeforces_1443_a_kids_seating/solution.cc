#include <bits/stdc++.h>
using namespace std;
vector<int> pr[405];
void prime(int n) {
  for (int i = 2; i < n * n; i++) {
    if (n % i == 0) {
      pr[n].push_back(i);
      while (n % i == 0) n /= i;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int cnt = 0;
    bool b = 0;
    vector<int> ans;
    for (int i = 4 * n; i >= 4; i -= 2) {
      if (cnt == n) break;
      ans.push_back(i);
      cnt++;
    }
    for (auto x : ans) cout << x << " ";
    cout << endl;
  }
  return 0;
}
