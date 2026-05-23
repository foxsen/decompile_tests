#include <bits/stdc++.h>
using LL = long long;
using ULL = unsigned long long;
int main() {
  using namespace std;
  ULL queries = 0;
  cin >> queries;
  for (ULL loop = 0; loop < queries; ++loop) {
    ULL rectangles = 0;
    cin >> rectangles;
    vector<ULL> sides;
    for (ULL sideLoop = 0; sideLoop < 4 * rectangles; ++sideLoop) {
      ULL side = 0;
      cin >> side;
      sides.push_back(side);
    }
    sort(sides.begin(), sides.end());
    bool successful = true;
    ULL equalArea = sides[0] * sides[sides.size() - 1];
    for (ULL index = 0; index < sides.size() / 2; ++index) {
      if (sides[index] * sides[sides.size() - index - 1] != equalArea) {
        successful = false;
        break;
      }
    }
    for (ULL index = 0; index < sides.size() - 1; index += 2) {
      if (sides[index] != sides[index + 1]) {
        successful = false;
        break;
      }
    }
    cout << (successful ? "YES" : "NO") << endl;
  }
  return 0;
}
