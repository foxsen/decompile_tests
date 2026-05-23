#include <bits/stdc++.h>
using namespace std;
int main() {
  int ml, mr, hl, hr;
  cin >> ml >> mr >> hl >> hr;
  int ok = 0;
  if (hr + 1 >= ml && hr <= 2 * (ml + 1)) ok = 1;
  if (hl + 1 >= mr && hl <= 2 * (mr + 1)) ok = 1;
  printf(ok ? "YES\n" : "NO\n");
  return 0;
}
