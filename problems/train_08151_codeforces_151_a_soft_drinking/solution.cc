#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  cout << ((((k * l / nl) < (c * d) ? (k * l / nl) : (c * d))) < (p / np)
               ? (((k * l / nl) < (c * d) ? (k * l / nl) : (c * d)))
               : (p / np)) /
              n;
}
