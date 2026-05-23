#include <bits/stdc++.h>
using namespace std;
void printAll(int n, ...) {
  if (1) {
    va_list ap;
    va_start(ap, n);
    for (int i = 1; i <= n; i++) cout << va_arg(ap, long long int) << " ";
    cout << endl;
    va_end(ap);
  }
}
template <typename T>
string toString(T n) {
  stringstream ss;
  ss << n;
  string s;
  ss >> s;
  return s;
}
void init() {
  cout << fixed << setprecision(0);
  ios_base::sync_with_stdio(false);
  cin.tie(0);
}
bool isInteger(double n) {
  if (n - (long long int)n == 0)
    return true;
  else
    return false;
}
int main() {
  init();
  long long int i, j, k;
  long long int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> ara(n);
    for (int i = 0; i < n; i++) cin >> ara[i];
    bool inc = (ara[1] - ara[0] > 0 ? true : false);
    vector<int> ans;
    ans.push_back(ara[0]);
    for (i = 2; i < n; i++) {
      if ((inc && ara[i] - ara[i - 1] < 0) ||
          (!inc && ara[i] - ara[i - 1] > 0)) {
        inc = !inc;
        ans.push_back(ara[i - 1]);
      }
    }
    ans.push_back(ara[n - 1]);
    cout << ans.size() << endl;
    {
      if (1) {
        for (auto a : ans) cout << a << " ";
        cout << endl;
      }
    };
  }
  return 0;
}
