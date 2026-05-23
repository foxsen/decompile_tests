#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, max, time, qsize;
  vector<int> t, c;
  cin >> n;
  t.resize(n);
  c.resize(n);
  for (int i(0), _n(n); i < _n; ++i) cin >> t[i] >> c[i];
  max = 0;
  time = 1;
  int q;
  q = 0;
  qsize = 0;
  while (q < n) {
    if (qsize > 0) qsize--;
    if (t[q] == time) {
      qsize += c[q];
      if (max < qsize) max = qsize;
      q++;
    }
    time++;
  }
  time += qsize - 1;
  cout << time << " " << max;
  return 0;
}
