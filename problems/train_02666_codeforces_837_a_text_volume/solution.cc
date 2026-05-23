#include <bits/stdc++.h>
using namespace std;
char zifu[20000], c;
int fangxiang[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int fangxiang2[4][2] = {{1, -1}, {1, 1}, {-1, 1}, {-1, -1}};
int main() {
  int n;
  char a[300];
  cin >> n;
  c = getchar();
  gets(a);
  int zuida = 0;
  for (int i = 0; i < n; i++) {
    int temp = 0;
    while (a[i] != ' ' && i < n) {
      if (a[i] >= 'A' && a[i] <= 'Z') {
        temp++;
      }
      i++;
    }
    zuida = max(zuida, temp);
  }
  cout << zuida << endl;
  return 0;
}
