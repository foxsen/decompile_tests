#include <bits/stdc++.h>
using namespace std;
long long V[101][101];
int main() {
  long long a, b, c, d, T;
  cin >> T;
  long long sum = 0;
  while (T--) {
    cin >> a >> b >> c >> d;
    for (int i = a; i <= c; i++) {
      for (int j = b; j <= d; j++) {
        sum++;
      }
    }
  }
  cout << sum;
}
