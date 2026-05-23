#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a;
    cin >> a;
    int ret = 0;
    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        if (a < x)ret++;
        a = x;
    }
    cout << ret << endl;
    return 0;
}

