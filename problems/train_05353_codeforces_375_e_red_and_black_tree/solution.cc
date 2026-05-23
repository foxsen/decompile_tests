#include <bits/stdc++.h>
using namespace std;
vector<vector<double> > m;
void change(int index, int a);
double simplex();
void solve(int n, int x, vector<bool>& c, vector<vector<long long> >& dis,
           int count);
int main() {
  int n, x;
  int count = 0;
  cin >> n >> x;
  vector<bool> c(n);
  bool b;
  for (int i = 0; i < n; i++) {
    cin >> b;
    c[i] = b;
    if (b == 1) count++;
  }
  vector<vector<long long> > dis;
  for (int i = 0; i < n; i++) {
    vector<long long> temp(n, 1e12);
    dis.push_back(temp);
  }
  int u, v;
  long long w;
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v >> w;
    dis[u - 1][v - 1] = w;
    dis[v - 1][u - 1] = w;
  }
  for (int i = 0; i < n; i++) {
    dis[i][i] = 0;
  }
  solve(n, x, c, dis, count);
  return 0;
}
void change(int index, int a) {
  int n = m.size();
  int n2 = m[0].size();
  for (int i = 0; i < n; i++) {
    if (i == index || (m[i][a] >= 0 && m[i][a] < 1e-9)) continue;
    for (int j = 0; j < n2; j++) {
      if (j == a) {
        continue;
      }
      m[i][j] = m[i][j] - m[index][j] * m[i][a] / m[index][a];
    }
    m[i][a] = 0;
  }
  for (int i = 0; i < n; i++) {
    m[index][i] /= fabs(m[index][a]);
  }
}
double simplex() {
  int n = m.size();
  int n2 = m[0].size();
  while (1) {
    double max = -1;
    int a = -1;
    for (int i = 0; i < n2 - 1; i++) {
      if (m[0][i] < 1e-9) continue;
      if (m[0][i] > max) {
        max = m[0][i];
        a = i;
      }
    }
    if (max + 1 < 1e-9) {
      return m[0][n2 - 1];
    }
    double min = 1e9;
    int index = -1;
    for (int i = 1; i < n; i++) {
      if (m[i][a] < 1e-9) continue;
      double t = m[i][n2 - 1] / m[i][a];
      if (t < 0) continue;
      if (min > t) {
        min = t;
        index = i;
      }
    }
    if (index == -1) return 1;
    change(index, a);
  }
}
void solve(int n, int x, vector<bool>& c, vector<vector<long long> >& dis,
           int count) {
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    }
  }
  vector<double> d(2 * n + 2, 0);
  for (int i = 0; i < n; i++) {
    d[i] = 1;
  }
  for (int i = n; i < 2 * n; i++) {
    d[i] = -1;
  }
  d[2 * n] = -count;
  d[2 * n + 1] = 0;
  m.push_back(d);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (dis[j][i] <= x)
        d[j] = 1;
      else
        d[j] = 0;
    }
    for (int j = n; j < 2 * n; j++) d[j] = 0;
    d[i + n] = -1;
    d[2 * n] = -1;
    d[2 * n + 1] = !c[i];
    m.push_back(d);
  }
  double result = simplex();
  if (result > 0)
    cout << -1 << endl;
  else
    cout << int(-result + 0.5) << endl;
}
