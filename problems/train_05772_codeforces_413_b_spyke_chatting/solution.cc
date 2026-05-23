#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[20010][12];
  int per[20010], chat[12];
  int i, n, m, k, j, c, p;
  cin >> n >> m >> k;
  memset(per, 0, sizeof(per));
  memset(chat, 0, sizeof(chat));
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j) cin >> a[i][j];
  for (i = 1; i <= k; ++i) {
    cin >> p >> c;
    chat[c]++;
    per[p]--;
  }
  for (i = 1; i <= n; ++i) {
    for (j = 1; j <= m; ++j)
      if (a[i][j]) per[i] += chat[j];
    cout << per[i] << ' ';
  }
  cout << endl;
  return 0;
}
