#include <bits/stdc++.h>
using namespace std;
string fi, se;
void input() {
  ios_base::sync_with_stdio(0);
  getline(cin, fi);
  getline(cin, se);
}
void output() {
  for (int i = 0; i < fi.length(); ++i)
    for (int j = 0; j < se.length(); ++j)
      if ((fi[i] == se[j]) && (fi[i] != ' ')) {
        cout << "YES";
        return;
      }
  cout << "NO";
}
int main() {
  input();
  output();
  return 0;
}
