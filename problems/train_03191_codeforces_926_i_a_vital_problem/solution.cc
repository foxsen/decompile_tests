#include <bits/stdc++.h>
using namespace std;
int a[101];
int min(int a, int b) { return a < b ? a : b; }
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int h = (s[0] - '0') * 10 + s[1] - '0';
    int m = (s[3] - '0') * 10 + s[4] - '0';
    a[i] = h * 60 + m;
  }
  sort(a, a + n);
  a[n] = a[0] + 1440;
  int max = a[1] > a[0] ? a[1] - a[0] - 1 : 0;
  for (int i = 1; i < n; i++) {
    int s = a[i + 1] > a[i] ? a[i + 1] - a[i] - 1 : 0;
    if (s > max) max = s;
  }
  int h = max / 60;
  int m = max % 60;
  if (h < 10) printf("0");
  printf("%d:", h);
  if (m < 10) printf("0");
  printf("%d\n", m);
}
