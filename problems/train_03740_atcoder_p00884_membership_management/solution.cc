#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < int(n); ++i)

int solve(map<int, set<int>>& group, unsigned m) {
    vector<char> vis(m, 0);
    function<int(int)> dfs = [&](int k) {
        if (vis[k]) return 0;
        vis[k] = 1;
        if (!group.count(k)) return 1;
        int cnt = 0;
        for (const int& i : group[k]) cnt += dfs(i);
        return cnt;
    };
    return dfs(0);
}

int main() {
    for (int n; cin >> n, n;) {
        cin.ignore();
        map<string, int> id;
        auto getid = [&](string& s) {
            int t = id.size();
            return id.count(s) ? id[s] : id[s] = t;
        };
        map<int, set<int>> group;
        while (n--) {
            string s; getline(cin, s);
            for (auto& e : s) if(ispunct(e)) e = ' ';
            stringstream ss(s);
            ss >> s;
            int i = getid(s);
            for (; ss >> s; group[i].insert(getid(s)));
        }
        cout << solve(group, id.size()) << endl;
    }
}