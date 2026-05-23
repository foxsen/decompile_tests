#include <bits/stdc++.h>
using namespace std;
string s, d;
bool corr = false;
void func() {
  if (cin >> s) {
    d += s;
    if (s == "pair") {
      d += "<";
      func();
      d += ',';
      func();
      d += ">";
    }
  } else
    corr = true;
}
int main() {
  int n, i = 0;
  cin >> n;
  func();
  if (corr || cin >> s) {
    cout << "Error occurred";
  } else
    cout << d;
}
