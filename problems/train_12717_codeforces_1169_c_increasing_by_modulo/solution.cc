#include <bits/stdc++.h>
using namespace std;
void TxtRead() {
  freopen("sleepy.in", "r", stdin);
  freopen("sleepy.out", "w", stdout);
}
void TheTime() {
  ios_base::sync_with_stdio(false);
  cin.tie();
}
const int N = 3e5 + 5;
const long long INF = 1e9 + 5;
const int MOD = 1e9 + 7;
const double PI = 3.141592653589793116;
int n, m;
int ar[N];
bool _can(int x) {
  int br[N];
  memset(br, 0, sizeof(br));
  for (int i = 1; i <= n; i++) {
    br[i] = ar[i];
    if (br[i] > br[i - 1] && br[i] + x >= m && (br[i] + x) % m >= br[i - 1])
      br[i] = br[i - 1];
    else if (br[i] < br[i - 1] && br[i] + x >= br[i - 1])
      br[i] = br[i - 1];
    if (br[i] < br[i - 1]) return false;
  }
  return true;
}
int main() {
  TheTime();
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &ar[i]);
  int l = 0, r = m, mid;
  while (l < r - 1) {
    mid = (l + r) / 2;
    if (_can(mid))
      r = mid;
    else
      l = mid;
  }
  if (_can(l))
    printf("%d\n", l);
  else
    printf("%d\n", r);
}
