#include <bits/stdc++.h>
using namespace std;
struct data {
  long long l, x, id, ans;
  data(long long _l, long long _x, long long _id) : l(_l), x(_x), id(_id){};
};
long long n, q;
long long a[100005];
vector<data> query;
set<long long> st;
long long ans = 1;
bool cmp(data &x, data &y) { return x.l < y.l; }
bool cmpID(data &x, data &y) { return x.id < y.id; }
const long long mod = 1e9 + 7;
vector<long long> pen;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  for (long long i = 1; i <= q; i++) {
    long long l, x;
    cin >> l >> x;
    query.push_back(data(l, x, i));
  }
  sort(query.begin(), query.end(), cmp);
  long long it = 0;
  st.insert(0);
  for (long long i = 1; i <= n; i++) {
    if (st.find(a[i]) == st.end()) {
      for (auto cur : st) pen.push_back(cur ^ a[i]);
      for (auto cur : pen) st.insert(cur);
      pen.clear();
    } else
      ans = (ans * 2) % mod;
    while (it != query.size() && query[it].l < i) it++;
    while (it != query.size() && query[it].l == i) {
      if (st.find(query[it].x) != st.end())
        query[it].ans = ans;
      else
        query[it].ans = 0;
      it++;
    }
  }
  sort(query.begin(), query.end(), cmpID);
  for (auto &cur : query) cout << cur.ans << '\n';
}
