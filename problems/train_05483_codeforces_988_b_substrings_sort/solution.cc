#include <bits/stdc++.h>
using namespace std;
bool is_substring(string s1, string s2) {
  for (int i = 0; i <= (s1.size() - s2.size()); i++) {
    if (s1.substr(i, s2.size()) == s2) return true;
  }
  return false;
}
void solution() {
  long long int n;
  string s;
  cin >> n;
  vector<pair<int, string> > mpp;
  for (int i = 0; i < n; i++) {
    cin >> s;
    mpp.push_back(make_pair(s.size(), s));
  }
  sort((mpp).begin(), (mpp).end());
  for (int j = 0; j < mpp.size() - 1; j++) {
    if (is_substring(mpp[j + 1].second, mpp[j].second) == false) {
      cout << "NO";
      return;
    }
  }
  cout << "YES\n";
  for (int i = 0; i < mpp.size(); i++) {
    cout << mpp[i].second << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long int t;
  t = 1;
  while (t--) {
    solution();
    cout << "\n";
  }
}
