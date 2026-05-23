#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int ret = 0;
  while (n--) {
    char str[1009];
    int cnt = 0;
    scanf("%s", str);
    int flag = 1;
    for (int i = 0; str[i]; i++) {
      if (str[i] == '4' || str[i] == '7') {
        cnt++;
        if (cnt > m) {
          flag = 0;
          break;
        }
      }
    }
    if (flag == 1) {
      ret++;
    }
  }
  cout << ret << endl;
  return 0;
}
