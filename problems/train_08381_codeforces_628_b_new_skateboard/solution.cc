#include <bits/stdc++.h>
using namespace std;
long long cnt = 0;
string str = "";
int change(string a) {
  stringstream ss;
  int number;
  ss << a;
  ss >> number;
  ss.clear();
  return number;
}
void dp(long long i) {
  string temp;
  temp = str[i];
  if (change(temp) % 4 == 0) cnt++;
  if (i > 0) {
    temp = "";
    temp = str[i] + temp;
    temp = str[i - 1] + temp;
    if (change(temp) % 4 == 0) {
      for (int j = i; j > 0; j--) cnt++;
    }
  }
}
int main() {
  cin >> str;
  for (long long i = 0; i < str.size(); i++) {
    dp(i);
  }
  cout << cnt;
}
