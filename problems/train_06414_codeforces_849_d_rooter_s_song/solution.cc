#include <bits/stdc++.h>
using namespace std;
pair<int, pair<int, int> > dance[100005];
pair<int, pair<int, int> > event[100005];
int finish[100005];
vector<pair<int, int> > x, y;
vector<int> ini;
int main() {
  int n, w, h;
  cin >> n >> w >> h;
  for (int i = 1; i <= n; i++) {
    int tipe, p, t;
    cin >> tipe >> p >> t;
    dance[i] = make_pair(tipe, make_pair(p, t));
    event[i] = make_pair(p - t, make_pair(tipe, i));
    finish[i] = i;
  }
  sort(event + 1, event + n + 1);
  for (int i = 1; i <= n + 1; i++) {
    if (i != n + 1 && (i == 1 || event[i].first == event[i - 1].first)) {
      ini.push_back(event[i].second.second);
    } else {
      x.clear();
      y.clear();
      for (int j = 0; j < ini.size(); j++) {
        int now = ini[j];
        if (dance[now].first == 1) {
          x.push_back(make_pair(dance[now].second.first, now));
        } else {
          y.push_back(make_pair(dance[now].second.first, now));
        }
      }
      sort(x.begin(), x.end());
      sort(y.begin(), y.end());
      int mins = min(x.size(), y.size());
      for (int j = 0; j < mins; j++) {
        finish[y[y.size() - j - 1].second] = x[j].second;
        finish[x[x.size() - j - 1].second] = y[j].second;
      }
      if (x.size() > y.size()) {
        for (int j = 0; j < x.size() - mins; j++) {
          finish[x[j].second] = x[mins + j].second;
        }
      } else {
        for (int j = 0; j < y.size() - mins; j++) {
          finish[y[j].second] = y[mins + j].second;
        }
      }
      ini.clear();
      ini.push_back(event[i].second.second);
    }
  }
  for (int i = 1; i <= n; i++) {
    int ini = finish[i];
    if (dance[ini].first == 1) {
      cout << dance[ini].second.first << " " << h << "\n";
    } else {
      cout << w << " " << dance[ini].second.first << "\n";
    }
  }
}
