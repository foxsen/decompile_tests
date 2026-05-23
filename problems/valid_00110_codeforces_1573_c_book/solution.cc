#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  long long n, k;
  long long ip;
  while (t--) {
    cin >> n;
    vector<int> graph[n + 1];
    vector<int> indegree(n + 1);
    for (int i = 0; i < n; i++) {
      cin >> k;
      indegree[i + 1] = k;
      for (int j = 0; j < k; j++) {
        cin >> ip;
        graph[ip].push_back(i + 1);
      }
    }
    set<int> q1;
    set<int> q2;
    for (int i = 1; i <= n; i++) {
      if (indegree[i] == 0) {
        q1.insert(i);
      }
    }
    long long x;
    long long yay = 0;
    long long cnt = 0;
    while (!q1.empty() || !q2.empty()) {
      if (!q1.empty()) cnt++;
      while (!q1.empty()) {
        yay++;
        x = *(q1.begin());
        q1.erase(q1.begin());
        for (auto y : graph[x]) {
          --indegree[y];
          if (indegree[y] == 0) {
            if (y > x)
              q1.insert(y);
            else {
              q2.insert(y);
            }
          }
        }
      }
      if (!q2.empty()) cnt++;
      while (!q2.empty()) {
        yay++;
        x = *(q2.begin());
        q2.erase(q2.begin());
        for (auto y : graph[x]) {
          --indegree[y];
          if (indegree[y] == 0) {
            if (y > x)
              q2.insert(y);
            else {
              q1.insert(y);
            }
          }
        }
      }
    }
    if (yay != n) {
      cout << -1 << endl;
    } else {
      cout << cnt << endl;
    }
  }
  return 0;
}
