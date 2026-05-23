#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d;
  cin >> d >> n;
  long long int ilosc = 0;
  for (int i = 0; i < n - 1; i++) {
    int p;
    cin >> p;
    ilosc += (d - p);
  }
  cin >> d;
  cout << ilosc << "\n";
  return 0;
}
