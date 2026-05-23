#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;

int length, n;
vector<int> a;
map<pair<int,int>, double> memo;

double dist(int i, int j) {
    return sqrt(4 * a[i] * a[j]);
}

double f(int p, int prev) {
    if (__builtin_popcount(p) == 0) {
        return a[prev];
    }
    if (memo.count(make_pair(p, prev))) return memo[make_pair(p, prev)];
    double ret = 1e+300;
    for (int i = 0; i < n; ++ i) if ((p>>i)&1) {
        if (prev == -1) {
            ret = min(ret, f(p&~(1<<i), i) + a[i]);
        } else {
            ret = min(ret, f(p&~(1<<i), i) + dist(prev, i));
        }
    }
    return memo[make_pair(p, prev)] = ret;
}

bool solve() {
    n = a.size();
    if (n == 0) return true;
    if (n == 1) return 2 * a[0] <= length;
    double len = f((1<<n)-1, -1);
    return len <= length + 1e-9;
}

int main() {
    string buf;
    while (getline(cin, buf)) {
        istringstream in(buf);
        in >> length;
        a.clear();
        memo.clear();
        for (int x; in >> x; ) a.push_back(x);
        cout << (solve() ? "OK" : "NA") << endl;
    }
}
