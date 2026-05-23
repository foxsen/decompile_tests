#include <bits/stdc++.h>
using namespace std;
stack<char> st;
string s;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> s;
  for (int i = 0; i < s.size(); ++i) {
    if (st.empty()) {
      st.push(s[i]);
    } else {
      if (st.top() == s[i])
        st.pop();
      else
        st.push(s[i]);
    }
  }
  if (st.empty())
    cout << "Yes" << '\n';
  else
    cout << "No" << '\n';
}
