#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int a, x, y, z;
  cin >> a;
  if (a % 2 == 0) {
    cout << a / 2 << endl;
    for (long long int i = 0; i < a / 2; i++) cout << "2 ";
  } else {
    cout << (a - 3) / 2 + 1 << endl;
    for (long long int i = 0; i < (a - 3) / 2; i++) cout << "2 ";
    cout << 3;
  }
}
