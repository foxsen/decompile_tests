#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string str;
  cin >> str;
  vector<char> v;
  int i = 0, j = 1;
  while (i < n && j < n) {
    if (str[i] != str[j]) {
      if (i > j)
        v.push_back(str[j]), v.push_back(str[i]);
      else
        v.push_back(str[i]), v.push_back(str[j]);
      i = j + 1, j += 2;
    } else
      j += 1;
  }
  cout << n - v.size() << endl;
  for (long long i = 0; i < v.size(); i++) cout << v[i];
  return 0;
}
