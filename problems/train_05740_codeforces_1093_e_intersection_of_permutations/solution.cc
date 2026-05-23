#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse4.2,sse4.1,ssse3,sse3,sse2,sse")
#pragma GCC target("avx")
#pragma GCC target("avx2")
using namespace std;
const int maxn = (int)2e5;
alignas(32) int a[maxn];
alignas(32) int b[maxn];
alignas(32) int posA[maxn];
alignas(32) int posB[maxn];
alignas(32) int special[maxn];
alignas(32) int result[128];
bool check(int lb, int rb, int i) {
  return lb <= special[i] && special[i] <= rb;
}
int getCount(int la, int ra, int lb, int rb) {
  int count = 0;
  if (la / 128 == ra / 128) {
    for (int i = la; i <= ra; i++) count += check(lb, rb, i);
    return count;
  } else {
    while (la % 128 != 0) {
      count += check(lb, rb, la);
      la++;
    }
    while (ra % 128 != 128 - 1) {
      count += check(lb, rb, ra);
      ra--;
    }
    ra++;
    for (int i = 0; i < 128; i++) result[i] = 0;
    for (int i = la; i + 128 <= ra; i += 128) {
      for (int j = 0; j < 128; j++) {
        result[j] += check(lb, rb, i + j);
      }
    }
    for (int i = 0; i < 128; i++) count += result[i];
  }
  return count;
}
int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i], a[i]--;
  for (int i = 0; i < n; i++) cin >> b[i], b[i]--;
  for (int i = 0; i < n; i++) posA[a[i]] = i;
  for (int i = 0; i < n; i++) posB[b[i]] = i;
  for (int i = 0; i < n; i++) special[i] = posB[a[i]];
  for (int i = 0; i < m; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int la, ra, lb, rb;
      cin >> la >> ra >> lb >> rb;
      la--, ra--, lb--, rb--;
      int count = getCount(la, ra, lb, rb);
      cout << count << '\n';
    } else {
      int x, y;
      cin >> x >> y;
      x--, y--;
      swap(b[x], b[y]);
      posB[b[x]] = x;
      posB[b[y]] = y;
      special[posA[b[x]]] = x;
      special[posA[b[y]]] = y;
    }
  }
}
