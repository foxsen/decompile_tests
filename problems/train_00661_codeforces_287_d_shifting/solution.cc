#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 4e6 + 5;
int a[N];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) a[i] = i + 1;
  int L = 0, R = n - 1;
  for (int i = 2; i <= n; ++i) {
    for (int k = (n - 1) / i; k > 0; --k)
      swap(a[L + (k - 1) * i], a[L + k * i]);
    ++R;
    a[R] = a[L];
    ++L;
  }
  for (int i = 0; i < n; ++i) printf("%d%s", a[L + i], i == n - 1 ? "\n" : " ");
  return 0;
}
