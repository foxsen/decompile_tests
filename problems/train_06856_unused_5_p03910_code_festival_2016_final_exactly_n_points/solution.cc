#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n;
  cin >> n;
  long long i = 1;
  while (i*(i+1)/2  < n) ++i;
  long long dif = i*(i+1)/2 - n;
  for (int j=1; j<=i; ++j) {
    if (j != dif) cout << j << endl;
  }
  return 0;
}
