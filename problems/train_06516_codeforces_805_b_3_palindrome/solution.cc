#include <bits/stdc++.h>
using namespace std;
int main() {
  string prohibit[] = {"aaa", "bab", "cac", "bbb", "bbb",
                       "cbc", "aca", "bcb", "ccc"};
  string list[] = {"ab", "aa", "ac", "bb", "ba", "bc", "cc", "ca", "cb"};
  string ans;
  int n;
  scanf("%d", &n);
  if (n == 1)
    printf("a\n");
  else if (n == 2)
    printf("aa\n");
  else {
    ans = "aa";
    printf("%s", ans.c_str());
    for (int i = 2; i < n; i++) {
      for (int j = 0; j < 9; j++) {
        if (ans == list[j]) {
          switch (j) {
            case 0:
              ans.push_back('b');
              break;
            case 1:
              ans.push_back('b');
              break;
            case 2:
              ans.push_back('b');
              break;
            case 3:
              ans.push_back('a');
              break;
            case 4:
              ans.push_back('a');
              break;
            case 5:
              ans.push_back('a');
              break;
            case 6:
              ans.push_back('a');
              break;
            case 7:
              ans.push_back('a');
              break;
            case 8:
              ans.push_back('a');
              break;
          }
          break;
        }
      }
      printf("%c", ans[2]);
      ans[0] = ans[1];
      ans[1] = ans[2];
      ans.pop_back();
    }
  }
  printf("\n");
}
