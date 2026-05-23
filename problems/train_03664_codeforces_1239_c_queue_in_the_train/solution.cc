#include <bits/stdc++.h>
using namespace std;
struct FenwickTree {
  FenwickTree() { this->n = 0; }
  void init(int n) {
    this->n = n;
    a.clear();
    a.insert(a.begin(), n + 3, 0);
  }
  FenwickTree(int n) { init(n); }
  int query(int i) {
    if (i == 0) {
      return 0;
    }
    int res = 0;
    while (i > 0) {
      res += a[i];
      i -= lowbit(i);
    }
    return res;
  }
  void update(int i, int value) {
    while (i <= n) {
      a[i] += value;
      i += lowbit(i);
    }
  }
  int lowbit(int k) { return k & (-k); }
  vector<int> a;
  int n;
};
const int N = 1e5 + 7;
long long a[N];
long long ans[N];
int main() {
  int n;
  long long p;
  scanf("%d%lld", &n, &p);
  set<int> S;
  deque<int> Q;
  deque<pair<int, int> > vec;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    vec.push_back(make_pair(a[i], i));
  }
  FenwickTree tr(n);
  sort(vec.begin(), vec.end());
  long long curTime = 0;
  long long waitTime = 0;
  while (!vec.empty() || !Q.empty() || !S.empty()) {
    long long tV = 1e18;
    long long tQ = 1e18;
    if (!vec.empty()) {
      tV = vec.front().first;
    }
    if (!Q.empty()) {
      tQ = curTime + p - waitTime;
    }
    if (tQ <= tV) {
      curTime = tQ;
      waitTime = 0;
      int idx = Q.front();
      Q.pop_front();
      ans[idx] = curTime;
      tr.update(idx, -1);
      int idx1 = 1e9;
      int idx2 = 1e9;
      if (tQ == tV) {
        idx1 = vec[0].second;
      }
      if (!S.empty()) {
        idx2 = *S.begin();
      }
      idx = min(idx1, idx2);
      if (idx == (int)1e9) {
        continue;
      }
      int cnt = tr.query(idx - 1);
      if (cnt == 0) {
        Q.push_back(idx);
        tr.update(idx, 1);
        if (idx1 < idx2) {
          vec.pop_front();
        } else {
          S.erase(S.begin());
        }
      } else if (idx1 < idx2) {
        S.insert(idx1);
        vec.pop_front();
      }
    } else {
      if (!Q.empty()) {
        waitTime += tV - curTime;
      }
      curTime = tV;
      int idx = vec.front().second;
      int cnt = tr.query(idx - 1);
      if (cnt == 0) {
        Q.push_back(idx);
        tr.update(idx, 1);
      } else {
        S.insert(idx);
      }
      vec.pop_front();
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%lld\n", ans[i]);
  }
  return 0;
}
