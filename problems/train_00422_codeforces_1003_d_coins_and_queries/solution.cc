#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, q;
  map<int, int> coins;
  cin >> n >> q;
  int queries[q];
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    coins[val]++;
  }
  for (int i = 0; i < q; i++) {
    cin >> queries[i];
  }
  for (int i = 0; i < q; i++) {
    int counter = 0;
    int curr = 0;
    for (auto it = coins.rbegin(); it != coins.rend(); it++) {
      int num = min(it->second, (queries[i] - curr) / (it->first));
      counter += num;
      curr += num * (it->first);
    }
    if (curr == queries[i]) {
      cout << counter << endl;
    } else {
      cout << -1 << endl;
    }
  }
}
