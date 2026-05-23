#include <bits/stdc++.h>
using namespace std;
int main() {
  int home[30];
  int away[30];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> home[i];
    cin >> away[i];
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      if (home[i] == away[j]) cnt++;
    }
  }
  cout << cnt << '\n';
  return 0;
}
