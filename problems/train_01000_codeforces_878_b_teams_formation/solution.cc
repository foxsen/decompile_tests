#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, b;
  scanf("%d%d%d", &n, &k, &b);
  stack<pair<int, int> > st;
  long long ans = (long long)n * b;
  for (int i = 0, a; i < n; i++) {
    scanf("%d", &a);
    if (st.size() && st.top().first == a) {
      st.top().second++;
      if (st.top().second == k) ans -= (long long)k * b, st.pop();
    } else
      st.push({a, 1});
  }
  deque<int> q;
  while (st.size()) {
    while (st.top().second) q.push_front(st.top().first), st.top().second--;
    st.pop();
  }
  while (q.size()) {
    int c = 0, x = q.front();
    while (q.size() && q.front() == x) c++, q.pop_front();
    while (q.size() && q.back() == x) c++, q.pop_back();
    if (!q.size()) {
      long long am = (long long)b * c;
      if (am % k == 0) return puts("0"), 0;
      ans -= (am / k) * k;
    } else if (c % k == 0) {
      ans -= (long long)c * (b - 1);
    } else {
      ans -= (c / k) * k * (long long)(b - 1);
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
