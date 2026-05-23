#include <bits/stdc++.h>
using namespace std;
int main() {
  string str, arr;
  cin >> str;
  int len = str.length();
  arr.push_back('/');
  for (int i = 1; i < len; i++) {
    if (str[i - 1] == str[i] && str[i] == '/') {
    } else {
      arr.push_back(str[i]);
    }
  }
  len = arr.length();
  if (arr.compare("/") == 0)
    cout << arr << endl;
  else {
    if (arr[len - 1] == '/') {
      arr.erase(len - 1, len);
      cout << arr << endl;
    } else
      cout << arr << endl;
  }
  return 0;
}
