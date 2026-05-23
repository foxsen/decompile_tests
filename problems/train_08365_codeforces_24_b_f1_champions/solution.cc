#include <bits/stdc++.h>
using namespace std;
template <class a, class b>
ostream &operator<<(ostream &tout, const pair<a, b> &c) {
  return (tout << '(' << c.first << ',' << c.second << ')');
}
template <class t>
ostream &operator<<(ostream &tout, const vector<t> &s) {
  tout << '[';
  for (int i = 0; i < s.size(); i++)
    if (i + 1 == s.size())
      tout << s[i];
    else
      tout << s[i] << ',';
  tout << ']';
  return (tout);
}
const int num[10] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
map<string, int> score;
map<string, map<int, int> > pl;
vector<int> f(map<int, int> s) {
  vector<int> ans;
  for (map<int, int>::iterator i = s.begin(); i != s.end(); i++)
    ans.push_back(i->second);
  return (ans);
}
bool df2(string a, string b) {
  if (pl[a][0] != pl[b][0]) return (pl[a][0] > pl[b][0]);
  if (score[a] != score[b]) return (score[a] > score[b]);
  for (int i = 0; i < 50; i++)
    if (pl[a][i] != pl[b][i]) return (pl[a][i] > pl[b][i]);
  return (a < b);
}
bool df1(string a, string b) {
  if (score[a] != score[b]) return (score[a] > score[b]);
  return (df2(a, b));
}
int main() {
  int t;
  cin >> t;
  vector<string> all;
  for (int i = 1; i <= t; i++) {
    int n;
    cin >> n;
    for (int j = 0; j < n; j++) {
      string x;
      cin >> x;
      if (j < 10) score[x] += num[j];
      pl[x][j]++;
      all.push_back(x);
    }
  }
  sort(all.begin(), all.end());
  all.resize(unique(all.begin(), all.end()) - all.begin());
  cout << *min_element(all.begin(), all.end(), df1) << endl;
  cout << *min_element(all.begin(), all.end(), df2) << endl;
}
