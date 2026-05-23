#include <bits/stdc++.h>
using namespace std;
const int INF = 1523456789;
const long double PI = acos(-1);
const int MAX = 7000 * (2e5) + 10;
int get_limit_for(long double angle) {
  assert(angle != 0);
  long double temp = sin(angle / 2);
  temp = 1 / temp;
  temp = temp * temp;
  temp = temp - 1;
  assert(temp != 0);
  temp = sqrt(temp);
  return (int)ceil(temp);
}
long double get_angle(int d, bool collide) {
  return (collide ? 2 : 1) * asin(1 / sqrt(1 + (long double)d * d));
}
int main() {
  int N, D;
  scanf("%d %d", &N, &D);
  vector<int> a;
  set<int> two_blocks;
  unordered_set<int> exist;
  for (int i = 0; i < N; ++i) {
    int x;
    scanf("%d", &x);
    if (a.size() == 0 || a.back() != x) {
      a.push_back(x);
    } else {
      two_blocks.insert(x);
    }
    a.push_back(x + 1);
    exist.insert(x);
    exist.insert(x + 1);
  }
  N = a.size();
  int M;
  scanf("%d", &M);
  int idx = -1;
  for (int i = 0; i < M; ++i) {
    int x;
    scanf("%d", &x);
    ;
    if (two_blocks.find(x) != two_blocks.end()) {
      printf("%0.15Lf\n", PI);
      continue;
    }
    while (idx + 1 < N && a[idx + 1] <= x) {
      ++idx;
    }
    int lim = INF;
    int lidx = idx;
    int ridx = idx + 1;
    int delta_l = lidx >= 0 ? x - a[lidx] : INF;
    int delta_r = ridx < N ? a[ridx] - x : INF;
    if (delta_l == delta_r) {
      ;
      long double angle = get_angle(delta_l, true);
      printf("%0.15Lf\n", angle);
    } else {
      ;
      long double angle = get_angle(min(delta_l, delta_r), false);
      int lim = get_limit_for(angle);
      if (delta_l <= delta_r) lidx--;
      ;
      while (lidx >= 0 && a[lidx] + lim >= x) {
        int delta_l = x - a[lidx];
        int r = x + delta_l;
        if (exist.find(r) != exist.end()) {
          ;
          angle = max(angle, get_angle(delta_l, true));
          break;
        } else {
          ;
        }
        lidx--;
      }
      printf("%0.15Lf\n", angle);
    }
  }
  return 0;
}
