#include <bits/stdc++.h>
using namespace std;
long long maxi = 1000005;
long long mini = LLONG_MIN;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fast();
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long k = (n - 11) + 1;
  long long cnt = 0;
  for (long long i = 0; i < k; i++) {
    if (s[i] == '8') cnt++;
  }
  if (cnt >= ((k + 1) / 2))
    cout << "YES"
         << "\n";
  else
    cout << "NO"
         << "\n";
}
