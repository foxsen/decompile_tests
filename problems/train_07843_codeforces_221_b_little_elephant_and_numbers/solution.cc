#include <bits/stdc++.h>
using namespace std;
string toString(int x) {
  string s;
  while (x) {
    s.push_back(x % 10 + '0');
    x /= 10;
  }
  return s;
}
int main() {
  int n;
  cin >> n;
  vector<int> divisors;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      int div = i;
      divisors.push_back(div);
      if (div != n / div) {
        divisors.push_back(n / div);
      }
    }
  }
  string s = toString(n);
  set<char> digits;
  for (int i = 0; i < s.size(); i++) {
    digits.insert(s[i]);
  }
  int count = 0;
  for (int i = 0; i < divisors.size(); i++) {
    bool flag = false;
    string divisor = toString(divisors[i]);
    for (int i = 0; i < divisor.size(); i++) {
      if (digits.count(divisor[i])) {
        flag = true;
        break;
      }
    }
    if (flag) {
      count++;
    }
  }
  cout << count << endl;
}
