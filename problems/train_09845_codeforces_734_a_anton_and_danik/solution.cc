#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  long long int times;
  times = 1;
  while (times--) {
    long long int n;
    cin >> n;
    string str;
    cin >> str;
    long long int ant = 0, dan = 0;
    for (long long int i = 0; i < n; i++) {
      if (str[i] == 'A')
        ant++;
      else
        dan++;
    }
    if (ant > dan)
      cout << "Anton"
           << "\n";
    else if (dan > ant)
      cout << "Danik"
           << "\n";
    else
      cout << "Friendship"
           << "\n";
  }
  return 0;
}
