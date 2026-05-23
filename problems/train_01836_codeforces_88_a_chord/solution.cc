#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[10], c = 0, k = 0, m = 0, case1, case2, case3, case4, case5, case6,
               case7, case8;
  string str;
  string str1 = "CQDWEFRGTABH";
  getline(cin, str);
  for (int i = 0; i < str.size(); i = i + 2) {
    if (str[i + 1] == '#') {
      if (str[i] == 'C') {
        str[i] = 'Q';
      }
      if (str[i] == 'D') {
        str[i] = 'W';
      }
      if (str[i] == 'F') {
        str[i] = 'R';
      }
      if (str[i] == 'G') {
        str[i] = 'T';
      }
      c++;
    }
    for (int j = 0; j < str1.size(); j++) {
      if (str[i] == str1[j]) {
        arr[k] = j;
        k++;
        break;
      }
    }
    if (c == 1) {
      i++;
      c = 0;
    }
  }
  sort(arr, arr + 3);
  do {
    if ((arr[1] - arr[0] == 3 || (12 - (arr[0] - arr[1]) == 3)) &&
        (arr[2] - arr[1] == 4 || (12 - (arr[1] - arr[2]) == 4))) {
      cout << "minor" << endl;
      m++;
      break;
    }
    if ((arr[1] - arr[0] == 4 || (12 - (arr[0] - arr[1]) == 4)) &&
        (arr[2] - arr[1] == 3 || (12 - (arr[1] - arr[2]) == 3))) {
      cout << "major" << endl;
      m++;
      break;
    }
  } while (next_permutation(arr, arr + 3));
  if (m == 0) {
    cout << "strange" << endl;
  }
  return 0;
}
