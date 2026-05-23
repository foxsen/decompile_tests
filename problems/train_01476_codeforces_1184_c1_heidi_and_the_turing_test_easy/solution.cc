#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long int n, i, j;
  vector<pair<long long int, long long int> > v;
  cin >> n;
  for (i = 0; i < 4 * n + 1; i++) {
    long long int x, y;
    cin >> x >> y;
    v.push_back(make_pair(x, y));
  }
  for (i = 0; i < v.size(); i++) {
    vector<pair<long long int, long long int> > aux;
    long long int f1 = 0, f2 = 0, f3 = 0, f4 = 0, mx = -1, my = -1, miy = 1e18,
                  mix = 1e18;
    for (j = 0; j < v.size(); j++) {
      if (i == j) continue;
      mix = min(mix, v[j].first);
      miy = min(miy, v[j].second);
      mx = max(mx, v[j].first);
      my = max(my, v[j].second);
      aux.push_back(v[j]);
    }
    for (j = 0; j < aux.size(); j++) {
      if (aux[j].first == mix)
        if (aux[j].second >= miy && aux[j].second <= my) f1++;
      if (aux[j].first == mx)
        if (aux[j].second >= miy && aux[j].second <= my) f2++;
      if (aux[j].second == miy)
        if (aux[j].first >= mix && aux[j].first <= mx) f3++;
      if (aux[j].second == my)
        if (aux[j].first >= mix && aux[j].first <= mx) f4++;
      if (aux[j].first != mix && aux[j].first != mx && aux[j].second != miy &&
          aux[j].second != my)
        f1 = -1e18;
    }
    if (f1 >= n && f2 >= n && f3 >= n && f4 >= n) {
      cout << v[i].first << " " << v[i].second << "\n";
      return 0;
    }
  }
  return 0;
}
