#include <bits/stdc++.h>
using namespace std;
const int maxint = -1u >> 1;
template <class T>
bool get_max(T& a, const T& b) {
  return b > a ? a = b, 1 : 0;
}
template <class T>
bool get_min(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
struct node {
  int val, dis;
  node() {}
  node(int _val, int _dis) : val(_val), dis(_dis) {}
} dat[100000];
bool com(node a, node b) { return a.dis < b.dis; }
int main() {
  int n, cur = 0;
  cin >> n >> cur;
  for (int i = 1; i <= n; i++) {
    int x, y, c;
    scanf("%d %d %d", &x, &y, &c);
    dat[i] = node(c, x * x + y * y);
  }
  sort(dat + 1, dat + 1 + n, com);
  if (cur >= 1000000) {
    puts("0.0");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    cur += dat[i].val;
    if (cur >= 1000000) {
      printf("%.7f\n", sqrt(dat[i].dis));
      return 0;
    }
  }
  puts("-1");
  return 0;
}
