#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int d = 0;
  while (n--) {
    char e;
    cin >> e;
    if (e == '(') {
      cout << d % 2;
      d++;
    } else {
      d--;
      cout << d % 2;
    }
  }
  cout << endl;
}
