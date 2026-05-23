#include <bits/stdc++.h>
using namespace std;
int t, n;
set<int> Set;
int main() {
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    Set.clear();
    scanf("%d", &n);
    for (int j = 1; j <= n; j++) {
      int tmp;
      scanf("%d", &tmp);
      Set.insert(tmp);
    }
    if (Set.size() == n)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
