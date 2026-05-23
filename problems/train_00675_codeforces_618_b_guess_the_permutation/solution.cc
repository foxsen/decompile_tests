#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> matrix[52];
  int n;
  vector<int> fila(52, 0);
  cin >> n;
  for (int i = int(0); i < int(n); i++) {
    for (int j = int(0); j < int(n); j++) {
      int num;
      cin >> num;
      matrix[i].push_back(num);
    }
  }
  for (int i = int(0); i < int(n); i++) {
    vector<int> rep(51, 0);
    for (int j = int(0); j < int(n); j++) {
      rep[matrix[i][j]]++;
    }
    int pos = 0;
    int maxi = 0;
    for (int j = int(1); j < int(n); j++) {
      if (maxi < rep[j]) {
        pos = j;
        maxi = rep[j];
      }
    }
    fila[i] = pos;
    for (int j = int(0); j < int(n); j++)
      if (matrix[i][j] == j) matrix[i][j] == 0;
  }
  int pos1 = -1, pos2;
  for (int i = int(0); i < int(n); i++) {
    for (int j = int(0); j < int(n); j++) {
      if (matrix[i][j] == n - 1) {
        if (pos1 == -1) {
          pos1 = i;
        } else {
          pos2 = i;
        }
      }
    }
  }
  for (int i = int(0); i < int(n); i++) {
    if (i == pos1) {
      pos1 = -1;
      cout << n - 1 << " ";
    } else if (pos2 == i) {
      cout << n << " ";
    } else {
      cout << fila[i] << " ";
    }
  }
}
