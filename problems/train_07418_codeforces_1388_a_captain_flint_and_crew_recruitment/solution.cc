#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n <= 30)
      cout << "NO" << endl;
    else {
      cout << "YES" << endl;
      long long temp = n - 30;
      if (temp == 6)
        cout << 6 << " " << 10 << " " << 15 << " " << 5 << endl;
      else if (temp == 14)
        cout << 6 << " " << 10 << " " << 15 << " " << 13 << endl;
      else if (temp == 10)
        cout << 6 << " " << 14 << " " << 15 << " " << 5 << endl;
      else
        cout << 6 << " " << 10 << " " << 14 << " " << temp << endl;
    }
  }
  return 0;
}
