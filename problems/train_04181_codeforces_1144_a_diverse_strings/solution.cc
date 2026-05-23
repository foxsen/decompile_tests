#include <bits/stdc++.h>
using namespace std;
priority_queue<long long int, vector<long long int>, greater<int> > q;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    for (int i = 0; i < s.length() - 1; i++) {
      if (!(s[i] + 1 == s[i + 1])) {
        cout << "No\n";
        goto l;
      }
    }
    cout << "Yes\n";
  l:;
  }
}
