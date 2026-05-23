#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s, s1;
  cin >> s;
  long long l = s.size(), p = 0, cnt = 0, c = 0, d = 0;
  vector<string> v;
  for (long long i = 0; i < l; i++) {
    if (s[i] == '@') d = 1;
    if (s[i] != '@')
      cnt += 1;
    else if (s[i] == '@' && !c && !cnt)
      p = 1;
    else if (s[i] == '@' && !c && cnt)
      c = 1, cnt = 0;
    else if (s[i] == '@' && c && cnt < 2)
      p = 1;
    else if (s[i] == '@' && c && cnt >= 2)
      cnt = 0;
    if (s[l - 1] == '@') p = 1;
  }
  if (p || !d)
    cout << "No solution";
  else {
    for (long long i = 0; i < l; i++) {
      if (s[i] != '@')
        s1.push_back(s[i]);
      else {
        s1.push_back(s[i]);
        s1.push_back(s[i + 1]);
        v.push_back(s1);
        s1 = "";
        i += 1;
      }
    }
    long long len = v.size();
    for (long long i = 0; i < len - 1; i++) cout << v[i] << ",";
    cout << v[len - 1] << s1;
  }
}
