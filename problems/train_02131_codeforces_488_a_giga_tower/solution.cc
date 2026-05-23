#include <bits/stdc++.h>
using namespace std;
bool lucky(int i) {
  string val = to_string(i);
  for (char i : val) {
    if (i == '8') return true;
  }
  return false;
}
int main() {
  long long n;
  cin >> n;
  int cnt = 1;
  for (int i = n + 1;; i++) {
    if (lucky(i)) {
      break;
    }
    cnt++;
  }
  cout << cnt << "\n";
}
