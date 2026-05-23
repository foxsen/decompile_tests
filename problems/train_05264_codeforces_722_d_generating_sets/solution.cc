#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50010;
int a[MAXN];
map<int, int> mp;
set<int> s, res;
int main() {
  int n, m, i, j;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    s.insert(a[i]);
    mp[a[i]] = 1;
  }
  set<int>::iterator it;
  while (1) {
    it = s.end();
    it--;
    int tmp = *it;
    while (mp[tmp] == 1 && tmp > 0) tmp /= 2;
    if (tmp == 0) break;
    s.erase(it);
    s.insert(tmp);
    mp[*it] = 0;
    mp[tmp] = 1;
  }
  for (it = s.begin(); it != s.end(); it++) printf("%d ", *it);
  return 0;
}
