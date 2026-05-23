#include <bits/stdc++.h>
using namespace std;
long long int MOD = (1e9) + 7;
inline void fastIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}
int main() {
  fastIO();
  int n, k, ans = 0;
  cin >> n >> k;
  map<pair<string, string>, int> has;
  vector<string> fin(n);
  vector<string> input(n);
  for (int i = 0; i < n; i++) {
    cin >> input[i];
  }
  for (int i = 0; i < k; i++) {
    string a, b;
    cin >> a >> b;
    has[make_pair(a, b)] = 1;
    has[make_pair(b, a)] = 1;
  }
  for (int i = 0; i <= pow(2, n); i++) {
    bool valid = true;
    int cnt = 0;
    vector<string> temp;
    for (int j = 0; j < n; j++) {
      if ((i & (1 << j)) != 0) {
        cnt++;
        temp.push_back(input[j]);
        for (int k = 0; k < n; k++) {
          if ((i & (1 << k)) != 0) {
            if (has[make_pair(input[k], input[j])]) {
              valid = false;
            }
          }
        }
      }
    }
    if (valid && cnt > ans) {
      for (int k = 0; k < temp.size(); k++) {
        fin[k] = temp[k];
      }
      ans = cnt;
    }
  }
  cout << ans << endl;
  sort(fin.begin(), fin.end());
  for (int i = 0; i < fin.size(); i++) {
    if (fin[i] != "") {
      cout << fin[i] << endl;
    }
  }
}
