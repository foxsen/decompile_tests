#include <bits/stdc++.h>
using namespace std;
long long visited[2000] = {0}, dist[2000] = {0};
vector<long long> vg[2000];
map<string, long long> M1;
void bfs(long long current) {
  long long i;
  long long x, y;
  queue<long long> q;
  q.push(current);
  visited[current] = 1;
  while (!q.empty()) {
    x = q.front();
    q.pop();
    visited[x] = 1;
    for (i = 0; i < vg[x].size(); i++) {
      y = vg[x][i];
      if (visited[y] == 0) {
        visited[y] = 1;
        dist[y] = dist[x] + 1;
        q.push(y);
      }
    }
  }
}
void lakshay() {
  long long i, z = 0, c, d, y = 0, maxi = 0, x, l = 0, a, b, s = 0, j, m, n, p,
               q, k, r;
  bool ok = true;
  string S, S1, S2, A;
  cin >> n;
  vector<long long> v;
  b = 2;
  M1["polycarp"] = 1;
  for (i = 0; i < 3 * n; i++) {
    cin >> A;
    transform(A.begin(), A.end(), A.begin(), ::tolower);
    if (A != "reposted") {
      if (M1[A] == 0) M1[A] = b, b++;
      v.push_back(M1[A]);
    }
  }
  for (i = 0; i < v.size() - 1; i += 2) {
    vg[v[i]].push_back(v[i + 1]);
    vg[v[i + 1]].push_back(v[i]);
  }
  dist[1] = 1;
  bfs(1);
  for (i = 1; i <= b; i++) maxi = max(maxi, dist[i]);
  cout << maxi;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long num;
  num = 1;
  while (num--) {
    lakshay();
    cout << "\n";
  }
  return 0;
}
