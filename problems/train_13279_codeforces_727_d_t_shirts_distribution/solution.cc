#include <bits/stdc++.h>
using namespace std;
using fl = long double;
using ll = long long;
using pii = pair<int, int>;
const int m = 6;
const int maxn = 3e5;
int cnt[m + 1];
int u[m + 1];
int res[maxn];
int need[maxn];
int allow[m + 1];
int shift[m + 1];
int parse(string s) {
  switch (s[0]) {
    case 'S':
      return 0;
    case 'M':
      return 1;
    case 'L':
      return 2;
    case 'X':
      return s.length() + 1;
    default:
      return -1;
  }
}
void print(int t) {
  switch (t) {
    case 0:
      cout << "S";
      break;
    case 1:
      cout << "M";
      break;
    case 2:
      cout << "L";
      break;
    case 3:
      cout << "XL";
      break;
    case 4:
      cout << "XXL";
      break;
    case 5:
      cout << "XXXL";
      break;
    default:
      break;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  for (int i = 0; i < m; ++i) {
    cin >> cnt[i];
  }
  int n;
  cin >> n;
  string s;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    size_t y;
    if (string::npos == (y = s.find(','))) {
      res[i] = parse(s);
      need[i] = -1;
      --cnt[res[i]];
    } else {
      need[i] = parse(s.substr(0, y));
      ++u[need[i]];
      res[i] = -1;
    }
  }
  for (int i = 0; i < m; ++i) {
    if (cnt[i] < 0) {
      cout << "NO\n";
      return 0;
    }
  }
  for (int i = 0; i < m; ++i) {
    if (cnt[i] >= u[i]) {
      allow[i] = u[i];
    } else {
      allow[i] = cnt[i];
      if (cnt[i + 1] < u[i] - cnt[i]) {
        cout << "NO\n";
        return 0;
      }
      cnt[i + 1] -= (u[i] - cnt[i]);
    }
  }
  cout << "YES\n";
  for (int i = 0; i < n; ++i) {
    if (res[i] >= 0) {
      print(res[i]);
    } else {
      if (allow[need[i]] > 0) {
        print(need[i]);
        --allow[need[i]];
      } else {
        print(need[i] + 1);
      }
    }
    cout << '\n';
  }
  return 0;
}
