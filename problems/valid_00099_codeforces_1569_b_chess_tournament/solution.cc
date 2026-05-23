#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * power(a * a % md, b / 2, md) % md
                      : power(a * a % md, b / 2, md) % md));
}
const int xn = 1e2 + 10;
const int xm = -20 + 10;
const int sq = 320;
const long long INF = 9e17 + 10;
const int mod = 998244353;
const int base = 257;
const int OO = (int)1e6;
const int maxim = 1e9;
const double EPS = (1e-10);
char arr[51][51];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    memset(arr, 'X', sizeof(arr));
    for (int i = 0; i < (int)(n); ++i) {
      if (s[i] == '1') {
        for (int j = 0; j < (int)(n); ++j) {
          if (i != j) {
            arr[i][j] = '=';
            arr[j][i] = '=';
          }
        }
      } else {
        bool flag = true;
        for (int j = 0; j < (int)(n); ++j) {
          if (i == j) {
            continue;
          } else if (s[j] == '2' && arr[i][j] == 'X' && flag) {
            arr[i][j] = '+';
            arr[j][i] = '-';
            flag = false;
          } else if (arr[i][j] == 'X' && s[j] == '2') {
            arr[i][j] = '-';
            arr[j][i] = '+';
          }
        }
      }
    }
    bool pos = true;
    for (int i = 0; i < (int)(n); ++i) {
      int w = 0, l = 0;
      for (int j = 0; j < (int)(n); ++j) {
        if (arr[i][j] == '+') {
          w++;
        } else if (arr[i][j] == '-') {
          l++;
        }
      }
      if (s[i] == '1') {
        if (l > 0) {
          cout << "NO" << '\n';
          pos = false;
        }
      } else {
        if (w == 0) {
          cout << "NO" << '\n';
          pos = false;
        }
      }
    }
    if (pos) {
      cout << "YES" << '\n';
      for (int i = 0; i < (int)(n); ++i) {
        for (int j = 0; j < (int)(n); ++j) {
          cout << arr[i][j];
        }
        cout << '\n';
      }
    }
  }
  return 0;
}
