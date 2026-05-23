#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    bool a = (n % 2 == 0), b = (s[0] == s[n-1]);
    if (a^b) cout << "Second" << endl;
    else cout << "First" << endl;
    return 0;
}