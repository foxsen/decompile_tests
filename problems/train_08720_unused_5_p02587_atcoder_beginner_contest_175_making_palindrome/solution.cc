#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct state {
    string pref, suff;
    ll cost;

    int hash() {
        ll res = 0;
        for (int i=0;i<pref.length();i++) {
            res = (res*41+pref[i]-'a'+1)%1000000007;
        }
        for (int i=0;i<suff.length();i++) {
            res = (res*43+suff[i]-'a'+1)%1000000007;
        }
        return res;
    }
};

bool cmp(state a, state b) {
    return a.cost>b.cost;
}

bool chk(state a) {
    string x = a.pref, y = a.suff;
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    return a.pref==x&&a.suff==y;
}

string s[55];
ll w[55];
priority_queue<state, vector<state>, decltype(&cmp)> pq(cmp);
map<int, ll> dist;
set<int> dead;

int main() {
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i=0;i<n;i++) cin >> s[i] >> w[i];

    for (int i=0;i<n;i++) {
        state now = {s[i], "", w[i]};
        pq.push(now);
        dist[now.hash()] = w[i];
    }
    while (pq.size()) {
        state now = pq.top(); pq.pop();
        //cout << now.pref << " | " << now.suff << " " << now.cost << endl;
        dead.insert(now.hash());
        if (chk(now)) {
            cout << now.cost << endl;
            return 0;
        }

        string cur = now.pref+now.suff;
        for (int i=0;i<n;i++) {
            int ok = 1;
            string t = s[i];
            if (now.pref.length()>0) reverse(t.begin(), t.end());
            int len = min(cur.length(), t.length());

            for (int p=0;p<len;p++) {
                if (cur[p]!=t[p]) ok = 0;
            }
            if (ok) {
                string a = cur.substr(len);
                string b = t.substr(len);
                state x = {a, b, now.cost+w[i]};
                if (now.pref.length()==0) {
                    swap(x.pref, x.suff);
                }
                int hsval = x.hash();
                if (dist.find(hsval)==dist.end()||dist[hsval]>x.cost) {
                    if (dead.find(hsval)==dead.end()) {
                        dist[hsval] = x.cost;
                        pq.push(x);
                    }
                }
            }
        }
    }
    cout << -1 << endl;
}
