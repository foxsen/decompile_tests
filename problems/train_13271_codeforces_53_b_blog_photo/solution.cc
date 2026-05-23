#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, j, h, w, tmp_h, tmp_w;
  cin >> h >> w;
  for (i = 0;; i++) {
    if ((long long)(1 << i) > h || (long long)(1 << i) > (5 * w) / 4) {
      i--;
      break;
    }
  }
  for (j = 0;; j++) {
    if ((long long)(1 << j) > w || (long long)(1 << j) > (5 * h) / 4) {
      j--;
      break;
    }
  }
  i = 1 << i;
  j = 1 << j;
  tmp_h = min(j * 5 / 4, h);
  tmp_w = min(i * 5 / 4, w);
  if (i * tmp_w > j * tmp_h)
    cout << i << " " << tmp_w << endl;
  else if (i * tmp_w < j * tmp_h)
    cout << tmp_h << " " << j << endl;
  else
    cout << max(i, tmp_h) << " " << min(j, tmp_w) << endl;
  return 0;
}
