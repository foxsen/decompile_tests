#include <iostream>
#include <vector>
using namespace std;

int main ()
{
    int n, k, m;
    while (cin >> n >> k >> m, (n || m || k)) {
        vector<int> v(n);
        for (int i = 1; i <= n; i++) {
            v[i - 1] = i;
        }
        m--;

        while (v.size() > 1) {
            v.erase(v.begin() + m);
            m = (m + k - 1) % v.size();
        }
        cout << v[0] << endl;
    }

    return 0;
}