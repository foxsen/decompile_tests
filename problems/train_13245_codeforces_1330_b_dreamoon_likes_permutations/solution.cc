#include <bits/stdc++.h>
using namespace std;
int main() {
  unordered_set<int> st;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) {
      cin >> x;
    }
    st.clear();
    int max_a = 0;
    unordered_set<int> idx1;
    for (int i = 0; i < n; i++) {
      max_a = max(max_a, a[i]);
      if (st.find(a[i]) != st.end()) {
        break;
      }
      st.insert(a[i]);
      if (i + 1 == max_a && i + 1 < n) {
        idx1.insert(i + 1);
      }
    }
    reverse(a.begin(), a.end());
    st.clear();
    max_a = 0;
    unordered_set<int> idx2;
    for (int i = 0; i < n; i++) {
      max_a = max(max_a, a[i]);
      if (st.find(a[i]) != st.end()) {
        break;
      }
      st.insert(a[i]);
      if (i + 1 == max_a && i + 1 < n) {
        if (idx1.find(n - (i + 1)) != idx1.end()) idx2.insert(n - (i + 1));
      }
    }
    cout << idx2.size() << endl;
    for (int i : idx2) {
      cout << i << " " << n - i << endl;
    }
  }
  return 0;
}
