#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[10000], b[10000];
  int a1 = 0, b1 = 0;
  cin >> a >> b;
  for (int i = 0; i < strlen(a); i++)
    if (a[i] == '1') a1++;
  for (int i = 0; i < strlen(b); i++)
    if (b[i] == '1') b1++;
  a1 += a1 % 2;
  if (a1 >= b1)
    cout << "YES";
  else
    cout << "NO";
}
