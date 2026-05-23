#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n, i, j, k, l, flag, flag1, count, count1, count2, count3,
      count4, sum, max1, max2, c1, c2, temp, suma, sumb;
  long long int d, c, b;
  long long int a[300001], a1[300001];
  scanf("%lld", &t);
  for (l = 0; l < t; l++) {
    vector<long long int> v2, v4, v5;
    vector<string> v, v1;
    string s1, s2, s;
    long long int f[26], f1[26], f2[26];
    for (i = 0; i < 26; i++) f[i] = 0;
    for (i = 0; i < 26; i++) f1[i] = 0;
    for (i = 0; i < 26; i++) f2[i] = 0;
    count = 0, flag = 0, flag1 = 0, sum = 0, max1 = 0, max2 = 0, c1 = 0, c2 = 0,
    temp = 0, suma = 0, sumb = 0, count1 = 0, count2 = 0, count3 = 0,
    count4 = 0;
    long long int max3 = 0, max4 = 0, x, y, m1, max5 = 0, q, i1, j1, k1, m;
    cin >> c1 >> n;
    if (n % 2 == 0) {
      suma = n / 2 + 1;
      if (suma < c1) suma = c1;
      cout << n % suma << endl;
    } else {
      suma = n / 2 + 1;
      if (suma < c1) suma = c1;
      cout << n % suma << endl;
    }
  }
  return 0;
}
