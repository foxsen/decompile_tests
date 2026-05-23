#include <bits/stdc++.h>
inline int sbt(int x) { return __builtin_popcount(x); }
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
vector<pair<int, pair<int, int>>> queries;
int a[100013];
int block_sz = 317;
int n, q, l, r;
vector<int> ans;
int freq[100013];
int block_a, block_b, quer_ans;
bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
  block_a = (a.first) / block_sz;
  block_b = (b.first) / block_sz;
  if (block_a != block_b) {
    return block_a < block_b;
  }
  return a.second.first < b.second.first;
}
void rem(int x) {
  if (x > n) return;
  freq[x]--;
  if (freq[x] == x) {
    quer_ans++;
  } else if (freq[x] == (x - 1)) {
    quer_ans--;
  }
}
void add(int x) {
  if (x > n) return;
  freq[x]++;
  if (freq[x] == (x + 1))
    quer_ans--;
  else if (freq[x] == x)
    quer_ans++;
}
int main() {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  cin >> n >> q;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < q; i++) {
    cin >> l >> r;
    queries.push_back(make_pair(l - 1, make_pair(r - 1, i)));
  }
  ans.resize(q);
  sort(queries.begin(), queries.end(), cmp);
  int mo_rgt = -1, mo_lft = 0;
  for (auto query : queries) {
    l = query.first;
    r = query.second.first;
    while (mo_rgt < r) {
      mo_rgt++;
      add(a[mo_rgt]);
    }
    while (mo_rgt > r) {
      rem(a[mo_rgt]);
      mo_rgt--;
    }
    while (mo_lft > l) {
      mo_lft--;
      add(a[mo_lft]);
    }
    while (mo_lft < l) {
      rem(a[mo_lft]);
      mo_lft++;
    }
    ans[query.second.second] = quer_ans;
  }
  for (auto res : ans) cout << res << endl;
  return 0;
}
