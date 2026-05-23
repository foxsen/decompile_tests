#include <bits/stdc++.h>
using namespace std;
int main() {
  size_t n;
  cin >> n;
  vector<int64_t> a;
  copy_n(istream_iterator<int64_t>(cin), n, back_inserter(a));
  set<int64_t> values_set;
  for (size_t i = 0; i != n; ++i) {
    values_set.insert(a[i] - i);
  }
  vector<int64_t> values(values_set.begin(), values_set.end());
  vector<int64_t> cost_prev(values.size(), 0);
  vector<int64_t> cost(values.size(), 0);
  for (size_t i = 0; i != n; ++i) {
    for (size_t val_idx = 0; val_idx != values.size(); ++val_idx) {
      int64_t value = values[val_idx] + i;
      if (a[i] == value) {
        cost[val_idx] = cost_prev[val_idx];
      } else if (a[i] > value) {
        cost[val_idx] = cost_prev[val_idx] + a[i] - value;
      } else {
        assert(val_idx > 0);
        assert(value - values[val_idx - 1] > 0);
        cost[val_idx] =
            min(cost[val_idx - 1], cost_prev[val_idx] + value - a[i]);
      }
    }
    swap(cost, cost_prev);
  }
  cout << *min_element(cost_prev.begin(), cost_prev.end()) << "\n";
}
