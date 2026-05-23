#include <bits/stdc++.h>
using namespace std;
struct Query {
  string s, t, p;
};
bool is_subsequence(const string& s, const string& t) {
  auto size = t.size();
  size_t i = 0;
  for (const auto& c : s) {
    while (i < size and t[i] != c) ++i;
    if (i == size) return false;
    ++i;
  }
  return true;
}
vector<string> solve(const vector<Query>& qs) {
  vector<string> ans;
  for (const auto& q : qs) {
    string a{"YES"};
    if (q.t.size() < q.s.size() or not is_subsequence(q.s, q.t)) {
      a = "NO";
    } else {
      map<char, int> hsp, ht;
      for (const auto& c : q.s) ++hsp[c];
      for (const auto& c : q.p) ++hsp[c];
      for (const auto& c : q.t) ++ht[c];
      for (const auto& c : q.t) {
        if (hsp.find(c) == hsp.end() or ht[c] > hsp[c]) {
          a = "NO";
          break;
        }
      }
    }
    ans.push_back(a);
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  int q;
  cin >> q;
  vector<Query> qs(q);
  for (int i = 0; i < q; ++i) cin >> qs[i].s >> qs[i].t >> qs[i].p;
  auto ans = solve(qs);
  for (const auto& x : ans) cout << x << '\n';
  return 0;
}
