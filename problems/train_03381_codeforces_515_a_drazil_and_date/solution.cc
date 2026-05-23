#include <bits/stdc++.h>
using namespace std;
bool compare(pair<long long int, long long int> p,
             pair<long long int, long long int> q) {
  return p.second < q.second;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ;
  long long int a;
  cin >> a;
  long long int b;
  cin >> b;
  long long int c;
  cin >> c;
  long long int m = abs(a) + abs(b);
  if (c < m)
    cout << "No" << endl;
  else {
    if ((c - m) % 2 == 0)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
