#include <bits/stdc++.h>
using namespace std;
int n;
int k;
int ans;
int as[514514];
map<int, int> cnt;
set<pair<int, int> > lib;
set<int> appear[514514];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &as[i]);
    appear[as[i]].insert(i);
    appear[as[i]].insert(0x7fffffff);
  }
  for (int i = 0; i < n; i++) {
    if (lib.count(pair<int, int>(*appear[as[i]].begin(), as[i]))) {
      lib.erase(pair<int, int>(*appear[as[i]].begin(), as[i]));
      appear[as[i]].erase(i);
      lib.insert(pair<int, int>(*appear[as[i]].begin(), as[i]));
      continue;
    }
    ans++;
    if (lib.size() == k) {
      lib.erase(*lib.rbegin());
    }
    appear[as[i]].erase(i);
    lib.insert(pair<int, int>(*appear[as[i]].begin(), as[i]));
  }
  printf("%d\n", ans);
}
