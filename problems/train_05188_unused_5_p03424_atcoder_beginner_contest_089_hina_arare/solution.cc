#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<char> s(n);
  string ans = "Three";
  for (auto& e: s) {
    cin >> e;
    if (e == 'Y') ans = "Four";
  }
  cout << ans << endl;
}