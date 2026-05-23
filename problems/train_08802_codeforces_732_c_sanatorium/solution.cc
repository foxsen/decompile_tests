#include <bits/stdc++.h>
using namespace std;
const int N = 100500;
int sum;
int ii;
bool cmp(long long a, long long b) { return a > b; }
int main() {
  int k, r;
  int i, j;
  int n;
  long long an[3];
  long long aa, bb, cc;
  long long sum;
  while (cin >> aa >> bb >> cc) {
    sum = 0;
    an[0] = aa;
    an[1] = bb;
    an[2] = cc;
    sort(an, an + 3, cmp);
    if (aa == an[0]) {
      if (bb == an[1]) {
        if (aa - bb - 1 > 0) sum += aa - bb - 1;
        if (aa - cc - 1 > 0) sum += aa - cc - 1;
      } else {
        if (aa - bb - 1 > 0) sum += aa - bb - 1;
        if (aa - cc - 1 > 0) sum += aa - cc - 1;
      }
    } else {
      if (bb == an[0]) {
        if (aa == an[1]) {
          if (bb - aa - 1 > 0) sum += bb - aa - 1;
          if (bb - cc - 1 > 0) sum += bb - cc - 1;
        } else {
          if (bb - aa - 1 > 0) sum += bb - aa - 1;
          if (bb - cc - 1 > 0) sum += bb - cc - 1;
        }
      } else {
        if (cc == an[0])
          if (aa == an[1]) {
            if (cc - aa - 1 > 0) sum += cc - aa - 1;
            if (cc - bb - 1 > 0) sum += cc - bb - 1;
          } else {
            if (cc - aa - 1 > 0) sum += cc - aa - 1;
            if (cc - bb - 1 > 0) sum += cc - bb - 1;
          }
      }
    }
    cout << sum << endl;
  }
  return 0;
}
