#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  scanf("%d", &n);
  vector<int> v(n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  sort(v.begin(), v.end(), greater<int>());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  scanf("%d%d", &a, &b);
  int count = 0, be = 0;
  while (a > b && be < v.size()) {
    count++;
    int step = 0;
    for (int i = be; i < v.size() && v[i] > step; i++) {
      if (a - a % v[i] >= b)
        step = ((step > (a % v[i])) ? step : (a % v[i]));
      else
        be = i + 1;
    }
    if (step)
      a -= step;
    else
      a--;
  }
  count += a - b;
  printf("%d\n", count);
  return 0;
}
