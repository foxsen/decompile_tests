#include <bits/stdc++.h>
using namespace std;
bool op[3][100002];
int t;
bool check(int c) {
  if (!op[1][c] && (!op[2][c] || !op[2][c - 1] || !op[2][c + 1])) {
    return false;
  } else if (!op[2][c] && (!op[1][c] || !op[1][c - 1] || !op[1][c + 1])) {
    return false;
  }
  return true;
}
int main() {
  memset(op, true, sizeof(op));
  int n, q, r, c;
  cin >> n >> q;
  for (int i = 0; i < q; i++) {
    cin >> r >> c;
    bool n1 = check(c);
    bool n2 = check(c - 1);
    bool n3 = check(c + 1);
    op[r][c] = (op[r][c] ? false : true);
    t += int((n1 ? 1 : 0) - (check(c) ? 1 : 0));
    t += int((n2 ? 1 : 0) - (check(c - 1) ? 1 : 0));
    t += int((n3 ? 1 : 0) - (check(c + 1) ? 1 : 0));
    cout << (t == 0 ? "Yes" : "No") << endl;
  }
  return 0;
}
