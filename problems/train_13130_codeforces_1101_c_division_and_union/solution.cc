#include <bits/stdc++.h>
using namespace std;
int main() {
  int q = 0;
  cin >> q;
  vector<pair<pair<int, int>, int>> intervals;
  for (int i = 0; i < q; i++) {
    int n;
    cin >> n;
    intervals.resize(n);
    for (int j = 0; j < n; j++) {
      cin >> intervals[j].first.first >> intervals[j].first.second;
      intervals[j].second = j;
    }
    sort(intervals.begin(), intervals.end());
    int maxend = intervals[0].first.second;
    bool possible = false;
    int pivot = 0;
    for (int j = 1; j < intervals.size(); j++) {
      if (maxend < intervals[j].first.first) {
        possible = true;
        pivot = intervals[j].first.first;
        break;
      } else if (maxend < intervals[j].first.second) {
        maxend = intervals[j].first.second;
      }
    }
    if (!possible) {
      cout << "-1\n";
      continue;
    }
    vector<int> out(n);
    for (int j = 0; j < n; j++) {
      int originalIndex = intervals[j].second;
      int begin = intervals[j].first.first;
      int end = intervals[j].first.second;
      if (end < pivot) {
        out[originalIndex] = 1;
      } else if (begin >= pivot) {
        out[originalIndex] = 2;
      }
    }
    for (int j = 0; j < n; j++) {
      cout << out[j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
