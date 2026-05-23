#include <bits/stdc++.h>
inline int getInt() {
  int s;
  scanf("%d", &s);
  return s;
}
using namespace std;
int main() {
  const int n = getInt();
  const int m = getInt();
  vector<set<int> > o(n);
  vector<vector<pair<int, int> > > v(n);
  for (int i = 0; i < (int)(m); i++) {
    const int a = getInt() - 1;
    const int b = getInt() - 1;
    const int c = getInt();
    v[a].push_back(make_pair(b, c));
    v[b].push_back(make_pair(a, c));
  }
  for (int i = 0; i < (int)(n); i++) {
    const int k = getInt();
    for (int j = 0; j < (int)(k); j++) o[i].insert(getInt());
  }
  vector<int> memo(n);
  priority_queue<pair<long long, int>, vector<pair<long long, int> >,
                 greater<pair<long long, int> > >
      pq;
  pq.push(make_pair(0, 0));
  while (pq.size()) {
    const pair<long long, int> d = pq.top();
    pq.pop();
    long long cost = d.first;
    const int pos = d.second;
    if (memo[pos]) continue;
    memo[pos] = 1;
    if (pos == n - 1) {
      cout << cost << endl;
      return 0;
    }
    while (o[pos].count(cost)) cost++;
    for (int i = 0; i < (int)(v[pos].size()); i++) {
      const int next = v[pos][i].first;
      if (memo[next] == 0) {
        const long long cc = cost + v[pos][i].second;
        pq.push(make_pair(cc, next));
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
