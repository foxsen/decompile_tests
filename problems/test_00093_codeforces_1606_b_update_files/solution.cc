#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  for (int w = 0; w < t; w++) {
    long long N, K;
    cin >> N >> K;
    N--;
    long long q = 1;
    long long res = 0;
    for (int i = 0; true; i++) {
      if (N <= 0) {
        cout << res << endl;
        break;
      }
      if (q <= K) {
        N -= q;
        q = q * 2;
        res++;
      } else {
        if (N % K == 0) {
          cout << res + N / K << endl;
          break;
        } else {
          cout << res + N / K + 1 << endl;
          break;
        }
      }
    }
  }
}
