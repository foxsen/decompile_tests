#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
int n, m;
struct ufind {
  int p[100005], t;
  void init() { memset(p, 0, sizeof(p)); }
  void set_friend(int i, int j) {
    for (; p[t = i]; i = p[i], p[t] = (p[i] ? p[i] : i))
      ;
    for (; p[t = j]; j = p[j], p[t] = (p[j] ? p[j] : j))
      ;
    p[i] = (i == j ? 0 : j);
  }
  int is_friend(int i, int j) {
    for (; p[t = i]; i = p[i], p[t] = (p[i] ? p[i] : i))
      ;
    for (; p[t = j]; j = p[j], p[t] = (p[j] ? p[j] : j))
      ;
    return i == j && i;
  }
} U;
int main() {
  while (cin >> n >> m) {
    int a, b;
    U.init();
    long long ret = 0;
    for (int i = 0; i < m; ++i) {
      scanf("%d%d", &a, &b);
      if (U.is_friend(a, b)) {
        ret *= 2;
        ++ret;
        ret %= 1000000009;
      } else {
        U.set_friend(a, b);
      }
      cout << ret << endl;
    }
  }
  return 0;
}
