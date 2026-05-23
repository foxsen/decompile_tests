#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int misha1 = a - (a / 250) * c;
  int vasiya1 = b - (b / 250) * d;
  int misha2 = (3 * a) / 10;
  int vasiya2 = (3 * b) / 10;
  int misha = max(misha1, misha2);
  int vasiya = max(vasiya1, vasiya2);
  if (vasiya > misha)
    printf("Vasya\n");
  else if (vasiya < misha)
    printf("Misha\n");
  else
    printf("Tie\n");
  return 0;
}
