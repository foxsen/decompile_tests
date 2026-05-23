#include <bits/stdc++.h>
using namespace std;
priority_queue<long long, vector<long long>, greater<long long> > q;
inline long long mx(long long a, long long b) { return a > b ? a : b; }
int main() {
  long long n, k;
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (long long i = 1; i <= k; i++) {
    q.push(0);
  }
  for (long long i = 1; i <= n; i++) {
    long long x, y;
    cin >> x >> y;
    long long z = mx(x, q.top()) + y;
    cout << z << endl;
    q.pop();
    q.push(z);
  }
  return 0;
}
