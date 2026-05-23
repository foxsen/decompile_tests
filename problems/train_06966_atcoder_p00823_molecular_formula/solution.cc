#include <bits/stdc++.h>

using namespace std;

#define LOG(...) fprintf(stderr, __VA_ARGS__)
//#define LOG(...)
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define RFOR(i, a, b) for (int i = (int)(b - 1); i >= (int)(a); --i)
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define RREP(i, n) for (int i = (int)(n - 1); i >= 0; --i)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define EXIST(s, e) ((s).find(e) != (s).end())
#define SORT(c) sort(ALL(c))
#define RSORT(c) sort(RALL(c))
#define SZ(a) ((int)(a).size())
#define BIT(x, i) (((x) >> (i)) & 1)
#define SQ(x) ((x) * (x))

typedef long long ll;
typedef unsigned long long ull;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

class ParseError {};

map<string, int> atoms;

int number(string& s, int& idx) {
    int n = 0;
    while (isdigit(s[idx])) {
        n *= 10;
        n += s[idx] - '0';
        idx++;
    }
    return n;
}

string atom(string& s, int& idx) {
    stringstream sym;
    sym << s[idx];
    idx++;
    while (islower(s[idx])) {
        sym << s[idx];
        idx++;
    }
    return sym.str();
}

int molecule(string& s, int& idx) {
    int res = 0;
    for (; idx < s.length();) {
        if (s[idx] == '(') {
            idx++;
            int a = molecule(s, idx);
            int b = number(s, idx);
            res += a * b;
        } else if (s[idx] == ')') {
            idx++;
            return res;
        } else if (isalpha(s[idx])) {
            int n;
            while (1) {
                string sym = atom(s, idx);
                if (!EXIST(atoms, sym)) throw ParseError();
                if (isalpha(s[idx])) {
                    res += atoms[sym];
                } else {
                    n = atoms[sym];
                    break;
                }
            }
            if (isdigit(s[idx])) {
                n *= number(s, idx);
            }
            res += n;
        } else {
            assert(0);
        }
    }
    return res;
}

int main() {
    // H2C = 1*2+12
    // Cu(OH)2 = 64+(16+1)*2

    string sym;
    while (cin >> sym, sym != "END_OF_FIRST_PART") {
        int weight;
        cin >> weight;
        atoms[sym] = weight;
    }
    string s;
    while (cin >> s, s != "0") {
        try {
            int idx = 0;
            cout << molecule(s, idx) << endl;
        } catch (ParseError e) {
            cout << "UNKNOWN" << endl;
        }
    }
}