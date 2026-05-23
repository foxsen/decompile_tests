#include <bits/stdc++.h>
using namespace std;
struct compare {
  bool operator()(const pair<int, int>& l, const pair<int, int>& r) {
    if (l.first == r.first) {
      return l.second > r.second;
    }
    return l.first > r.first;
  }
};
bool isgood(vector<vector<int>>& A, int i, int j) {
  if (i < A.size() - 1 && A[i + 1][j] == A[i][j]) {
    return true;
  }
  if (j < A[i].size() - 1 && A[i][j + 1] == A[i][j]) {
    return true;
  }
  if (i > 0 && A[i - 1][j] == A[i][j]) {
    return true;
  }
  if (j > 0 && A[i][j - 1] == A[i][j]) {
    return true;
  }
  return false;
}
void print(vector<vector<int>> X) {
  for (int i = 0; i < X.size(); i++) {
    for (int j = 0; j < X[i].size(); j++) {
      cout << X[i][j] << " ";
    }
    cout << endl;
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, T;
  cin >> n >> m >> T;
  vector<int> d(m, 0);
  vector<vector<int>> A(n, d);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      int a = s[j] - '0';
      A[i][j] = a;
    }
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, compare> Q;
  vector<vector<int>> X(n, d);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (X[i][j] == 0) {
        X[i][j] = isgood(A, i, j);
      }
      if (X[i][j] == 1) {
        Q.push({1, 1000 * i + j});
      }
    }
  }
  while (!Q.empty()) {
    pair<int, int> u = Q.top();
    Q.pop();
    int i = u.second / 1000;
    int j = u.second % 1000;
    if (i < X.size() - 1 && X[i + 1][j] == 0) {
      X[i + 1][j] = X[i][j] + 1;
      Q.push({X[i + 1][j], 1000 * (i + 1) + j});
    }
    if (i > 0 && X[i - 1][j] == 0) {
      X[i - 1][j] = X[i][j] + 1;
      Q.push({X[i - 1][j], 1000 * (i - 1) + j});
    }
    if (j < X[i].size() - 1 && X[i][j + 1] == 0) {
      X[i][j + 1] = X[i][j] + 1;
      Q.push({X[i][j + 1], 1000 * i + j + 1});
    }
    if (j > 0 && X[i][j - 1] == 0) {
      X[i][j - 1] = X[i][j] + 1;
      Q.push({X[i][j - 1], 1000 * i + j - 1});
    }
  }
  for (int t = 0; t < T; t++) {
    int i, j;
    long long int k;
    cin >> i >> j >> k;
    i--;
    j--;
    if (X[i][j] > k || X[i][j] == 0) {
      cout << A[i][j] << endl;
    } else {
      cout << (A[i][j] + (k - X[i][j] + 1) % 2) % 2 << endl;
    }
  }
  return 0;
}
