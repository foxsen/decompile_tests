#include <bits/stdc++.h>
using namespace std;
int n, ans;
int prefSuf[1000010][2];
string s;
void getPS(int k, char cl, char op) {
  stack<char> st;
  bool ok = 1;
  for (int i = 1; i <= n; ++i) {
    if (!ok) {
      prefSuf[i + k * (n - 2 * i + 1)][k] = -1e9;
      continue;
    }
    if (st.empty()) {
      if (s[i] == cl) {
        ok = 0;
        prefSuf[i + k * (n - 2 * i + 1)][k] = -1e9;
        continue;
      } else {
        st.push(s[i]);
      }
    } else {
      if (st.top() == op and s[i] == cl) {
        st.pop();
      } else {
        st.push(s[i]);
      }
    }
    prefSuf[i + k * (n - 2 * i + 1)][k] = st.size();
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> s;
  s = " " + s + " ";
  getPS(0, ')', '(');
  reverse(s.begin(), s.end());
  getPS(1, '(', ')');
  reverse(s.begin(), s.end());
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '(') {
      ans += (prefSuf[i - 1][0] == (prefSuf[i + 1][1] + 1));
    } else {
      ans += (prefSuf[i + 1][1] == (prefSuf[i - 1][0] + 1));
    }
  }
  cout << ans;
}
