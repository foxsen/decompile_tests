#include <bits/stdc++.h>
using namespace std;
priority_queue<int> pq;
int main() {
  int n;
  scanf("%d", &n);
  long long res = 0;
  int x;
  scanf("%d", &x);
  pq.push(x);
  for (int i = 1; i < n; ++i) {
    scanf("%d", &x);
    pq.push(x);
    if (pq.top() > x) {
      res += pq.top() - x;
      pq.pop();
      pq.push(x);
    }
  }
  printf("%lld", res);
  return 0;
}
