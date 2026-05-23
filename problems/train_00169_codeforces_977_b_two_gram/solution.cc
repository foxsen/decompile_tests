#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int MAX = 200001;
int An[MAX];
int book[MAX];
int main() {
  string str;
  char a = 'a', b = 'b';
  int n;
  cin >> n >> str;
  int sum = 0;
  int mmax = 0;
  for (int i = 0; i < n - 1; i++) {
    sum = 0;
    for (int j = 0; j < n - 1; j++) {
      if (str[i] == str[j] && str[i + 1] == str[j + 1]) sum++;
    }
    if (sum > mmax) {
      mmax = sum;
      a = str[i];
      b = str[i + 1];
    }
  }
  cout << a << b << endl;
  return 0;
}
