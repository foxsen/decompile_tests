#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    map<char, set<int>> chars;
    for (int i = 0; i < s.size(); i++) {
        chars[s[i]].insert(i);
        chars[s[i]].insert(i + s.size());
    }
    int64_t ret = 0;
    for (int i = 0; i < t.size(); i++) {
        if (chars[t[i]].empty()) {
            ret = -1;
            break;
        }
        int p = ret % s.size();
        auto it = chars[t[i]].lower_bound(p);
        ret += *it - p + 1;
    }

    cout << ret << endl;

    return 0;
}
