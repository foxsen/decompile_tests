#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using pcc = pair<char, char>;
using pdd = pair<double, double>;
using pci = pair<char, int>;
using si = set<int>;
using s = string;
using seti = set<int>;
using useti = unordered_set<int>;
using mseti = multiset<int>;
using umseti = unordered_multiset<int>;
using vi = vector<int>;
using vc = vector<char>;
using vs = vector<string>;
using vd = vector<double>;
using vll = vector<ll>;
using vpii = vector<pii>;
using msi = map<string, int>;
using umsi = unordered_map<string, int>;
void solve() {
  string str1 = "AEFHIKLMNTVWXYZ";
  string str2 = "BCDGJOPQRSU";
  string str;
  cin >> str;
  int cnt = 0;
  bool flag = false;
  for (int i = 0; i < str.size(); i++) {
    flag = false;
    for (int j = 0; j < str1.size(); j++) {
      if (str[i] == str1[j]) flag = true;
    }
    if (flag) cnt++;
  }
  if (cnt == str.size()) {
    cout << "YES"
         << "\n";
    return;
  }
  cnt = 0;
  for (int i = 0; i < str.size(); i++) {
    flag = false;
    for (int j = 0; j < str2.size(); j++) {
      if (str[i] == str2[j]) flag = true;
    }
    if (flag) cnt++;
  }
  if (cnt == str.size()) {
    cout << "YES"
         << "\n";
    return;
  }
  cout << "NO"
       << "\n";
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
  return 0;
}
