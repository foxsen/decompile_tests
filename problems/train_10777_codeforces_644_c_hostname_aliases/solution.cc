#include <bits/stdc++.h>
using namespace std;
int dr[] = {1, 0, -1, 0, -1, -1, 1, 1};
int dc[] = {0, -1, 0, 1, -1, 1, -1, 1};
const int MAX = 1e6 + 7;
const int MOD = 1e9 + 7;
pair<string, string> http[MAX];
map<string, int> mp;
map<vector<string>, vector<string> > ans;
bool comp(pair<string, string> a, pair<string, string> b) {
  if (a.first != b.first) return a.first < b.first;
  return a.second < b.second;
}
int main() {
  int n, m = 0, i = 0;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    if (mp[s]) continue;
    int last_sl = s.substr(7, s.length()).find_first_of('/') + 7;
    if (last_sl == 6)
      http[i] = pair<string, string>(s, "");
    else {
      http[i] = pair<string, string>(s.substr(0, last_sl),
                                     s.substr(last_sl, s.length()));
    }
    i++;
    mp[s]++;
    m++;
  }
  sort(http, http + m, comp);
  string temp = http[0].first;
  vector<string> q;
  http[m] = pair<string, string>("fuck", "you");
  for (long long i = 0; i < m + 1; ++i) {
    if (temp == http[i].first) {
      q.push_back(http[i].second);
    } else {
      ans[q].push_back(temp);
      temp = http[i].first;
      q.clear();
      q.push_back(http[i].second);
    }
  }
  int x = 0;
  for (map<vector<string>, vector<string> >::iterator it = ans.begin();
       it != ans.end(); it++)
    if ((long long)it->second.size() > 1) x++;
  cout << x << "\n";
  for (map<vector<string>, vector<string> >::iterator it = ans.begin();
       it != ans.end(); it++) {
    if ((long long)it->second.size() <= 1) continue;
    for (long long i = 0; i < (long long)it->second.size(); ++i)
      cout << it->second[i] << " ";
    cout << "\n";
  }
}
