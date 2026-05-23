#include<bits/stdc++.h>
using namespace std;

class fraction {
    long long numer; // bunshi
    long long denom; // bunbo
public:
    fraction(long long numer, long long denom) : numer(numer), denom(denom) {}
    int compare_to(const fraction& f) const {
        assert(denom > 0 && f.denom > 0);
        long long res = numer * f.denom - denom * f.numer;
        if (res > 0) return 1;
        else if (res < 0) return -1;
        else return 0;
    }
    long double to_float() const {
        return numer / (long double)denom;
    }
};

using P = pair<fraction, fraction>;


int main() {
    long long t;
    int n;
    cin >> t >> n;
    vector<P> upper, lower, middle;
    for (int i = 0; i < n; ++i) {
        long long x, a, b;
        cin >> x >> a >> b;
        fraction ta(a, x * (t - x));
        fraction tb(b, x * (t - x));
        if (a * t > x * (t - x)) upper.push_back({ta, tb});
        else if (b * t < x * (t - x)) lower.push_back({ta, tb});
        else middle.push_back({ta, tb});
    }
    sort(upper.begin(), upper.end(), [](const P& a, const P& b) { return a.first.compare_to(b.first) > 0; });
    sort(lower.begin(), lower.end(), [](const P& a, const P& b) { return a.second.compare_to(b.second) < 0; });

    long double ans = 0;
    fraction last1(1e6 + 10, 1), last2(-(1e6 + 10), 1);
    for (auto& i : upper) {
        if (last1.compare_to(i.second) > 0) {
            ans += sqrt(i.first.to_float() * t * t / 2 + 1 / (i.first.to_float() * 2));
            last1 = i.first;
        }
    }
    for (auto& i : lower) {
        if (last2.compare_to(i.first) < 0) {
            ans += sqrt(i.second.to_float() * t * t / 2 + 1 / (i.second.to_float() * 2));
            last2 = i.second;
        }
    }
    bool ad = false;
    for (auto& i : middle) {
        if ((i.second.compare_to(last1) < 0 || i.first.compare_to(last1) > 0) && (i.second.compare_to(last2) < 0 || i.first.compare_to(last2) > 0)) {
            ad = true;
            break;
        }
    }
    if (ad) ans += sqrt(t);
    cout << setprecision(24) << ans << '\n';
    return 0;
}

