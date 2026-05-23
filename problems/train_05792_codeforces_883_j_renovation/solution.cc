#include <bits/stdc++.h>
using namespace std;
const long long nn = 100005;
struct Building {
  long long ren, dem;
  inline bool operator<(const Building &x) const { return ren < x.ren; }
};
Building bui[nn];
priority_queue<long long, vector<long long>, greater<long long> > heap;
long long n, m, money[nn], ans;
long long pnt, now, tmp, tmp1 = 1;
int main() {
  scanf("%d%d", &n, &m);
  now = n;
  money[0] = 2147483647;
  for (register long long i = 1; i <= n; i++) {
    scanf("%d", &money[i]);
  }
  for (register long long i = 1; i <= m; i++) {
    scanf("%d", &bui[i].ren);
  }
  for (register long long i = 1; i <= m; i++) {
    scanf("%d", &bui[i].dem);
  }
  sort(bui + 1, bui + m + 1);
  while (now >= 1) {
    tmp = 0;
    pnt = now;
    while (money[pnt] <= money[now]) {
      tmp += money[pnt];
      pnt--;
    }
    long long j = tmp1;
    while (j <= m && bui[j].ren <= money[now]) {
      heap.push(bui[j].dem);
      j++;
    }
    now = pnt;
    tmp1 = j;
    while (heap.empty() == false) {
      if (tmp >= heap.top()) {
        tmp -= heap.top();
        heap.pop();
        ans++;
      } else {
        tmp = heap.top() - tmp;
        heap.pop();
        heap.push(tmp);
        break;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
