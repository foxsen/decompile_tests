#include <bits/stdc++.h>
using namespace std;
int n;
void EXEC() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int s = 0;
    int t;
    for (int j = 0; j < n; ++j) {
      cin >> t;
      if (t != -1) s |= t;
    }
    cout << s << ' ';
  }
  cout << endl;
}
int main() {
  EXEC();
  return 0;
}
