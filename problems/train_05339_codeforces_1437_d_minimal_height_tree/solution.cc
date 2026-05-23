#include <bits/stdc++.h>
using namespace std;
void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> poss;
    int count = 1;
    for (int i = 2; i < n; i++) {
      if (a[i] > a[i - 1]) {
        count++;
      } else {
        poss.push_back(count);
        count = 1;
      }
    }
    poss.push_back(count);
    int level = 1, nodes = 1, i = 0;
    while (i < poss.size()) {
      level++;
      int sum = 0;
      while (i < poss.size() && nodes--) {
        sum += poss[i];
        i++;
      }
      nodes = sum;
    }
    cout << level - 1 << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
