#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test_cases;
  cin >> test_cases;
  for (int tc = 1; tc <= test_cases; tc++) {
    int n;
    LL W;
    cin >> n >> W;
    pair<LL, int> w[n];
    int pppppp = -1;
    LL half = W / 2LL + (W % 2LL);
    LL sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> w[i].first;
      if (w[i].first >= half && w[i].first <= W) {
        pppppp = i + 1;
      }
      w[i].second = i + 1;
      sum += w[i].first;
    }
    if (pppppp != -1) {
      cout << 1 << endl << pppppp << endl;
      continue;
    }
    sort(w, w + n);
    if (w[0].first > W || sum < half) {
      cout << -1 << endl;
      continue;
    }
    sum = 0LL;
    deque<pair<LL, int> > knap;
    for (int i = 0; i < n; i++) {
      if (w[i].first > W) break;
      sum += w[i].first;
      knap.push_back(w[i]);
      if (sum >= half && sum <= W) break;
    }
    if (sum < half) {
      cout << -1 << endl;
    } else {
      cout << knap.size() << endl;
      for (auto &i : knap) cout << i.second << " ";
      cout << endl;
    }
  }
  return 0;
}
