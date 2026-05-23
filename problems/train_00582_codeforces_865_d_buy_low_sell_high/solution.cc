#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> > s;
int main() {
  int n;
  while (~scanf("%d", &n)) {
    int a;
    long long ss = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a);
      if (!s.empty() && s.top() < a) {
        ss += (a - s.top());
        s.pop();
        s.push(a);
      }
      s.push(a);
    }
    printf("%lld\n", ss);
  }
  return 0;
}
