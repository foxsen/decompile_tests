#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int lat[5][5];

vector<vector<int>> bx = {
    {0, 1, 2, 3, 4},
    {0, 1, 2, 3, 4},
    {0, 1, 2, 3, 4},
    {0, 1, 2, 3, 4},
    {0, 1, 2, 3, 4},
    {0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1},
    {2, 2, 2, 2, 2},
    {3, 3, 3, 3, 3},
    {4, 4, 4, 4, 4}
};

vector<vector<int>> by = {
    {0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1},
    {2, 2, 2, 2, 2},
    {3, 3, 3, 3, 3},
    {4, 4, 4, 4, 4},
    {0, 1, 2, 3, 4},
    {0, 1, 2, 3, 4},
    {0, 1, 2, 3, 4},
    {0, 1, 2, 3, 4},
    {0, 1, 2, 3, 4}
};

string rev(string s) {
    reverse(s.begin(), s.end());
    return s;
}

int dfs(vector<string> &v, int k) {
    if (k == 10) {
        return 1;
    }
    vector<string> S(1, v[k]);
    if (v[k] != rev(v[k])) {
        S.push_back(rev(v[k]));
    }
    int ret = 0;
    for (string bloc : S) {
        for (int i=0; i<10; ++i) {
            bool ok = true;
            vector<int> t;
            for (int j=0; j<5; ++j) {
                if ((lat[by[i][j]][bx[i][j]] & 1 && bloc[j] - '0' == 0) ||
                    (lat[by[i][j]][bx[i][j]] & 2 && bloc[j] - '0' == 1)) {
                    ok = false;
                    break;
                }
                t.push_back(lat[by[i][j]][bx[i][j]]);
            }
            if (ok) {
                for (int j=0; j<5; ++j) {
                    lat[by[i][j]][bx[i][j]] |= (bloc[j] - '0' + 1);
                }
                ret += dfs(v, k+1);
                for (int j=0; j<5; ++j) {
                    lat[by[i][j]][bx[i][j]] = t[j];
                }
            }
        }
    }
    return ret;
}

int main() {
    vector<string> v(10);
    while (cin >> v[0], v[0] != "END") {
        for (int i=1; i<10; ++i) {
            cin >> v[i];
        }
        memset(lat, 0, sizeof lat);
        int ret = dfs(v, 0);
        cout << (ret == 0 ? 0 : ret / 8) << endl;
    }
    return 0;
}