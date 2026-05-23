#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<vector<int> > a(m + n + 1), b(m + n + 1);
  int c;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &c);
      a[i + j].push_back(c);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &c);
      b[i + j].push_back(c);
    }
  }
  bool isgood = true;
  for (int i = 0; i < m + n + 1; i++) {
    sort(a[i].begin(), a[i].end());
    sort(b[i].begin(), b[i].end());
    if (a[i] != b[i]) {
      isgood = false;
      break;
    }
  }
  if (isgood) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}
