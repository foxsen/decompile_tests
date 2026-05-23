#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, p;
  cin >> n >> k >> p;
  while (p--) {
    long long x;
    cin >> x;
    if (k == 0) {
      cout << '.';
      continue;
    } else {
      if (n % 2) {
        if (x == n)
          cout << 'X';
        else {
          long long num_even = min(k - 1, (n - 1) / 2);
          long long num_odd = (k - 1) - num_even;
          if (x % 2 == 0) {
            long long dist = (n - 1 - x) / 2;
            if (dist + 1 <= num_even) {
              cout << 'X';
            } else {
              cout << '.';
            }
          } else {
            long long dist = (n - 2 - x) / 2;
            if (dist + 1 <= num_odd) {
              cout << 'X';
            } else {
              cout << '.';
            }
          }
        }
      } else {
        long long num_even = min(k, (n) / 2);
        long long num_odd = (k)-num_even;
        if (x % 2 == 0) {
          long long dist = (n - x) / 2;
          if (dist + 1 <= num_even) {
            cout << 'X';
          } else {
            cout << '.';
          }
        } else {
          long long dist = (n - 1 - x) / 2;
          if (dist + 1 <= num_odd) {
            cout << 'X';
          } else {
            cout << '.';
          }
        }
      }
    }
  }
  return 0;
}
