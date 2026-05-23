#include <bits/stdc++.h>
using namespace std;
int n;
int top;
int side[105][2];
void scan(void) {
  cin >> n;
  cin >> top;
  for (int i = 0; i < n; i++) cin >> side[i][0] >> side[i][1];
}
bool possible(void) {
  for (int i = 0; i < n; i++)
    if ((top == side[i][0]) || (7 - top == side[i][0]) || (top == side[i][1]) ||
        (7 - top == side[i][1]))
      return false;
  return true;
}
int main(void) {
  scan();
  cout << (possible() ? "YES" : "NO") << endl;
  return 0;
}
