#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<string> names;
  vector<pair<int, int> > results;
  bool flag = false;
  for (int i = 0; i < n; i++) {
    string ime;
    int poeni1, poeni2;
    cin >> ime >> poeni1 >> poeni2;
    if (poeni1 >= 2400 && poeni2 > poeni1) flag = true;
  }
  if (flag == true)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
