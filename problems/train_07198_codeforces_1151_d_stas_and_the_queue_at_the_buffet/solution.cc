#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int arr[n];
  long long int sumb = 0;
  long long int suma = 0;
  for (long long int i = 0; i <= n - 1; i++) {
    long long int a, b;
    cin >> a >> b;
    suma = suma + a;
    sumb = sumb + b;
    arr[i] = a - b;
  }
  sort(arr, arr + n);
  long long int g = 0;
  for (long long int i = 1; i <= n; i++) {
    g = g + (arr[n - i] * i);
  }
  g = g + (sumb * n) - suma;
  cout << g << endl;
}
