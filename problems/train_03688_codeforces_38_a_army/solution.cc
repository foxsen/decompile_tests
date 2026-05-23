#include <bits/stdc++.h>
using namespace std;
int N, a, b;
int arr[110];
int total = 0;
int main() {
  cin >> N;
  for (int i = 1; i <= N - 1; i++) {
    cin >> arr[i];
  }
  cin >> a >> b;
  for (int i = a; i <= b - 1; i++) {
    total = total + arr[i];
  }
  cout << total << endl;
}
