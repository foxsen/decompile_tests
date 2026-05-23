#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
int main() {
  long long pm, mp, v;
  int n;
  long long ans = 0;
  scanf("%d", &n);
  scanf("%lld", &v);
  pm = -v;
  mp = v;
  for (int i = 1; i < n; i++) {
    scanf("%lld", &v);
    long long cur = max(ans, max(pm + v, mp - v));
    pm = max(pm, ans - v);
    mp = max(mp, ans + v);
    ans = cur;
  }
  printf("%lld\n", ans);
  return 0;
}
