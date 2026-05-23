#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  void solve(int num, std::istream& in, std::ostream& out) {
    int n, m;
    in >> n >> m;
    vector<long long> pr(n), arr(n);
    map<int, long long> cnt;
    map<int, vector<long long>> ptpr;
    long long S = 0;
    for (int i = 0; i < n; i++) {
      in >> arr[i] >> pr[i];
      cnt[arr[i]]++;
      ptpr[arr[i]].push_back(pr[i]);
      S += pr[i];
    }
    for (auto& p : ptpr) sort(p.second.begin(), p.second.end());
    bool isOk = true;
    for (auto p : cnt) {
      if (p.first == 1) continue;
      if (p.second >= cnt[1]) {
        isOk = false;
        break;
      }
    }
    if (isOk) {
      out << 0;
      return;
    }
    for (int c = cnt[1] + 1; c <= n; c++) {
      long long loc = 0;
      long long count = cnt[1];
      vector<long long> all;
      for (int i = 2; i <= m; i++) {
        int sz = ptpr[i].size();
        auto& v = ptpr[i];
        for (int j = 0; j < sz; j++) {
          if (sz - j >= c) {
            loc += v[j];
            count++;
          } else
            all.push_back(v[j]);
        }
      }
      if (count > c) continue;
      sort(all.begin(), all.end());
      for (auto x : all) {
        if (count >= c) break;
        count++;
        loc += x;
      }
      S = min(S, loc);
    }
    out << S << endl;
  }
};
void solve(std::istream& in, std::ostream& out) {
  out << std::setprecision(12);
  Solution solution;
  solution.solve(0, in, out);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  istream& in = cin;
  ostream& out = cout;
  solve(in, out);
  return 0;
}
