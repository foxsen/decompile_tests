#include <bits/stdc++.h>
using namespace std;
int n, m;
long long num[2];
map<int, int> cnt[2];
int best_dist = -1;
long long best_total = 0;
void check_val(int dist, long long total) {
  if (total == 0) return;
  if (dist > best_dist)
    best_dist = dist, best_total = total;
  else if (dist == best_dist)
    best_total += total;
}
void calc_equal(int i) {
  long long k = num[i];
  auto &a = cnt[i];
  if (a.size() == 1) {
    check_val(0, k * (k - 1) * (k - 2) / 6);
    return;
  }
  auto it0 = a.begin();
  auto it1 = --a.end();
  int dist = 2 * (it1->first - it0->first);
  long long c0 = it0->second, c1 = it1->second;
  long long total = c0 * c1 * (k - c0 - c1);
  total += c0 * (c0 - 1) / 2 * c1;
  total += c1 * (c1 - 1) / 2 * c0;
  check_val(dist, total);
}
void calc_unequal(int i, int j) {
  long long ki = num[i], kj = num[j];
  auto &ai = cnt[i], &aj = cnt[j];
  long long prev = 0;
  auto it = ai.begin();
  for (auto &val : aj) {
    while (it != ai.end() && it->first <= val.first) prev += it->second, it++;
    if (it != ai.end()) {
      int dist = 2 * (n - it->first + val.first);
      long long k = it->second;
      long long total = val.second * (k * (k - 1) / 2 + k * (ki - prev - k));
      check_val(dist, total);
    }
  }
  prev = 0;
  it = ai.begin();
  for (auto &val : aj) {
    while (it != ai.end() && it->first < val.first) prev += it->second, it++;
    if (it != ai.begin()) it--, prev -= it->second;
    if (it->first < val.first) {
      int dist = 2 * (n - val.first + it->first);
      long long k = it->second;
      long long total = val.second * (k * (k - 1) / 2 + k * prev);
      check_val(dist, total);
    }
  }
  prev = 0;
  it = ai.begin();
  for (auto &val : aj) {
    while (it != ai.end() && it->first < val.first) prev += it->second, it++;
    if (it != ai.end()) {
      int dist = 2 * n;
      long long k = it->second;
      long long total = prev * (ki - prev);
      if (it->first == val.first)
        total += k * (k - 1) / 2 + k * (ki - prev - k);
      total *= val.second;
      check_val(dist, total);
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int s, f;
    scanf("%d%d", &s, &f);
    num[s]++;
    cnt[s][f]++;
  }
  for (int i = 0; i < 2; i++)
    if (num[i] > 2) calc_equal(i);
  for (int i = 0; i < 2; i++)
    if (num[i] > 1 && num[1 - i] > 0) calc_unequal(i, 1 - i);
  printf("%lld\n", best_total);
}
