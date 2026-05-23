#include <bits/stdc++.h>
using namespace std;
void Solve() {
  string str;
  cin >> str;
  int len = str.length();
  str = " " + str;
  vector<int> cnt;
  cnt.push_back(0);
  int count = 0;
  for (int i = 1; i <= len; i++) {
    if (str[i] == '0') {
      if (count > 0) {
        cnt.push_back(count);
        count = 0;
      }
      continue;
    }
    if (str[i] == '1') {
      count++;
    }
  }
  cnt.push_back(count);
  sort(cnt.begin() + 1, cnt.end());
  bool isFir = true;
  int Fir = 0, Sec = 0;
  for (int i = cnt.size() - 1; i >= 1; i--) {
    if (isFir)
      Fir += cnt[i];
    else
      Sec += cnt[i];
    isFir = !isFir;
  }
  cout << Fir << endl;
};
int main() {
  int num = 1;
  cin >> num;
  for (int i = 1; i <= num; i++) {
    Solve();
  }
  return 0;
}
