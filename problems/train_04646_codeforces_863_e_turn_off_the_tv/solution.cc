#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long n, ai, bi;
  set<long long> bad;
  cin >> n;
  vector<pair<long long, long long> > events;
  for (long long i = 0; i < n; i++) {
    cin >> ai >> bi;
    events.push_back(make_pair(ai, i));
    events.push_back(make_pair(bi, i));
  }
  sort(events.begin(), events.end());
  long long lev = -1;
  set<long long> opens;
  bool close = false;
  for (long long i = 0; i < events.size(); i++) {
    long long date = events[i].first;
    if (date != lev) {
      bool copen = false;
      set<long long> counters;
      long long u = i;
      while (u < 2 * n && events[u].first == date) {
        counters.insert(events[u].second);
        if (!opens.count(events[u].second)) {
          copen = true;
        }
        u++;
      }
      if ((!copen || !close || date - lev > 1) && opens.size() == 1) {
        long long vv = *(opens.begin());
        bad.insert(vv);
      }
      if (counters.size() == 1 && opens.size() == 0) {
        long long vv = *(counters.begin());
        bad.insert(vv);
      }
      lev = date;
      close = false;
    }
    long long el = events[i].second;
    if (opens.count(el)) {
      set<long long>::iterator it = opens.upper_bound(el - 1);
      opens.erase(it);
      close = true;
    } else {
      opens.insert(el);
    }
  }
  if (bad.size() == n) {
    cout << -1 << endl;
  } else {
    for (long long i = 0; i < n; i++) {
      if (!bad.count(i)) {
        cout << i + 1 << endl;
        return 0;
      }
    }
  }
  return 0;
}
