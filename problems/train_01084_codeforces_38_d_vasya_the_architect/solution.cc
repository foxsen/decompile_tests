#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios::sync_with_stdio(0);
  solve();
  return 0;
}
pair<pair<double, double>, pair<double, double> > rects[100];
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> rects[i].first.first >> rects[i].first.second >>
        rects[i].second.first >> rects[i].second.second;
    if (rects[i].first.first > rects[i].second.first)
      swap(rects[i].first.first, rects[i].second.first);
    if (rects[i].first.second > rects[i].second.second)
      swap(rects[i].first.second, rects[i].second.second);
    for (int j = 0; j < i; j++) {
      double cx = 0, cy = 0, m = 0;
      for (int k = j + 1; k <= i; k++) {
        double l = fabs(rects[k].first.first - rects[k].second.first);
        double lll = l * l * l;
        m += lll;
        double x = (rects[k].first.first + rects[k].second.first) / 2.0;
        double y = (rects[k].first.second + rects[k].second.second) / 2.0;
        cx += lll * x;
        cy += lll * y;
      }
      cx /= m;
      cy /= m;
      if (rects[j].first.first > cx || rects[j].first.second > cy ||
          rects[j].second.first < cx || rects[j].second.second < cy) {
        cout << i;
        return;
      }
    }
  }
  cout << n;
}
