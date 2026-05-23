#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, num, x, y, ans;
  while (~scanf("%d", &n)) {
    priority_queue<int, vector<int>, greater<int> > q;
    ans = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &num);
      q.push(num);
    }
    for (;;) {
      if (q.size() == 1) {
        ans++;
        break;
      }
      x = q.top();
      q.pop();
      y = q.top();
      if (x != y) {
        ans++;
      }
      if (x == y) {
        q.pop();
        q.push(++x);
      }
    }
    printf("%d\n", ans);
  }
}
