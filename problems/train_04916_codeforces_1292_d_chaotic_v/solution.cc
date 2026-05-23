#include <bits/stdc++.h>
using namespace std;
int zs[5005][5005];
int num[5005];
int mp[5005];
int main() {
  mp[1] = 1;
  for (int i = 2; i <= 5000; i++) {
    for (int j = 2; j < i; j++) {
      zs[i][j] = zs[i - 1][j];
    }
    int k = i;
    for (int j = 2; j * j <= k; j++) {
      while (!(k % j)) k /= j, zs[i][j]++, mp[i] = max(j, mp[i]);
    }
    if (k > 1) zs[i][k]++, mp[i] = max(k, mp[i]);
  }
  for (int i = 2; i <= 5000; i++) {
    mp[i] = max(mp[i - 1], mp[i]);
  }
  int n;
  long long sz = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int k;
    scanf("%d", &k);
    num[k]++;
  }
  for (int i = 1; i <= 5000; i++) {
    for (int j = 1; j <= i; j++) sz += 1ll * num[i] * zs[i][j];
  }
  while (1) {
    vector<long long> V(5005, 0);
    for (int i = 1; i <= 5000; i++) {
      V[mp[i]] += num[i];
    }
    int pos = max_element(V.begin(), V.end()) - V.begin();
    long long val = V[pos];
    if (n >= 2 * val || pos == 1) break;
    sz -= 2 * val - n;
    for (int i = 1; i <= 5000; i++) {
      if (mp[i] != pos)
        num[i] = 0;
      else {
        if (zs[i][mp[i]]) zs[i][mp[i]]--;
        while (mp[i] > 1 && (!zs[i][mp[i]])) mp[i]--;
      }
    }
  }
  cout << sz << endl;
}
