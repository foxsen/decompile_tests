#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int gcd(int a, int b) {
    while (b > 0) {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

map<pair<int, int>, int> mem;

int get(int x, int y) {
    x = abs(x);
    y = abs(y);
    return gcd(x, y);
//    typedef typename map<pair<int, int>, int>::mapped_type V;
//    auto r = mem.insert({{x, y}, V()});
//    V &v=r.first->second;
//    if (r.second)
//        v = gcd(x, y);
//    return v;
}

long calc(long w, long h, long k) {
    long res = 0;
    vector<int> mem(h + 1);
    vector<int> t2(h + 1);
    vector<int> mem2(h + 1);
    for (long b = 1; b < w; b++) {
        for (long c = 1; c < h && c * w <= 2 * (k + w); c++) {
            int mm = get(c, b);
//            c * w + (a - c) * b <= 2k;
            long mina = max((2 * k - c * w) / b + c, c);
            mina = min(mina, h);
            if (mina > c) {
                res += (mina - c) * 2 - 1;
            }
            for (long a = mina; a < h && c * w + (a - c) * b <= 2 * (k + w); a++) {
                long s = c * w + (a - c) * b;
                if (s / 2 <= k) {
                    res++;
                    if (a != c) res++;
                    continue;
                }
                long g = mm;
                if ((s - g + 2) / 2 <= k) {
                    res++;
                    if (a != c) res++;
                    continue;
                }
                if (t2[a] != b) {
                    t2[a] = b;
                    mem2[a] = get(a, w - b);
                }
                g += mem2[a];
                if ((s - g + 2) / 2 <= k) {
                    res++;
                    if (a != c) res++;
                    continue;
                }
                if (mem[a - c] == 0) {
                    mem[a - c] = get(a - c, w);
                }
                g += mem[a - c];
                if ((s - g + 2) / 2 <= k) {
                    res++;
                    if (a != c) res++;
                    continue;
                }
            }
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);

    int w, h, k;
    cin >> w >> h >> k;
    auto start = std::chrono::high_resolution_clock::now();
    cout << (calc(w, h, k) + calc(h, w, k)) * 2;
    auto finish = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = finish - start;
    cerr << elapsed.count() << "\n";

    return 0;
}
