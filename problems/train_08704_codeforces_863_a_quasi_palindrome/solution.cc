#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int main() {
  long long ind;
  string s;
  cin >> s;
  for (long long i = (long long)s.size() - 1; i >= 0; i--) {
    if (s[i] != '0') {
      ind = i;
      break;
    }
  }
  long long i = 0, j = ind;
  while (i <= j) {
    if (s[i] != s[j]) return cout << "NO", 0;
    i++;
    j--;
  }
  cout << "YES";
  return 0;
}
