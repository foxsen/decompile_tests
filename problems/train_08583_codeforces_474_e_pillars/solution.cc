#include <bits/stdc++.h>
int32_t* data;
int32_t* segtree;
void build(int32_t node, int32_t left, int32_t right) {
  if (right - left == 1) {
    segtree[node] = left;
    return;
  }
  int32_t m = (left + right) / 2;
  build(node * 2 + 1, left, m);
  build(node * 2 + 2, m, right);
  segtree[node] = data[segtree[node * 2 + 1]] > data[segtree[node * 2 + 2]]
                      ? segtree[node * 2 + 1]
                      : segtree[node * 2 + 2];
}
void update(int32_t node, int32_t left, int32_t right, int32_t ind) {
  if (left > ind || right <= ind) return;
  if (right - left == 1) {
    segtree[node] = left;
    return;
  }
  int32_t m = (left + right) / 2;
  update(node * 2 + 1, left, m, ind);
  update(node * 2 + 2, m, right, ind);
  segtree[node] = data[segtree[node * 2 + 1]] > data[segtree[node * 2 + 2]]
                      ? segtree[node * 2 + 1]
                      : segtree[node * 2 + 2];
}
int32_t combine(int32_t ind1, int32_t ind2) {
  if (ind1 == -1) return ind2;
  if (ind2 == -1) return ind1;
  return data[ind1] > data[ind2] ? ind1 : ind2;
}
int32_t query(int32_t node, int32_t left, int32_t right, int32_t query_left,
              int32_t query_right) {
  if (left >= query_right || right <= query_left) return -1;
  if (left >= query_left && right <= query_right) {
    return segtree[node];
  }
  int32_t m = (left + right) / 2;
  int32_t res_left = query(node * 2 + 1, left, m, query_left, query_right);
  int32_t res_right = query(node * 2 + 2, m, right, query_left, query_right);
  return combine(res_left, res_right);
}
int main() {
  int32_t n, d;
  std::cin >> n >> d;
  int64_t* arr = new int64_t[n];
  for (int32_t i = 0; i < n; i++) std::cin >> arr[i];
  std::set<int64_t> all;
  for (int32_t i = 0; i < n; i++) all.insert(arr[i]);
  std::map<int64_t, int32_t> to_compressed;
  int32_t cur = 0;
  for (auto it = all.begin(); it != all.end(); it++) to_compressed[*it] = cur++;
  int32_t* dp = new int32_t[to_compressed.size() + 5];
  for (int32_t i = 0; i < to_compressed.size() + 5; i++) dp[i] = 0;
  data = dp;
  segtree = new int32_t[4 * (to_compressed.size() + 5)];
  build(0, 0, to_compressed.size() + 5);
  int32_t* prev = new int32_t[n];
  for (int32_t i = 0; i < n; i++) prev[i] = -1;
  std::map<int32_t, int32_t> last;
  for (int32_t i = 0; i < n; i++) {
    auto it = all.upper_bound(arr[i] - d);
    int32_t pref_len = 0;
    if (it != all.begin()) {
      it--;
      pref_len = to_compressed[*it] + 1;
    }
    it = all.lower_bound(arr[i] + d);
    int32_t first_ok = -1;
    if (it != all.end()) {
      first_ok = to_compressed[*it];
    }
    int32_t max_val = to_compressed.size() + 4;
    if (pref_len != 0)
      max_val =
          combine(max_val, query(0, 0, to_compressed.size() + 5, 0, pref_len));
    if (first_ok != -1)
      max_val = combine(max_val, query(0, 0, to_compressed.size() + 5, first_ok,
                                       to_compressed.size() + 5));
    dp[to_compressed[arr[i]]] =
        std::max(dp[to_compressed[arr[i]]], dp[max_val] + 1);
    if (last.find(max_val) != last.end()) prev[i] = last[max_val];
    update(0, 0, to_compressed.size() + 5, to_compressed[arr[i]]);
    last[to_compressed[arr[i]]] = i;
  }
  int32_t max_val = segtree[0];
  int32_t end = -1;
  for (int32_t i = n - 1; i >= 0; i--)
    if (to_compressed[arr[i]] == max_val) {
      end = i;
      break;
      ;
    }
  std::cout << dp[max_val] << "\n";
  int32_t cur2 = end;
  std::vector<int32_t> ans_ind;
  while (cur2 != -1) {
    ans_ind.push_back(cur2);
    cur2 = prev[cur2];
  }
  for (int32_t i = ans_ind.size() - 1; i >= 0; i--)
    std::cout << ans_ind[i] + 1 << " ";
  return 0;
}
