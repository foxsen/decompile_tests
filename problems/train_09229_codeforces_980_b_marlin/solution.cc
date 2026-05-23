#include <bits/stdc++.h>
using namespace std;
void center(vector<vector<char>> &arr, int row, int k, int n) {
  int mid = n / 2;
  arr[row][mid] = '#';
  k--;
  int i = mid - 1;
  int j = mid + 1;
  while (i >= 1 && j < n - 1 && k > 0) {
    arr[row][j] = '#';
    arr[row][i] = '#';
    i--;
    j++;
    k -= 2;
  }
}
void evenc(vector<vector<char>> &arr, int row, int k, int n) {
  int i = 1, j = n - 2;
  while (k > 0) {
    k -= 2;
    arr[row][i] = '#';
    arr[row][j] = '#';
    i++;
    j--;
  }
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, k;
  cin >> n >> k;
  if (k > 2 * (n - 2))
    cout << "NO";
  else {
    cout << "YES" << endl;
    vector<vector<char>> arr(4, vector<char>(n, '.'));
    if (k % 2 == 0) {
      for (int i = 0; i < k / 2; i++) {
        arr[1][i + 1] = '#';
        arr[2][i + 1] = '#';
      }
    } else {
      if (k > n - 2) {
        for (int i = 1; i < n - 1; i++) arr[1][i] = '#';
        k -= n - 2;
        evenc(arr, 2, k, n);
      } else {
        center(arr, 1, k, n);
      }
    }
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < n; j++) cout << arr[i][j] << "";
      cout << endl;
    }
  }
  return 0;
}
