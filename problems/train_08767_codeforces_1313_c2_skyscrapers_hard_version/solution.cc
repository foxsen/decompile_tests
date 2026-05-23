#include <bits/stdc++.h>
using namespace std;
const int inf = int(1e9) + 7;
int main() {
  ios::sync_with_stdio(false);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<long long> minl(n);
  vector<long long> minr(n);
  vector<long long> dpl(n);
  vector<long long> dpr(n);
  stack<pair<long long, long long>> st;
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && st.top().first > a[i]) st.pop();
    if (st.empty()) {
      minl[i] = i;
      st.push({a[i], i});
      continue;
    }
    minl[i] = st.top().second;
    st.push({a[i], i});
  }
  for (int i = n - 1; i >= 0; --i) {
    while (!st.empty() && st.top().first > a[i]) st.pop();
    if (st.empty()) {
      minr[i] = i;
      st.push({a[i], i});
      continue;
    }
    minr[i] = st.top().second;
    st.push({a[i], i});
  }
  for (int i = 0; i < n; ++i) {
    if (i == minl[i])
      dpl[i] = a[i] * (i + 1);
    else
      dpl[i] = dpl[minl[i]] + (i - minl[i]) * a[i];
  }
  for (int i = n - 1; i >= 0; --i) {
    if (i == minr[i])
      dpr[i] = a[i] * (n - i);
    else
      dpr[i] = dpr[minr[i]] + (minr[i] - i) * a[i];
  }
  int ind = 0;
  long long maxs = 0;
  for (int i = 0; i < n; ++i) {
    if (dpl[i] + dpr[i] - a[i] > maxs) {
      maxs = dpl[i] + dpr[i] - a[i];
      ind = i;
    }
  }
  for (int i = ind - 1; i >= 0; --i) {
    a[i] = min(a[i], a[i + 1]);
  }
  for (int i = ind + 1; i < n; ++i) {
    a[i] = min(a[i], a[i - 1]);
  }
  for (int i = 0; i < n; ++i) cout << a[i] << " ";
  return 0;
}
