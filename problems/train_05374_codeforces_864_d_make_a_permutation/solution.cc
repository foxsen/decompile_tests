#include <bits/stdc++.h>
using namespace std;
long long mark[100050];
vector<long long> t1;
vector<long long> t2;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n;
  cin >> n;
  long long a[n + 4];
  priority_queue<pair<long long, long long>> pq;
  priority_queue<long long> tbp;
  map<long long, long long> placed;
  long long swaps = 0;
  map<long long, long long> th;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    th[a[i]]++;
  }
  for (long long i = 1; i <= n; i++) {
    if (th[a[i]] > 1) {
      pq.push({-i, a[i]});
    }
    if (th[i] == 0) {
      tbp.push(-i);
    }
    if (th[a[i]] == 1) {
      placed[a[i]] = 1;
    }
  }
  while (!tbp.empty()) {
    long long toB = -tbp.top();
    pair<long long, long long> iter = pq.top();
    iter.first = -iter.first;
    if (placed[iter.second] == 1) {
      a[iter.first] = toB;
      th[iter.second]--;
      pq.pop();
      tbp.pop();
      swaps++;
    } else if (th[a[iter.first]] == 1) {
      placed[iter.second] = 1;
      pq.pop();
    } else if (toB < iter.second) {
      th[iter.second]--;
      a[iter.first] = toB;
      tbp.pop();
      pq.pop();
      swaps++;
    } else {
      placed[a[iter.first]] = 1;
      th[a[iter.first]]--;
      pq.pop();
    }
  }
  cout << swaps << '\n';
  for (long long i = 1; i <= n; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
