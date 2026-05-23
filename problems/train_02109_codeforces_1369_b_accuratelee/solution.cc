#include <bits/stdc++.h>
using namespace std;
int t, n, last;
string s, wynik;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> s;
    wynik = "";
    int ile0 = 0, ile1 = 0;
    for (int i = 0; i < s.size() && s[i] != '1'; i++) ile0++;
    for (int i = s.size() - 1; i >= 0 && s[i] != '0'; i--) ile1++;
    for (int i = 0; i < ile0; i++) cout << '0';
    if (n > ile0 + ile1) cout << '0';
    for (int i = 0; i < ile1; i++) cout << '1';
    cout << wynik << "\n";
  }
}
