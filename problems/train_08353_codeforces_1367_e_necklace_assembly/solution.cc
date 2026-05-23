#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const int N = 2e2 + 10;
int cnt[N];
int gcd(int n, int m) { return m == 0 ? n : gcd(m, n % m); }
int main() {
  int ncase;
  scanf("%d", &ncase);
  while (ncase--) {
    int n, k;
    scanf("%d%d", &n, &k);
    string str;
    cin >> str;
    memset((cnt), (0), sizeof(cnt));
    for (auto& c : str) cnt[c]++;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int g = gcd(i, k);
      int r = i / g;
      int tot = 0;
      for (int j = 'a'; j <= 'z'; j++) tot += cnt[j] / r;
      if (tot >= g) ans = i;
    }
    printf("%d\n", ans);
  }
  return 0;
}
