#include <bits/stdc++.h>
using namespace std;
void fun(string s) {
  long long int number = 0;
  string s1;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] >= 'A' and s[i] <= 'Z') {
      s1 += s[i];
    } else {
      number = number * 10 + (s[i] - 48);
    }
  }
  int len = s1.size();
  int cnt = len - 1;
  long long int b = 0;
  for (int i = 0; i < len; i++) {
    b = b + ((s1[i] - 64) * (ceil(pow(26, cnt))));
    cnt--;
  }
  printf("R%lldC%lld\n", number, b);
}
void fun1(string s) {
  long long int row = 0, col = 0;
  int pos = -1;
  int len = s.size();
  for (int i = 1; i < len; i++) {
    if (s[i] == 'C') {
      pos = i;
      break;
    } else {
      row = row * 10 + (s[i] - 48);
    }
  }
  for (int i = pos + 1; i < len; i++) {
    col = col * 10 + (s[i] - 48);
  }
  long long int n = col;
  string s1;
  while (n > 0) {
    int a = (n - 1) % 26;
    s1 += (a + 65);
    n = (n - 1) / 26;
  }
  for (int i = s1.size() - 1; i >= 0; i--) {
    cout << s1[i];
  }
  cout << row << endl;
}
int main() {
  int test;
  cin >> test;
  for (int t = 1; t <= test; t++) {
    string s;
    cin >> s;
    int pos = -1, pos2;
    int len = s.size();
    for (int i = 0; i < len; i++) {
      if (s[i] >= 48 and s[i] <= 57) {
        pos2 = i;
        break;
      }
    }
    for (int i = pos2; i < len; i++) {
      if (s[i] >= 'A' and s[i] <= 'Z') {
        pos = i;
        break;
      }
    }
    if (pos == -1) {
      fun(s);
    } else {
      fun1(s);
    }
  }
  return 0;
}
