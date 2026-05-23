#include <bits/stdc++.h>
using namespace std;
namespace Primary {
int a, b;
long long ans = 0;
void main() {
  scanf("%d%d", &a, &b);
  for (int L = 1, R; L <= a + b; L = R + 1) {
    int p = (a + b) / L;
    R = (a + b) / p;
    if (a < p || b < p) continue;
    int l_a = (a - 1) / (p + 1) + 1, l_b = (b - 1) / (p + 1) + 1;
    int r_a = a / p, r_b = b / p;
    if (l_a <= r_a && l_b <= r_b)
      ans += max(0ll, 1ll * (min(R, r_a + r_b) - max(L, l_a + l_b) + 1));
  }
  printf("%I64d", ans);
}
}  // namespace Primary
int main() {
  Primary::main();
  return 0;
}
