#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <cmath>
#include <set>
#include <algorithm>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
using namespace std;

string s;
vector<string> ans;
void rec(int idx, vector<bool> state, string sum) {
    if(idx == s.size()) {
        ans.push_back(sum);
        return ;
    }
    char c = s[idx];
    if(state[c - 'a']) {
        rec(idx + 1, state, sum + c);
    }
    if(c + 1 <= 'z' && !state[c + 1 - 'a']) {
        state[c + 1 - 'a'] = true;
        rec(idx + 1, state, sum + string(1, (c + 1)));
    }
}

int main(){
    while(cin >> s && s != "#") {
        ans.clear();
        vector<bool> state(26, false);
        state[0] = true;
        rec(0, state, "");
        cout << ans.size() << endl;
        sort(ans.begin(), ans.end());
        if(ans.size() <= 10) {
            REP(i, ans.size()) cout << ans[i] << endl;
        } else {
            REP(i, 5) cout << ans[i] << endl;
            REP(i, 5) cout << ans[ ans.size() - 5 + i] << endl;
        }
    }
}