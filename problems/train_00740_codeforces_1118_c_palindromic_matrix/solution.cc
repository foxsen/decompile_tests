#include <bits/stdc++.h>
using namespace std;
int a[1001], mat[21][21];
queue<int> n2;
queue<int> n4;
int n1;
int main() {
  int n, t;
  cin >> n;
  for (int i = 1; i <= n * n; i++) {
    cin >> t;
    a[t]++;
  }
  int odd = 0, oddi;
  int r = 1, c = 1;
  if (n % 2 == 0) {
    for (int i = 1; i <= 1000; i++) {
      while (a[i] >= 4) {
        n4.push(i);
        a[i] -= 4;
        if (n4.size() == n * n / 4) break;
      }
      if (n4.size() == n * n / 4) break;
    }
    if (n4.size() == n * n / 4)
      cout << "YES" << endl;
    else {
      cout << "NO" << endl;
      return 0;
    }
    for (int i = 1; i <= n / 2; i++) {
      for (int j = 1; j <= n / 2; j++) {
        int t = n4.front();
        n4.pop();
        mat[i][j] = t;
        mat[n - i + 1][j] = t;
        mat[i][n - j + 1] = t;
        mat[n - i + 1][n - j + 1] = t;
      }
    }
  } else {
    int x4 = (n - 1) * (n - 1) / 4;
    int x2 = (n - 1);
    for (int i = 1; i <= 1000; i++) {
      while (a[i] >= 4) {
        n4.push(i);
        a[i] -= 4;
        if (n4.size() == x4) break;
      }
      if (n4.size() == x4) break;
    }
    for (int i = 1; i <= 1000; i++) {
      while (a[i] >= 2) {
        n2.push(i);
        a[i] -= 2;
        if (n2.size() == x2) break;
      }
      if (n2.size() == x2) break;
    }
    for (int i = 1; i <= 1000; i++) {
      if (a[i]) {
        n1 = i;
        break;
      }
    }
    if (n4.size() != x4 || n2.size() != x2) {
      cout << "NO";
      return 0;
    } else {
      cout << "YES" << endl;
      for (int i = 1; i <= n / 2; i++) {
        for (int j = 1; j <= n / 2; j++) {
          int t = n4.front();
          n4.pop();
          mat[i][j] = t;
          mat[n - i + 1][j] = t;
          mat[i][n - j + 1] = t;
          mat[n - i + 1][n - j + 1] = t;
        }
      }
      for (int i = 1; i <= n / 2; i++) {
        int t = n2.front();
        n2.pop();
        mat[i][n / 2 + 1] = t;
        mat[n - i + 1][n / 2 + 1] = t;
      }
      for (int i = 1; i <= n / 2; i++) {
        int t = n2.front();
        n2.pop();
        mat[n / 2 + 1][i] = t;
        mat[n / 2 + 1][n - i + 1] = t;
      }
      mat[n / 2 + 1][n / 2 + 1] = n1;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) cout << mat[i][j] << ' ';
    cout << endl;
  }
}
