#include <bits/stdc++.h>
using namespace std;
using std::map;
const int CMAX = 100005;
const char Cfd[] = "", Cfr[] = "";
int main() {
  int n;
  string s;
  cin >> n >> s;
  for (int i = 0; i < s.length(); i++)
    if (s[i] == '*')
      for (int j = 1; i + 4 * j < s.length(); j++)
        if (s[i + j] == '*' && s[i + 2 * j] == '*' && s[i + 3 * j] == '*' &&
            s[i + 4 * j] == '*') {
          cout << "yes";
          return 0;
        }
  cout << "no";
  return 0;
}
