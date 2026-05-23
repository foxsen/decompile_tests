#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  vector<pair<int, int>> v;
  bool not_equal = false, increasing = false;
  int a, b;
  cin >> a >> b;
  v.push_back(make_pair(a, b));
  for (int i = 0; i < t - 1; i++) {
    cin >> a >> b;
    v.push_back(make_pair(a, b));
    if (v[i].first != v[i].second || a != b) {
      not_equal = true;
      break;
    }
    if (v[i].first < a) increasing = true;
  }
  if (not_equal)
    cout << "rated"
         << "\n";
  else if (!not_equal && !increasing)
    cout << "maybe"
         << "\n";
  else
    cout << "unrated"
         << "\n";
  return 0;
}
