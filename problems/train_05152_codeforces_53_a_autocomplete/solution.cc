#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const long long INF = 1000 * 1000 * 1000 + 7;
const long long LINF = INF * (long long)INF;
const int MAX = 100 + 47;
string A[MAX];
string t;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> t >> n;
  for (int i = (0); i < (n); i++) cin >> A[i];
  string mn = "";
  for (int i = (0); i < (n); i++) {
    if (A[i].substr(0, (int)t.size()) == t) {
      mn = A[i];
      break;
    }
  }
  if (mn == "") {
    cout << t << endl;
    return 0;
  }
  for (int i = (0); i < (n); i++) {
    if (A[i].substr(0, (int)t.size()) == t) {
      mn = min(A[i], mn);
    }
  }
  cout << mn << endl;
}
