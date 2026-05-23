#include <bits/stdc++.h>
using namespace std;
int main() {
  string theWord = "";
  int shiftRight = 0;
  int shiftDown = 0;
  int faces = 0;
  int n;
  int m;
  cin >> n;
  cin >> m;
  char arr[n][m];
  char letter;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> letter;
      arr[i][j] = letter;
    }
  }
  for (int y = 0; y < n - 1; y++) {
    for (int x = 0; x < m - 1; x++) {
      for (int i = shiftDown; i < shiftDown + 2; i++) {
        for (int j = shiftRight; j < shiftRight + 2; j++) {
          theWord += arr[i][j];
        }
      }
      if (theWord.find('f') != string::npos &&
          theWord.find('a') != string::npos &&
          theWord.find('c') != string::npos &&
          theWord.find('e') != string::npos) {
        faces++;
      }
      theWord.clear();
      shiftRight++;
    }
    shiftRight = 0;
    shiftDown++;
  }
  cout << faces << endl;
  return 0;
}
