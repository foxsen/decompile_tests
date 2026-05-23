#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 10;
int n;
int b[MAXN];
pair<int, int> a[MAXN];
vector<pair<int, pair<int, int>>> vi;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i + 1;
  }
  for (int i = 0; i < n; i++) cin >> b[i];
  sort(a, a + n);
  sort(b, b + n);
  for (int i = 0; i < n; i++) a[i].first = b[i] - a[i].first;
  stack<int> s;
  for (int i = n - 1; i >= 0; i--)
    if (a[i].first < 0) {
      s.push(i);
    }
  long long ans = 0;
  bool can = 1;
  for (int i = 0; i < n; i++) {
    if (a[i].first < 0 || !can || !s.empty() && s.top() < i) {
      can = 0;
      continue;
    }
    while (a[i].first > 0 && !s.empty()) {
      if (a[i].first >= abs(a[s.top()].first)) {
        vi.push_back({-a[s.top()].first, {a[i].second, a[s.top()].second}});
        a[i].first += a[s.top()].first;
        a[s.top()].first = 0;
        s.pop();
      } else {
        vi.push_back({a[i].first, {a[i].second, a[s.top()].second}});
        a[s.top()].first += a[i].first;
        a[i].first = 0;
      }
    }
    if (a[i].first > 0) can = 0;
  }
  if (can) {
    cout << "YES\n";
    cout << vi.size() << "\n";
    for (auto first : vi) {
      cout << first.second.first << " " << first.second.second << " "
           << first.first << "\n";
    }
  } else {
    cout << "NO\n";
  }
}
