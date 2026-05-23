#include <bits/stdc++.h>
using namespace std;
string find(int j) {
  string s = "";
  while (j > 0) {
    char ch = j % 10 + '0';
    s += ch;
    j = j / 10;
  }
  reverse(s.begin(), s.end());
  return s;
}
int main() {
  string s;
  cin >> s;
  int n = s.size();
  string t = "";
  for (int i = 0; i < n - 1; i++) t += s[i];
  s.append(t);
  int arr[26][n][26];
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < 26; k++) {
        arr[i][j][k] = 0;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < n; j++) {
      int c1 = s[i] - 'a';
      int c2 = s[i + j] - 'a';
      arr[c1][j][c2]++;
    }
  }
  int ans = 0;
  for (int i = 0; i < 26; i++) {
    int max = 0;
    for (int j = 1; j < n; j++) {
      int x = 0;
      for (int k = 0; k < 26; k++) {
        if (arr[i][j][k] == 1) x++;
      }
      if (x > max) max = x;
    }
    ans += max;
  }
  double d = (double)ans / (double)n;
  std::cout << std::fixed;
  std::cout << std::setprecision(6);
  std::cout << d << endl;
}
