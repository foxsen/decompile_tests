#include <bits/stdc++.h>
using namespace std;
bool visited[1001];
int main() {
  int n;
  cin >> n;
  vector<pair<int, pair<int, int> > > vp;
  for (int i = 0; i < n; i++) {
    int size, money;
    cin >> size >> money;
    vp.push_back(make_pair(money, make_pair(size, i + 1)));
  }
  int k;
  cin >> k;
  vector<pair<int, int> > capacities;
  for (int i = 0; i < k; i++) {
    int cap;
    cin >> cap;
    capacities.push_back(make_pair(cap, i + 1));
  }
  sort(vp.begin(), vp.end(), greater<pair<int, pair<int, int> > >());
  sort(capacities.begin(), capacities.end(), greater<pair<int, int> >());
  int accepted = 0, total = 0;
  vector<pair<int, int> > ans;
  for (int i = 0; i < n; i++) {
    int tosearch = vp[i].second.first;
    if (capacities.size() && tosearch <= capacities[0].first) {
      int low = -1, high = capacities.size(), mid;
      int needed = 1;
      while (high - low > 1) {
        mid = (high + low) / 2;
        if (capacities[mid].first == tosearch) {
          accepted++;
          total += vp[i].first;
          ans.push_back(make_pair(vp[i].second.second, capacities[mid].second));
          needed = 0;
          capacities.erase(capacities.begin() + mid);
          break;
        } else if (capacities[mid].first > tosearch)
          low = mid;
        else
          high = mid;
      }
      if (needed) {
        total += vp[i].first;
        accepted++;
        ans.push_back(make_pair(vp[i].second.second, capacities[low].second));
        capacities.erase(capacities.begin() + low);
      }
    }
  }
  cout << accepted << " " << total << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].first << " " << ans[i].second << endl;
  }
}
