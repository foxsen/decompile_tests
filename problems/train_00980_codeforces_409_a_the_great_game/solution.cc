#include <bits/stdc++.h>
using namespace std;
string a, b;
int wa, wb;
int main() {
  cin >> a >> b;
  for (int i = 0; i < a.size(); i += 2) {
    if (a[i] == '8' && b[i] == '[') wa++;
    if (a[i] == '[' && b[i] == '(') wa++;
    if (a[i] == '(' && b[i] == '8') wa++;
    if (b[i] == '8' && a[i] == '[') wb++;
    if (b[i] == '[' && a[i] == '(') wb++;
    if (b[i] == '(' && a[i] == '8') wb++;
  }
  if (wa > wb)
    puts("TEAM 1 WINS");
  else if (wa < wb)
    puts("TEAM 2 WINS");
  else
    puts("TIE");
  return 0;
}
