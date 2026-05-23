#include <bits/stdc++.h>
using namespace std;
int a[110000];
int b[110000];
int main() {
  vector<int> v;
  int i, n, m, k;
  cin >> n >> m >> k;
  for (i = 0; i < n; ++i) cin >> a[i];
  for (i = 0; i < m; ++i) cin >> b[i];
  sort(a, a + n);
  sort(b, b + m);
  bool answer = false;
  int it1 = 0, it2 = 0;
  while (1) {
    if (it2 >= m) {
      if (it1 < n) answer = true;
      break;
    }
    if (a[it1] <= b[it2]) it1++;
    it2++;
  }
  if (!answer)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}
