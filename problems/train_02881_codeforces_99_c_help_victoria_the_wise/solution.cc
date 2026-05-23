#include <bits/stdc++.h>
using namespace std;
const string gr[24] = {"123456", "234156", "341256", "412356", "143265",
                       "432165", "321465", "214365", "546213", "462513",
                       "625413", "254613", "452631", "526431", "264531",
                       "645231", "351624", "516324", "163524", "635124",
                       "361542", "615342", "153642", "536142"};
string pr(const string &s, int k) {
  string ret = "123456";
  for (int i = 0; i < 6; ++i) ret[i] = s[gr[k][i] - '1'];
  return ret;
}
bool eq(const string &s1, const string &s2) {
  for (int i = 0; i < 24; ++i)
    if (s1 == pr(s2, i)) return true;
  return false;
}
vector<string> r;
string s;
bool used[6] = {0};
void check(const string &x) {
  for (int i = 0; i < r.size(); ++i)
    if (eq(x, r[i])) return;
  r.push_back(x);
}
void rec(string x) {
  if (x.length() > 6) return;
  if (x.length() == 6) {
    check(x);
    return;
  }
  for (int i = 0; i < 6; ++i)
    if (!used[i]) {
      used[i] = true;
      rec(x + s[i]);
      used[i] = false;
    }
}
int main() {
  cin >> s;
  rec("");
  cout << r.size() << endl;
  return 0;
}
