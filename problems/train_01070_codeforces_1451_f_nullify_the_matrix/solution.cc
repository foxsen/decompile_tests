#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;
const int N = 1e6 + 10;
int a[200];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        memset(a, 0, sizeof(a));
        int n, m;
        cin >> n >> m;
        for(int i = 1;i <= n;++i)
            for(int j = 1;j <= m;++j) {
                int temp;
                cin >> temp;
                a[i + j - 1] ^= temp;
            }
        int flag = 1;
        for(int i = 1;i <= n + m - 1;++i) {
            if(a[i]) flag = 0;
        }
        cout << (flag ? "Jeel" : "Ashish") << endl;
    }
}
