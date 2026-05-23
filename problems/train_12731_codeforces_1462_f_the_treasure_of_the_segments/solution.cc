#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector <vector <int>> vvi;
typedef vector <ll> vl;
typedef vector <vector <ll>> vvl;
typedef vector <bool> vb;
typedef vector <vector <bool>> vvb;

//const int kINF_int = INT_MAX;
//const long long kINF_long = LONG_LONG_MAX;

inline void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

template <typename type1, typename type2>
ostream &operator<<(ostream &out, const pair <type1, type2> &p) {
    out << '[' << p.first << ", " << p.second << ']';
    return out;
}

template <typename type>
ostream &operator<<(ostream &out, const vector <type> &massive) {
    for (const type &i : massive) {
        out << i << ' ';
    }
    return out;
}

template <typename type>
void print(const vector <type> &massive, const string &sep = " ", const string &end = "\n") {
    if (!massive.empty()) {
        cout << massive[0];
        for (int i = 1; i < massive.size(); ++i) {
            cout << sep << massive[i];
        }
    }
    cout << end;
}

template <typename type>
void print(const type &mass, const string &end = "\n") {
    cout << mass << end;
}

void solve() {
    int n;
    cin >> n;

    vector <pair <int, int>> lr(n);
    vector <int> lefts(n), rights(n);
    for (int i = 0; i < n; ++i) {
        cin >> lefts[i] >> rights[i];
        lr[i] = {lefts[i], rights[i]};
    }
    sort(lr.begin(), lr.end());
    sort(lefts.begin(), lefts.end());
    sort(rights.begin(), rights.end());

    int max_collisions = 1, now_collisions = 0, now_left = 0, now_right = 0;
    for (auto segment : lr) {
        for (; now_right < rights.size() && rights[now_right] < segment.first; ++now_right) {
            --now_collisions;
        }
        for (; now_left < lefts.size() && lefts[now_left] <= segment.second; ++now_left) {
            ++now_collisions;
        }
        max_collisions = max(max_collisions, now_collisions);
    }

    print(n - max_collisions);
}

int main() {
    fast();

    //freopen("../input.txt", "r", stdin);

    int t;
    cin >> t;
    for (int never_use = 0; never_use < t; ++never_use) {
        solve();
    }

    return 0;
}
