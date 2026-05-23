#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cin >> x;
  string names[x * 2];
  for (int i = 0; i < x * 2; i++) cin >> names[i];
  for (int i = 0; i < x * 2; i++)
    if (names[i] == "rat") {
      cout << names[i - 1];
      cout << endl;
    }
  for (int i = 0; i < x * 2; i++)
    if (names[i] == "woman" || names[i] == "child") {
      cout << names[i - 1];
      cout << endl;
    }
  for (int i = 0; i < x * 2; i++)
    if (names[i] == "man") {
      cout << names[i - 1];
      cout << endl;
    }
  for (int i = 0; i < x * 2; i++)
    if (names[i] == "captain") {
      cout << names[i - 1];
      cout << endl;
    }
  return 0;
}
