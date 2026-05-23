#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int> > A(n);
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i].first >> A[i].second;
    ans[i] = A[i].first;
  }
  int count = 0, ololo = 0, lastx;
  int i = 0, j;
  while (i < n) {
    j = i;
    map<int, int> B;
    map<int, vector<int> > C;
    while (j < n && count < m) {
      B[A[j].second]++;
      C[A[j].second].push_back(j);
      count++, j++;
    }
    int time = max(ololo, A[j - 1].first), prev = 0;
    for (map<int, int>::iterator z = B.begin(); z != B.end(); z++) {
      time += z->first - prev;
      prev = z->first;
      for (int p = 0; p < C[z->first].size(); p++) ans[C[z->first][p]] = time;
      time += 1 + z->second / 2;
    }
    count = 0;
    ololo = time + prev;
    i = j;
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
