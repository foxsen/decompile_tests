#include <bits/stdc++.h>
using namespace std;
bool b;
long long ans, cnt, sum2;
string num_to_string(int num) {
  stringstream ss;
  ss << num;
  return ss.str();
}
void O_o() {
  ios::sync_with_stdio(0);
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
}
int main() {
  O_o();
  int n, k;
  string s;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> s;
    set<int> ss;
    b = 0;
    for (int j = 0; j < ((int)(s.size())); j++) ss.insert(s[j] - '0');
    int x = 0;
    for (auto j : ss) {
      if (j != x) b = 1;
      if (x == k) break;
      x++;
    }
    if (((int)(ss.size())) < k + 1 || x != k) b = 1;
    if (!b) cnt++;
  }
  cout << cnt << endl;
  return 0;
}
