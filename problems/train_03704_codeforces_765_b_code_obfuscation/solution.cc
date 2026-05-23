#include <bits/stdc++.h>
using namespace std;
bool letter[512] = {0};
char str[512];
int main() {
  gets(str);
  char temp = 'a';
  int i;
  for (i = 0; str[i] != 0; i++) {
    if (str[i] == temp)
      temp++;
    else if (str[i] > temp)
      break;
  }
  if (str[i] == 0 && temp <= 'z' + 1)
    puts("YES");
  else
    puts("NO");
}
