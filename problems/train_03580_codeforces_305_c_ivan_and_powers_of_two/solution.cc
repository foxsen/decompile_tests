#include <bits/stdc++.h>
using namespace std;
vector<long long> A;
struct node {
  long long u;
  bool operator<(const node& rhs) const { return u > rhs.u; }
};
int main() {
  int n;
  while (~scanf("%d", &n)) {
    priority_queue<node> Q;
    long long aa;
    node tt;
    for (int i = 1; i <= n; i++) {
      scanf("%I64d", &aa);
      tt.u = aa;
      Q.push(tt);
    }
    A.clear();
    node a;
    a = Q.top();
    Q.pop();
    node b;
    while (!Q.empty()) {
      b = Q.top();
      Q.pop();
      if (a.u == b.u) {
        b.u++;
        Q.push(b);
        a = Q.top();
        Q.pop();
        continue;
      }
      A.push_back(a.u);
      a = b;
    }
    A.push_back(a.u);
    aa = -1;
    long long ans = 0;
    for (int i = 0; i < A.size(); i++) {
      ans += A[i] - aa - 1;
      aa = A[i];
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
