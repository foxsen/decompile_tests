#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
int kq;
int n, m, k;
int a[N];
bool check(int f) {
  int tg = 0;
  int cl = m;
  for (int i = n - f + 1; i <= n; i++) {
    if (tg < a[i]) {
      tg = k;
      cl--;
    }
    tg -= a[i];
  }
  return (cl >= 0);
}
void np() {
  int l = 0, r = n;
  while (l <= r) {
    int giua = (l + r) / 2;
    if (check(giua)) {
      kq = giua;
      l = giua + 1;
    } else
      r = giua - 1;
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  np();
  printf("%d", kq);
}
