#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void maxi(T &x, T y) {
  if (y > x) x = y;
}
template <class T>
inline void mini(T &x, T y) {
  if (y < x) x = y;
}
const int N = 200, B = 0x7fffffff;
int n, m;
pair<int, int> a[N];
int ans[N];
int sum;
int main() {
  scanf("%d", &n), scanf("%d", &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i].first);
    sum += a[i].first;
    a[i].second = i;
  }
  sort(a + 1, a + n + 1);
  int nas = sum - m;
  for (int i = 1; i <= n; i++) {
    if (nas == 0)
      ans[a[i].second] = a[i].first;
    else {
      if (nas <= a[i].first / 2) {
        ans[a[i].second] = a[i].first - nas;
        nas = 0;
      } else {
        nas -= a[i].first / 2;
        ans[a[i].second] = a[i].first - a[i].first / 2;
      }
    }
  }
  if (nas != 0)
    puts("-1");
  else {
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  }
  return !!0;
}
