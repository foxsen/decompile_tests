#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i;
  cin >> n;
  string s, temp;
  cin >> s;
  int flag = 0;
  for (i = 0; i < n - 1; i++) {
    if (s[i] > s[i + 1] && flag == 0) {
      flag = 1;
      continue;
    }
    temp += s[i];
  }
  temp += s[i];
  if (temp.size() == s.size()) temp.pop_back();
  cout << temp;
}
