#include <bits/stdc++.h>
using namespace std;
long long c[201000];
priority_queue<long long, vector<long long>, greater<long long> > que;
int main() {
  int n;
  scanf("%d", &n);
  long long s = 0;
  for (int i = 0; i < n; i++) {
    long long x;
    scanf("%lld", &x);
    s += x;
    que.push(x);
  }
  long long ans = 0;
  if (n % 2 == 0) {
    long long x1 = que.top();
    que.pop();
    long long x2 = que.top();
    que.pop();
    que.push(x1 + x2);
    ans += x1 + x2;
  }
  while (que.size() > 1) {
    long long x1 = que.top();
    que.pop();
    long long x2 = que.top();
    que.pop();
    long long x3 = que.top();
    que.pop();
    que.push(x1 + x2 + x3);
    ans += x1 + x2 + x3;
  }
  cout << ans << endl;
  return 0;
}
