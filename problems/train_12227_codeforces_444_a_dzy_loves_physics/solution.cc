#include <bits/stdc++.h>
using namespace std;
const int MX = 1000 + 100;
vector<pair<int, int> > G[MX];
bitset<MX> bs;
struct data {
  int v, f, t;
  bool operator<(const data& in) const { return v < in.v; }
};
int val[MX];
int main() {
  srand(time(0));
  int n, e;
  cin >> n >> e;
  if (e == 0) {
    cout << "0.000000000000000";
    exit(0);
  }
  for (int i = 1; i < n + 1; i++) {
    cin >> val[i];
  }
  while (e--) {
    int s, d, v;
    cin >> s >> d >> v;
    G[s].push_back({d, v});
    G[d].push_back({s, v});
  }
  long double ans = 0;
  for (int i = 1; i < n + 1; i++) {
    long double v_sum = val[i], e_sum = 0;
    long double local_max = 0;
    bs.reset();
    priority_queue<data> pq;
    for (auto it : G[i]) pq.push((data){-it.second, i, it.first});
    bs[i] = true;
    while (pq.size()) {
      int next = pq.top().t;
      int from = pq.top().f;
      int vl = pq.top().v;
      pq.pop();
      if (bs[next]) continue;
      bs[next] = true;
      if ((v_sum + val[next]) / (e_sum - vl) > ans) {
        local_max = max((v_sum + val[next]) / (e_sum - vl), local_max);
        e_sum -= vl;
        v_sum += val[next];
        for (auto it : G[next]) {
          pq.push((data){-it.second, next, it.first});
        }
      }
    }
    ans = max(ans, local_max);
  }
  cout << fixed << setprecision(15) << ans;
}
