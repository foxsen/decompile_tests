#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 10;
long long N, arr[maxn];
signed main() {
  ios::sync_with_stdio(false);
  cin >> N;
  set<long long> st, today;
  vector<long long> v;
  long long h = 1;
  for (register long long i = 1; i <= N; ++i) {
    cin >> arr[i];
    if (arr[i] < 0) {
      if (st.count(-arr[i])) {
        st.erase(-arr[i]);
      } else {
        cout << "-1" << endl;
        return 0;
      }
      if (st.size() == 0) {
        v.push_back(i - h + 1);
        today.clear();
        h = i + 1;
      }
    } else {
      if (today.count(arr[i])) {
        cout << "-1" << endl;
        return 0;
      }
      st.insert(arr[i]);
      today.insert(arr[i]);
    }
  }
  if (st.size() != 0) {
    cout << -1 << endl;
    return 0;
  }
  cout << v.size() << endl;
  for (auto i : v) {
    cout << i << " ";
  }
  return 0;
}
