#include <bits/stdc++.h>
using namespace std;
bool is_odd(int i) { return i % 2; }
void printname();
void printname();
int x = 4;
int main() {
  bool check = true;
  int n, m, k, socket, no_lin = 0;
  cin >> n >> m >> k;
  vector<int> sockets;
  for (int i = 0; i < n; i++) {
    cin >> socket;
    sockets.push_back(socket);
  }
  sort(sockets.rbegin(), sockets.rend());
  if (k >= m) {
    cout << 0;
  } else {
    for (int i = 0; i < n; i++) {
      no_lin += sockets[i];
      if ((no_lin - i) + (k - 1) >= m) {
        cout << i + 1;
        check = false;
        break;
      }
    }
    if (check == true) {
      cout << -1;
    }
  }
  return 0;
}
