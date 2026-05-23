#include <bits/stdc++.h>
using namespace std;
int main() {
  int num;
  long long int ans = 0, tmp_ans = 2;
  cin >> num;
  for (int i = 1; i <= num; i++) {
    ans += tmp_ans;
    tmp_ans *= 2;
  }
  cout << ans;
  return 0;
}
