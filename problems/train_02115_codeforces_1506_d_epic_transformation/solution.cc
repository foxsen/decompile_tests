// g++ -std=c++17 -DLOCAL a.cpp -o ex && ./ex >tst.out 2>&1
#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
    return '"' + s + '"';
}
 
string to_string(const char* s) {
    return to_string((string) s);
}
 
string to_string(bool b) {
    return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}
 
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
 
void debug_out() { cerr << "   "; }
void debug_out_nl() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

template <typename Head, typename... Tail>
void debug_out_nl(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out_nl(T...);
}
 
#ifdef LOCAL
#define dbg(...) cerr << "#" << #__VA_ARGS__ << ":", debug_out(__VA_ARGS__)
#define nl(...) cerr << "#" << #__VA_ARGS__ << ":", debug_out_nl(__VA_ARGS__)
#else
#define dbg(...) 69
#define nl(...) 42
#endif

#define ll long long

const int MOD = 1e9 + 7;
const int N = 2e5 + 10;

int n, k;
string s;

void solve(int test, istream &cin, ostream &cout) {
    cin >> n;
    map<int, int> mp; 
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        mp[x]++;
    }

    multiset<int> s;
    for (auto it : mp) {
        s.insert(it.second);
    }

    int ans = n;
    while ((int) s.size() > 1) {
        auto it = s.end();
        it = prev(it);
        auto it2 = prev(it);

        ans -= 2;
        int v1 = *it;
        int v2 = *it2;

        s.erase(it);
        s.erase(it2);

        if (v1 - 1 > 0) {
            s.insert(v1 - 1);
        }
        if (v2 - 1 > 0) {
            s.insert(v2 - 1);
        }
    }

    cout << ans << '\n';
}

int main() {
    // ifstream cin("tst.in");
    // ofstream cout("tst.out");
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    bool multiTest = true;

    int t;    
    if (multiTest) {
        cin >> t;
    } else {
        t = 1;
    }

    for (int test = 1; test <= t; test++) {
        solve(test, cin, cout);
    }

    return 0;
}