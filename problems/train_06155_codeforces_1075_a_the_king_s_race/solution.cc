#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long n, x, y;
  cin >> n >> x >> y;
  long long white = x + y - 2;
  long long black = 2 * n - x - y;
  if (white <= black)
    cout << "White";
  else
    cout << "Black";
  return 0;
}
