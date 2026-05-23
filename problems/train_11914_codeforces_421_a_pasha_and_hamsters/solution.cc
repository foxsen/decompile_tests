#include <bits/stdc++.h>
using namespace std;
long long T, C = 1, N;
void process() {
  int arr[1000];
  int n, a, b;
  for (int i = 0; i < 104; i++) {
    arr[i] = 2;
  }
  cin >> n >> a >> b;
  for (int i = 0; i < a; i++) {
    int x;
    cin >> x;
    arr[x] = 1;
  }
  for (int i = 0; i < b; i++) {
    int x;
    cin >> x;
  }
  cout << arr[1];
  for (int i = 2; i <= n; i++) {
    cout << " " << arr[i];
  }
  cout << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  process();
  return 0;
}
