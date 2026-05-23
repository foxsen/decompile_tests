#include <bits/stdc++.h>
using namespace std;
int arr[100001], nxt[100001], pos[100001], have[100001];
set<pair<int, int> > s;
int main() {
  ios::sync_with_stdio(false);
  ;
  cin.tie(0);
  ;
  int i, j, n, k, x, y, cost = 0, which, have_ctr = 0;
  cin >> n >> k;
  for (i = 1; i <= n; i++) cin >> arr[i];
  for (i = n; i >= 1; i--) {
    if (!pos[arr[i]])
      nxt[i] = n + 1;
    else
      nxt[i] = pos[arr[i]];
    pos[arr[i]] = i;
  }
  for (i = 1; i <= n; i++) {
    if (have[arr[i]]) {
      assert(s.find({i, arr[i]}) != s.end());
      s.erase(s.find({i, arr[i]}));
      s.insert({nxt[i], arr[i]});
      continue;
    }
    cost++;
    if (have_ctr < k) {
      have_ctr++;
      have[arr[i]] = 1;
      s.insert({nxt[i], arr[i]});
      continue;
    }
    which = (*(--s.end())).second;
    have[which] = 0;
    s.erase(--s.end());
    have[arr[i]] = 1;
    s.insert({nxt[i], arr[i]});
  }
  cout << cost;
  return 0;
}
