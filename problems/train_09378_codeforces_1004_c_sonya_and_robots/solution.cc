#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
int vis[100005];
int a[100005];
int main() {
  int n;
  scanf("%d", &n);
  int now = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    if (!mp[a[i]]) {
      mp[a[i]]++;
      now++;
    } else {
      mp[a[i]]++;
    }
  }
  long long ans = 0;
  for (int i = 1; i < n; ++i) {
    mp[a[i]]--;
    if (mp[a[i]] == 0) now--;
    if (vis[a[i]]) continue;
    vis[a[i]] = 1;
    ans += now;
  }
  printf("%lld\n", ans);
}
