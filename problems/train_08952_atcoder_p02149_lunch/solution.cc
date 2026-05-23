#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if(a > b && a > c) cout << "A" << endl;
    else if(b > c) cout << "B" << endl;
    else cout << "C" << endl;
    return 0;
}

