#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> d(n);
  vector<int> s(n);
  for (int i = 0; i < n; ++i) cin >> d[i] >> s[i];
  int m = 0;
  for (int i = 0; i < n; ++i) m += d[i];
  m /= 2;
  queue<int> Q;
  vector<pair<int, int> > answer;
  for (int i = 0; i < n; ++i)
    if (d[i] == 1) Q.push(i);
  while (!Q.empty()) {
    int v = Q.front();
    Q.pop();
    if (d[v] != 1) continue;
    d[v]--;
    int nextV = s[v];
    s[nextV] ^= v;
    answer.push_back(make_pair(v, nextV));
    d[nextV]--;
    if (d[nextV] == 1) {
      Q.push(nextV);
    }
  }
  cout << m << "\n";
  for (int i = 0; i < answer.size(); ++i)
    printf("%ld %ld", answer[i].first, answer[i].second), printf("\n");
  return 0;
}
