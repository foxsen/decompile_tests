#include <bits/stdc++.h>
using namespace std;
const int Maxn = 2e5 + 10;
const int Inf = 2000000007;
vector<int> v(Maxn);
map<int, int> mp;
int b[Maxn];
int n, k, temp = 0, tot = 0;
int res = -Inf, root = 0, z = 0, r = 0;
bool ok = false;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'z') {
      temp++;
    }
    if (s[i] == 'n') {
      tot++;
    }
  }
  for (int i = 0; i < tot; i++) {
    cout << "1";
    cout << " ";
  }
  for (int i = 0; i < temp; i++) {
    cout << "0";
    cout << " ";
  }
  cout << "\n";
  return 0;
}
