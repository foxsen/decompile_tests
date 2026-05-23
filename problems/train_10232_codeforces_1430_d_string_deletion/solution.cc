#include <bits/stdc++.h>
using namespace std;
char str[200001];
long long arr[200001];
int main() {
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    scanf("%s", str);
    int index = 0;
    for (int i = 0; i < n; i++) {
      int j = i + 1;
      int c = 1;
      while ((j < n) && (str[j] == str[i])) {
        j++;
        c++;
      }
      arr[index] = c;
      index++;
      i = j - 1;
    }
    int ptr = -1;
    for (int i = 0; i < index; i++) {
      if (arr[i] != 1) {
        ptr = i;
        break;
      }
    }
    int tot = 0;
    for (int i = 0; i < index; i++) {
      tot = tot + 1;
      if (arr[i] == 1) {
        if (ptr == -1) {
          i++;
        } else {
          arr[ptr]--;
          if (arr[ptr] == 1) {
            int j;
            for (j = ptr + 1; j < index; j++) {
              if (arr[j] != 1) {
                ptr = j;
                break;
              }
            }
            if (j == index) {
              ptr = -1;
            }
          }
        }
      } else {
        if (i == ptr) {
          int j;
          for (j = ptr + 1; j < index; j++) {
            if (arr[j] != 1) {
              ptr = j;
              break;
            }
          }
          if (j == index) {
            ptr = -1;
          }
        }
      }
    }
    cout << tot << endl;
  }
  return 0;
}
