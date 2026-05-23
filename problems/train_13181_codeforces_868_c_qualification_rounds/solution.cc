#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> count(16);
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = 0; j < k; j++) {
      int x;
      cin >> x;
      sum = sum * 2 + x;
    }
    count[sum] += 1;
  }
  int ans = 0;
  if (count[0] > 0)
    ans = 1;
  else {
    for (int i = 0; i < (1 << k); i++) {
      for (int j = 0; j < (1 << k); j++) {
        if (count[i] == 0 || count[j] == 0) continue;
        if (i == j and count[j] < 2) continue;
        if (i & j) continue;
        ans = 1;
      }
    }
  }
  ans == 1 ? cout << "YES\n" : cout << "NO\n";
}
