#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    int m;
    cin >> m;
    ll digit = 0;
    ll sum = 0;
    for (int i = 0; i < m; i++) {
        ll d, c;
        cin >> d >> c;
        digit += c;
        sum += d * c;
    }
    cout << digit + (sum - 1) / 9 - 1 << endl;
    return 0;
}