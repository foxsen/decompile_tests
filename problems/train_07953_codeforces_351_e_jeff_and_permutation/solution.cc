#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000;
int n, tmp;
vector<int> v, v2, maxes;
int maxx, maxxCnt, ans;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    v.push_back(abs(tmp));
  }
  while (!v.empty()) {
    for (int i : v) maxx = max(maxx, i);
    for (int i = 0; i < v.size(); i++)
      if (v[i] == maxx) maxes.push_back(i);
    for (int i = 0; i < maxes.size(); i++) {
      if (maxes[i] - i < v.size() - maxes[i] - maxes.size() + i)
        ans += maxes[i] - i;
      else
        ans += v.size() - maxes[i] - maxes.size() + i;
    }
    for (int i : v)
      if (i != maxx) v2.push_back(i);
    v = v2;
    while (!v2.empty()) v2.pop_back();
    while (!maxes.empty()) maxes.pop_back();
    maxx = 0;
  }
  cout << ans << endl;
  return 0;
}
