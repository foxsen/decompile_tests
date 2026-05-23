#include <bits/stdc++.h>
using namespace std;
int n, a[200005];
map<int, int> mp;
vector<int> ver;
long long sum;
int main() {
  scanf("%d", &n);
  for (register int i = 1; i <= n; ++i)
    scanf("%d", &a[i]), sum += a[i], mp[a[i]]++;
  long long t;
  for (register int i = 1; i <= n; ++i) {
    t = sum - a[i];
    if (t & 1) continue;
    t >>= 1;
    if (t > 0 && t <= 1000000) {
      if (t != a[i] && mp[t] >= 1 || t == a[i] && mp[t] >= 2) {
        ver.push_back(i);
      }
    }
  }
  printf("%d\n", ver.size());
  for (int i : ver) printf("%d ", i);
  return 0;
}
