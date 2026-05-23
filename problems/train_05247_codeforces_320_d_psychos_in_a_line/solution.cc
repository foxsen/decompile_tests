#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
const int N = 100100;
int a[N];
bool b[N];
set<int> st;
vector<int> v1;
vector<int> v2;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= n; i++) st.insert(i), b[i] = true;
  for (int i = 1; i < n; i++)
    if (a[i] > a[i + 1]) v1.push_back(i);
  int Ans = 0;
  while (!v1.empty()) {
    debug() << " ["
            << "v1"
               ": "
            << (v1) << "] ";
    debug() << " ["
            << "st"
               ": "
            << (st) << "] ";
    while (!v1.empty()) {
      int x = v1.back();
      v1.pop_back();
      int y = *st.upper_bound(x);
      st.erase(y);
      if (!v2.empty() && v2.back() == y) v2.pop_back();
      auto it = st.upper_bound(x);
      if (it != st.end() && a[*it] < a[x]) v2.push_back(x);
    }
    reverse(v2.begin(), v2.end());
    swap(v1, v2);
    v2.clear();
    Ans++;
  }
  cout << Ans;
}
