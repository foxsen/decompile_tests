#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    bool fwin = false;
    while (N--) {
        int a; cin >> a;
        if (a % 2 != 0) fwin = true;
    }
    if (fwin) cout << "first" << endl;
    else cout << "second" << endl;
}