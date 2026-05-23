#include<bits/stdc++.h>
using namespace std;

// ---------- Debugger

// #define TRACE

string to_string(string s) {
    return '"' + s + '"';
}

string to_string(char * s) {
    return to_string((string) s);
}

string to_string(const char * s) {
    return to_string((string) s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

template < typename A >
string to_string(A v);

template < typename A, typename B >
string to_string(pair < A, B > p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template < typename C > struct rge { C b, e; };
template < typename C > rge<C> range(C i, C j) { return rge<C>{i, j}; }

template < typename C > 
string to_string(rge<C> v) {
    bool first = true;
    string res = "[";
    for(auto it = v.b; it != v.e; it++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(*it);
    }
    res += "]";
    return res;
}

template < typename A >
string to_string(A v) {
    return to_string(range(v.begin(), v.end()));
}

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template < typename Head >
void __f(const string names, Head arg1) {
    cerr << names << " : " << to_string(arg1) << endl;
}
template < typename Head, typename...Tail >
void __f(const string names, Head arg1, Tail...args) {
    int b = 0, comma = names.size();
    for(int i=0;i<names.size();i++) {
        if(names[i] == ',' && b == 0) {
            comma = i;
            break;
        }
        if(names[i] == '(' || names[i] == '{' || names[i] == '[' || names[i] == '<') b++;
        else if(names[i] == ')' || names[i] == '}' || names[i] == ']' || names[i] == '>') b--;
    }
    // size_t comma = names.find(', ');
    cerr << names.substr(0, comma) << " : " << to_string(arg1) << " | ";
    __f(names.substr(comma + 1), args...);
}
#else
#define trace(...)
#endif

// ---------- Debugger

#define LL long long
#define FI ios_base::sync_with_stdio(false); cin.tie(NULL);
#define PREC cout << setprecision(10) << fixed;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 9;
const int MX = 1e5 + 5;

#define int long long

int sqrt(int x) {
    int i = 1;
    while(i * i <= x) {
        i++;
    }
    return i-1;
}

int32_t main() {
	int tt;
	cin >> tt;
	while(tt--) {
        int x, y;
        cin >> x >> y;
	
        int r = sqrt(x);

        if(y <= r) {
            int ans = (y * (y+1))/2 - y;
            cout << ans << endl;
            continue;
        } 

        int ans = (r * (r+1))/2 - r;
        y = min(y, x);

        trace(ans, y);

        //add totals
        for(int f=2;f<=r;f++) {
            int n = min(x/f, y) - r;
            n = max(n, 0ll);
            trace(f, x/f, y, r, n);
            ans += n;
        }
        trace(ans);

        //add partials
        for(int f=1;f<=r;f++) {
            int n = min((x - f)/f, y) - max(r, x/(f+1));
            n = max(n, 0ll);
            trace(f, (x-f)/f, y, r, n);
            ans += n;
        }

        cout << ans << endl;
	}
	
	return 0;
}






















