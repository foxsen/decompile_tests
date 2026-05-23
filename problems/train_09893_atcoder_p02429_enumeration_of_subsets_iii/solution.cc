#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    int k; cin >> k;
    int mask = 0;
    while (k--) { int i; cin >> i; mask |= 1 << i; }
    for (int b = mask; ; b = (b - 1) & mask) {
        int rb = b ^ mask;
        cout << rb << ":";
        for (int i = 0; i < n; i++) if (rb >> i & 1) cout << " " << i;
        cout << endl;
        if (!b) break;
    }
    return 0;
}
