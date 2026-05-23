#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long f, suma, l = sqrt(n);
  suma = 4 * l;
  f = n - l * l;
  suma += (f / l) * 2;
  f -= (f / l) * l;
  if (f > 0) {
    suma += 2;
  }
  cout << suma;
  return 0;
}
