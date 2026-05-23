#include <bits/stdc++.h>
using namespace std;
int main() {
  long int n;
  cin >> n;
  for (long int b = 0; b < n; ++b) {
    int a[7] = {0};
    long long int k;
    cin >> k;
    int count = 0;
    for (int j = 0; j < 7; ++j) {
      cin >> a[j];
      if (a[j] == 1) count++;
    }
    if (count == 1) {
      cout << (7 * (k - 1)) + 1 << endl;
    } else {
      int rem = k % count;
      if (k % count == 0) {
        k = k - count;
        rem = count;
      }
      int min = 99999;
      for (int i = 0; i < 7; ++i) {
        int l = 0;
        int j = i + 1;
        if (j >= 7) j = j - 7;
        int count1 = 0;
        while (l < rem) {
          if (a[j] == 1) {
            l++;
          }
          count1++;
          j++;
          if (j >= 7) j = j - 7;
        }
        if (min > count1) min = count1;
      }
      cout << ((k / count) * 7) + min << endl;
    }
  }
  return 0;
}
