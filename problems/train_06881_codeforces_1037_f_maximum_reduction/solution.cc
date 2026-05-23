#include <bits/stdc++.h>
using namespace std;
using li = long long;
using ld = long double;
void solve(bool);
signed main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  solve(true);
  return 0;
}
vector<vector<li>> ed;
vector<vector<li>> e;
vector<li> depth;
vector<li> parent;
void dfs(li v, li p = -1) {
  for (li u : ed[v]) {
    if (u == p) continue;
    depth[u] = depth[v] + 1;
    parent[u] = v;
    e[v].push_back(u);
    dfs(u, v);
  }
}
const li MOD = 1e9 + 7;
void add(li& to, li x) {
  to += x;
  if (to >= MOD) {
    to -= MOD;
  }
}
struct maxcalc {
  vector<pair<li, li>> pushTo, popFrom;
  li mx(vector<pair<li, li>>& vec) {
    return vec.empty() ? 0 : vec.back().second;
  }
  void push(vector<pair<li, li>>& to, li x) {
    li y = max(x, mx(to));
    to.emplace_back(x, y);
  }
  void push(li x) { push(pushTo, x); }
  void pop() {
    if (popFrom.empty()) {
      while (!pushTo.empty()) {
        li x = pushTo.back().first;
        pushTo.pop_back();
        push(popFrom, x);
      }
    }
    assert(!popFrom.empty());
    popFrom.pop_back();
  }
  li get() { return max(mx(pushTo), mx(popFrom)); }
};
struct sufmax {
  vector<pair<li, li>> nums;
  li value = 0;
  void doAdd(li x, li cnt) {
    while (!nums.empty() && nums.back().first < x) {
      cnt += nums.back().second;
      add(value, MOD - (nums.back().second * nums.back().first) % MOD);
      nums.pop_back();
    }
    nums.emplace_back(x, cnt);
    add(value, x * cnt % MOD);
  }
};
li z(vector<li> a, li k) {
  li n = a.size();
  if (n < k) {
    return 0;
  }
  li ans = 0;
  vector<li> b;
  for (li i = 0; i + k - 1 < n; ++i) {
    li mx = 0;
    for (li j = i; j < i + k; ++j) {
      mx = max(mx, a[j]);
    }
    ans += mx;
    b.push_back(mx);
  }
  return ans + z(b, k);
}
void solve(bool __attribute__((unused)) read) {
  li n, k;
  if (read) {
    cin >> n >> k;
  } else {
    n = rand() % 10 + 2;
    k = min<li>(n, rand() % 10 + 2);
  }
  --k;
  vector<li> a(n);
  for (li i = 0; i < n; ++i) {
    if (read) {
      cin >> a[i];
    } else {
      a[i] = rand() % 10 + 1;
    }
  }
  vector<maxcalc> maxcalcs(n / k + 1);
  for (li i = 0; i < n; ++i) {
    maxcalcs[i / k].push(a[i]);
  }
  li answer = 0;
  for (li start = 0; start < k; ++start) {
    sufmax s;
    li last = start;
    for (li i = start; i < n; i += k) {
      last = max(last, i);
    }
    for (li i = last; i >= start; i -= k) {
      if (i + k - 1 >= n) {
        continue;
      }
      s.doAdd(maxcalcs[i / k].get(), 1);
      if (i > 0) {
        s.doAdd(a[i - 1], 0);
        add(answer, s.value);
      }
    }
    for (li t = start; t < n; t += k) {
      maxcalcs[t / k].pop();
      if (t + k < n) {
        maxcalcs[t / k].push(a[t + k]);
      }
    }
  }
  cout << answer << endl;
}
