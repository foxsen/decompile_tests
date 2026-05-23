#include "bits/stdc++.h"
using namespace std;

#define chota(a) transform(a.begin(), a.end(), a.begin(), ::tolower)
#define pure cout << fixed << setprecision(18)
#define kitnabit(x) __builtin_popcount(x)
#define ll long long
#define newline cout << "\n"
#define speed ios_base::sync_with_stdio(0); cin.tie(0)

const int N = 1e2 + 2;
int n;

void clearEverything() {
   
}


void solve(int tno) {
    cin >> n;
    vector<int> data(n + 1, 0);
    vector<int> cnt(N, 0);
    set<int> s;
    vector<int> ans;

    for (int i = 1; i <= n; i++) {
        cin >> data[i];
        s.insert(data[i]);
        cnt[data[i]] += 1;
    }
    for (int x : s) {
        ans.push_back(x);
        cnt[x] -= 1;
    }
    for (int i = 0; i <= 100; i++) {
        for (int j = 1; j <= cnt[i]; j++) {
            ans.push_back(i);
        }
    }
    for (int x : ans) cout << x << " " ;
    newline;
}
int main() {
    speed;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}