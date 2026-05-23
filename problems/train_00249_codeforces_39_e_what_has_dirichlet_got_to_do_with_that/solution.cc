#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
map<pair<int, int>, int> Set;
int a, b, n, ret;
void init() { scanf("%d%d%d", &a, &b, &n); }
int solve(int a, int b) {
  pair<int, int> cur = make_pair(a, b);
  if (Set.find(cur) != Set.end()) return Set[cur];
  bool A = false, B = false;
  if (log(n) / log(a + 1) - eps > b) A = true;
  if (pow((double)a, b + 1) < n - eps) B = true;
  int ret = 0;
  if (!A && !B) {
    ret = -1;
  } else if (a == 1 && !A) {
    ret = 0;
  } else if (b == 1 && !B) {
    ret = ((n - a) & 1) ? -1 : 1;
  } else {
    ret = 1;
    if (B) {
      int tmp = solve(a, b + 1);
      if (tmp < ret) ret = tmp;
    }
    if (A) {
      int tmp = solve(a + 1, b);
      if (tmp < ret) ret = tmp;
    }
    if (ret != 0) ret = -ret;
  }
  Set[cur] = ret;
  return ret;
}
void work() { ret = solve(a, b); }
void print() {
  if (ret == 1)
    printf("Masha\n");
  else if (ret == -1)
    printf("Stas\n");
  else
    printf("Missing\n");
}
int main() {
  init();
  work();
  print();
  return 0;
}
