#include <bits/stdc++.h>
using namespace std;
vector<long> a[100005];
long x[100004];
long b[100004];
long y[100004];
int v[100004];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long n, m;
  scanf("%ld", &(n));
  scanf("%ld", &(m));
  for (long i = 1; i <= m; i++) {
    long x, y;
    scanf("%ld", &(x));
    scanf("%ld", &(y));
    a[x].push_back(y);
    a[y].push_back(x);
  }
  long k = 0;
  queue<long> q;
  for (long i = 1; i <= n; i++) {
    scanf("%ld", &(x[i]));
    if (x[i] == 0) {
      v[i] = 1;
      q.push(i);
    }
  }
  while (!q.empty()) {
    long r = q.front();
    q.pop();
    if (b[r] == x[r]) {
      b[r]++;
      k++;
      y[k] = r;
      for (long j = 0; j < a[r].size(); j++) {
        long h = a[r][j];
        b[h]++;
        if (v[h] == 1 && b[h] == x[h]) {
          cout << "-1" << endl;
          return 0;
        }
        if (v[h] == 0 && b[h] == x[h]) {
          v[h] = 1;
          q.push(h);
        }
      }
    }
  }
  cout << k << endl;
  for (long i = 1; i <= k; i++) cout << y[i] << " ";
  cout << endl;
}
