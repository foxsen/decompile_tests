#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ara[26];
  for (int i = 0; i < 26; i++) {
    ara[i] = 0;
  }
  for (int i = 0, len = s.length(); i < len; i++) {
    ara[s[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    if (ara[i] % n != 0) {
      printf("-1");
      return 0;
    }
    ara[i] /= n;
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < ara[i]; j++) {
        printf("%c", i + 'a');
      }
    }
  }
  printf("\n");
}
