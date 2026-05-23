#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
using namespace std;
#define INF 100000000

typedef long long ll;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

const int L = 16 * 9 * 5 * 7 * 11;

int main(void) {
    int N;
    while (cin >> N && N) {
        int Q[25][25] = {{0}};
        for (int i = 0; i < N; i++) {
            int d, t;
            cin >> d >> t;
            for (int j = 0; j < d; j++) {
                int q;
                cin >> q;
                Q[d][(j+d-t) % d] += q;
            }
        }
        int sum = 0, T[L] = {0};
        for (int d = 1; d <= 24; d++) {
            if (d == 13 || d == 17 || d == 19 || d == 23) {
                int ma = 0;
                for (int i = 0; i < d; i++) ma = max(ma, Q[d][i]);
                sum += ma;
            } else {
                for (int i = 0; i < L; i++) {
                    T[i] += Q[d][i%d];
                }
            }
        }
        int ma = 0;
        for (int i = 0; i < L; i++) ma = max(ma, T[i]);
        cout << sum + ma << endl;
    }
    return 0;
}