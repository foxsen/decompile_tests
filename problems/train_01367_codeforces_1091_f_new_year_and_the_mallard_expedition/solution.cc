#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n;
  cin >> n;
  vector<int64_t> a(n), water(n, 0), land(n, 0);
  int64_t time = 0;
  for (int64_t i = 0; i < n; i++) {
    cin >> a[i];
    a[i] *= 4;
    time += a[i];
  }
  string s__;
  cin >> s__;
  for (int64_t i = 0; i < n; i++) {
    water[i] = ((s__[i] == 'W') ? a[i] : 0);
    land[i] = ((s__[i] == 'G') ? a[i] : 0);
    if (i != 0) {
      water[i] += water[i - 1];
      land[i] += land[i - 1];
    }
  }
  int64_t timePlus = 0;
  int64_t usedWater = 0;
  int64_t usedLand = 0;
  for (int64_t i = 0; i < n; i++) {
    int64_t avaWater = water[i] - usedWater;
    int64_t avaLand = land[i] - usedLand;
    int64_t need = a[i] / 2;
    if (avaWater >= need) {
      usedWater += need;
      timePlus += need * 2;
    } else {
      need -= avaWater;
      usedWater += avaWater;
      timePlus += avaWater * 2;
      if (avaLand >= need) {
        usedLand += need;
        timePlus += need * 4;
      } else {
        need -= avaLand;
        usedLand += avaLand;
        timePlus += avaLand * 4;
        if (water[i] > 0)
          timePlus += (need * 2) * 3;
        else
          timePlus += (need * 2) * 5;
      }
    }
  }
  cout << (timePlus + time) / 4;
  return 0;
}
