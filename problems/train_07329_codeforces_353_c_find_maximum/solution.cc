#include <bits/stdc++.h>
using namespace std;
int cursum[100003];
int allsum[100003];
string str;
int val;
int main(void) {
  int n;
  cin >> n;
  cin >> val;
  allsum[0] = val;
  for (int i = 1; i < n; i++) {
    cin >> val;
    allsum[i] = allsum[i - 1] + val;
  }
  cin >> str;
  if (str[0] == '1') cursum[0] = allsum[0];
  for (int i = 1; i < n; i++) {
    if (str[i] == '1')
      cursum[i] = cursum[i - 1] + (allsum[i] - allsum[i - 1]);
    else
      cursum[i] = cursum[i - 1];
  }
  int maxim = -1;
  if (str[0] == '1') maxim = cursum[0];
  for (int i = 1; i < n; i++) {
    if (str[i] == '1')
      maxim = max(maxim, allsum[i - 1] + cursum[n - 1] - cursum[i]);
  }
  maxim = max(maxim, cursum[n - 1]);
  if (maxim < 0) maxim = 0;
  cout << maxim << endl;
  return 0;
}
