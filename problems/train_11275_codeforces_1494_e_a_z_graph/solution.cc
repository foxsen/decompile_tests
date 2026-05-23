#include <bits/stdc++.h>

using namespace std;
using ll = long long;

set<pair<int, int>> mp[26];
map<pair<int, int>, char> st;

int main() {

    int n, m, ans[2] = {0};
    cin >> n >> m;

    while(m--){
        char x;
        cin >> x;
        if (x == '+') {
            int u, v;
            char c;
            cin >> u >> v >> c;
            st[{u, v}] = c;
            mp[c-'a'].insert({u, v});
            if(mp[c-'a'].find({v, u}) != mp[c-'a'].end()) ans[0]++;
            for(int i = 0; i < 26; i++){
                if(mp[i].find({v, u}) != mp[i].end()) ans[1]++;
            }
        } else if (x == '-') {
            int u, v;
            cin >> u >> v;
            char c = st[{u, v}];
            mp[c-'a'].erase({u, v});
            if(mp[c-'a'].find({v, u}) != mp[c-'a'].end()) ans[0]--;
            for(int i = 0; i < 26; i++){
                if(mp[i].find({v, u}) != mp[i].end()) ans[1]--;
            }
        } else {
            int u;
            cin >> u;
            cout << (ans[u%2] ? "YES" :"NO") << endl;
        }
    }

    return 0;
}
