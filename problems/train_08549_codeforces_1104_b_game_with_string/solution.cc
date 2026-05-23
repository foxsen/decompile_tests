#include <bits/stdc++.h>
using namespace std;
const long long N = 1e7 + 5, MOD = 1e9 + 7;
string s;
long long cnt;
stack<char> st;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> s;
  long long n = s.size();
  for (long long i = 0; i < n; i++) {
    if (st.empty())
      st.push(s[i]);
    else if (st.top() == s[i]) {
      st.pop();
      cnt++;
    } else
      st.push(s[i]);
  }
  if (cnt & 1)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
