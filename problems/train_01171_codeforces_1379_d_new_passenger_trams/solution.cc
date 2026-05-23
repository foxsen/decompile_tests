#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool common(int train, int startTime, int gap) {
  return (startTime > train && startTime < train + gap);
}
void solve() {
  int n, h, m, k;
  cin >> n >> h >> m >> k;
  vector<int> trains(n);
  for (auto &i : trains) {
    int x;
    cin >> x >> i;
  }
  vector<int> times, f(n), l(n);
  times.emplace_back(0);
  times.emplace_back(m / 2 + 1);
  for (int i = 0; i < n; i++) {
    f[i] = trains[i] + 1;
    l[i] = trains[i] + k - 1;
    while (f[i] >= m / 2) {
      f[i] -= m / 2;
    }
    while (l[i] >= m / 2) {
      l[i] -= m / 2;
    }
    times.emplace_back(f[i]);
    times.emplace_back(l[i] + 1);
  }
  {
    sort(times.begin(), times.end());
    times.erase(unique(times.begin(), times.end()), times.end());
  };
  h = (int)times.size();
  map<int, int> index;
  for (int i = 0; i < h; i++) {
    index[times[i]] = i;
  }
  vector<vector<int>> add(h), remove(h);
  for (int i = 0; i < n; i++) {
    if (f[i] > l[i]) {
      add[index[0]].emplace_back(i);
      remove[index[l[i] + 1]].emplace_back(i);
      add[index[f[i]]].emplace_back(i);
      remove[index[m / 2 + 1]].emplace_back(i);
    } else {
      add[index[f[i]]].emplace_back(i);
      remove[index[l[i] + 1]].emplace_back(i);
    }
  }
  int curr = 0, best = n, bestIndex = 0;
  for (int i = 0; times[i] < m / 2; i++) {
    curr += (int)add[i].size() - (int)remove[i].size();
    if (curr < best) {
      best = curr;
      bestIndex = i;
    }
  }
  int startTime = times[bestIndex];
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    bool overlap = 0;
    if (common(trains[i], startTime, k) ||
        common(trains[i], startTime + m / 2, k) ||
        common(trains[i], startTime + m, k)) {
      overlap = 1;
    }
    if (overlap) {
      ans.emplace_back(i + 1);
    }
  }
  cout << ans.size() << " " << startTime << endl;
  for (auto i : ans) {
    cout << i << " ";
  }
  cout << endl;
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
