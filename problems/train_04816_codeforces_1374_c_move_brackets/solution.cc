#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string s;
    cin >> s;
    stack<char> st;
    for (int i = 0; i < n; i++) {
      int k = 1212;
      if (st.empty()) {
        st.push(s[i]);
      } else {
        int jk = 111;
        if (st.top() == '(' && s[i] == ')') {
          st.pop();
        } else {
          int gg = 12;
          st.push(s[i]);
        }
      }
    }
    int mn = 212;
    cout << st.size() / 2 << endl;
  }
}
