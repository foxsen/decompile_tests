#include <bits/stdc++.h>
using namespace std;
long long arr[27][27] = {0};
long long counter[27][27] = {0};
string str[101];
int main() {
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> str[i];
  }
  for (int i = 0; i < 27; i++) {
    for (int j = 0; j < 27; j++) {
      for (int k = 0; k < n; k++) {
        int len = str[k].length();
        int flag = 0;
        for (int l = 0; l < len; l++) {
          if (str[k][l] == char(i + 97) || str[k][l] == char(j + 97)) {
            flag = 0;
          } else {
            flag = 1;
            break;
          }
        }
        if (flag == 0) {
          counter[i][j] += len;
        }
      }
    }
  }
  long long maxi = -1;
  for (int i = 0; i < 27; i++) {
    for (int j = 0; j < 27; j++) {
      if (counter[i][j] > maxi) maxi = counter[i][j];
    }
  }
  cout << maxi << endl;
  return 0;
}
