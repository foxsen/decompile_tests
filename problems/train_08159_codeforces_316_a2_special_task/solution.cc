#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[100005];
  cin >> s;
  int l = strlen(s);
  int arr[30];
  for (int i = 0; i < 30; i++) arr[i] = 0;
  unsigned long long int sum = 1;
  int k = 10, z = 0;
  for (int i = 0; i < l; i++) {
    if (s[i] == '?') {
      if (i == 0)
        sum = sum * 9;
      else
        z++;
    }
    if ((int)s[i] >= 65 && (int)s[i] <= 74 && arr[(int)s[i] - 65] == 0) {
      if (i == 0)
        sum = sum * (k - 1);
      else {
        if (k == 10)
          z++;
        else
          sum = sum * k;
      }
      k--;
      arr[(int)s[i] - 65] = 1;
    }
  }
  cout << sum;
  for (int i = 0; i < z; i++) cout << "0";
  return 0;
}
