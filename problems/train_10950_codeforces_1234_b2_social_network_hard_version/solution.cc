#include <bits/stdc++.h>
using namespace std;
int n, k, a[200005];
set<int> ada;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    id;
vector<int> ans;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (ada.count(a[i])) {
      continue;
    }
    if (id.size() == k) {
      ada.erase(id.top().second);
      id.pop();
      id.push(make_pair(i, a[i]));
      ada.insert(a[i]);
    } else {
      id.push(make_pair(i, a[i]));
      ada.insert(a[i]);
    }
  }
  cout << id.size() << '\n';
  while (!id.empty()) {
    ans.push_back(id.top().second);
    id.pop();
  }
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) {
    if (i) cout << ' ';
    cout << ans[i];
  }
  cout << '\n';
  return 0;
}
