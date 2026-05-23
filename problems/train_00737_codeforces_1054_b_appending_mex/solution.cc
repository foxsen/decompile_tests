#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
long long int XpowerY(long long int x, long long int y, long long int m) {
  long long int ans = 1;
  x = x % m;
  while (y > 0) {
    if (y % 2 == 1) ans = (ans * x) % m;
    x = ((x % m) * (x % m)) % m;
    y = y >> 1;
  }
  return ans % m;
}
set<int> st;
;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (i == 1) {
      if (x != 0) {
        cout << 1 << endl;
        return 0;
      } else
        st.insert(0);
      continue;
    }
    if ((st.size() == x and *st.rbegin() == x - 1) || st.find(x) != st.end()) {
      st.insert(x);
      continue;
    }
    cout << i << endl;
    return 0;
  }
  cout << -1 << endl;
  return 0;
}
