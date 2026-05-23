#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, k, j;
  cin >> n >> k;
  set<long long> ms;
  long long x = 0;
  for (i = 0; i < n; i++) {
    cin >> j;
    if (ms.find(j) == ms.end()) {
      ms.insert(j);
      x += j;
    }
  }
  j = 0;
  for (auto it : ms) {
    if (k <= 0 || x <= 0) break;
    cout << (it - j) << endl;
    j = it;
    x -= it;
    k--;
  }
  while (k--) cout << "0" << endl;
}
