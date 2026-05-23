#include <bits/stdc++.h>
inline int getInt() {
  int s;
  scanf("%d", &s);
  return s;
}
using namespace std;
int main() {
  const int n = getInt();
  const long long k = getInt();
  vector<long long> a(n);
  for (int i = 0; i < (int)(n); i++) a[i] = getInt();
  int cnt = 1;
  long long d = 0;
  for (int i = 1; i < n; i++) {
    d -= (n - 1 - i) * a[i] * cnt;
    const bool f = d < k;
    d += (n - 1 - i) * a[i] * cnt;
    if (f) {
      printf("%d\n", i + 1);
    } else {
      cnt++;
      d += a[i] * (cnt - 1);
    }
  }
  return 0;
}
