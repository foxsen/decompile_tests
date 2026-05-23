#include <bits/stdc++.h>
using namespace std;
string s;
int cnt[26];
stack<char> st;
int main() {
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    cnt[s[i] - 'a']++;
  }
  int index = 0;
  for (int i = 0; i < s.length(); i++) {
    cnt[s[i] - 'a']--;
    while (index < 26 && cnt[index] == 0) {
      index++;
    }
    if (index < s[i] - 'a')
      st.push(s[i]);
    else {
      while (!st.empty()) {
        if (st.top() > s[i]) break;
        cout << st.top();
        st.pop();
      }
      cout << s[i];
      while (!st.empty()) {
        if (st.top() > 'a' + index) break;
        cout << st.top();
        st.pop();
      }
    }
  }
  while (!st.empty()) {
    cout << st.top();
    st.pop();
  }
  cout << endl;
  return 0;
}
