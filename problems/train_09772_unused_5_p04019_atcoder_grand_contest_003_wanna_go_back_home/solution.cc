#include <map>
#include <iostream>
using namespace std;
int main(int argc, char** argv) {
    string s; cin >> s;
    map<char, bool> m;
    for (char c : s) m[c] = true;
    cout << ((m['N'] == m['S'] && m['E'] == m['W']) ? "Yes" : "No") << endl;
}
