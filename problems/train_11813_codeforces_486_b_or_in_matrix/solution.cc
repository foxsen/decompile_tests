#include <bits/stdc++.h>
using namespace std;
void initCode() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
const long long int N = 1000000007;
vector<double> primeNumber;
void SieveOfEratosthenes(int n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (long long int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long int i = p * p; i <= n; i += p) {
        prime[i] = false;
      }
    }
  }
  long long int i = 0;
  for (long long int p = 2; p <= n; p++) {
    if (prime[p]) {
      primeNumber.push_back((double)p);
    }
  }
}
long long int mod(long long int a) { return (a % N + N) % N; }
int arr[101][101];
int ans[101][101];
void pre() {
  for (int i = 0; i < 101; i++) {
    for (int j = 0; j < 101; j++) ans[i][j] = 1;
  }
}
void sol() {
  int n, m;
  cin >> n >> m;
  pre();
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      if (arr[i][j] == 0) {
        for (long long int k = 0; k < n; k++) {
          ans[k][j] = 0;
        }
        for (long long int r = 0; r < m; r++) {
          ans[i][r] = 0;
        }
      }
    }
  }
  int row[n];
  int col[m];
  for (long long int i = 0; i < n; i++) {
    row[i] = 0;
    for (long long int j = 0; j < m; j++) {
      if (ans[i][j] == 1) {
        row[i] = 1;
      }
    }
  }
  for (long long int i = 0; i < m; i++) {
    col[i] = 0;
    for (long long int j = 0; j < n; j++) {
      if (ans[j][i] == 1) {
        col[i] = 1;
      }
    }
  }
  bool x = 1;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      if (arr[i][j] == 1) {
        if (!(row[i] == 1 || col[j] == 1)) {
          cout << "NO" << endl;
          return;
        }
      }
      if (arr[i][j] == 0) {
        if (!(row[i] == 0 && col[j] == 0)) {
          cout << "NO" << endl;
          return;
        }
      }
    }
  }
  cout << "YES" << endl;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}
int main() {
  initCode();
  sol();
  return 0;
}
