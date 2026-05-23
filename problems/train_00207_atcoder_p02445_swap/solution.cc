#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <list>
#include <stack>
#include <cctype>
#include <cmath>

using namespace std;

/* typedef */

typedef long long ll;

/* constant */

const int INF = 1 << 30;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */

/* function */
void printVec(vector<int> &vec);

/* main */
int main(){

    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    
    int q; cin >> q;
    int l, r, t;
    for (int i = 0; i < q; i++) {
        cin >> l >> r >> t;
        // swap_ranges(begin, end, swap_begin);
        // begin ~ end <-> swap_begin ~ swap_begin + (end - begin)
        swap_ranges(v.begin() + l, v.begin() + r, v.begin() + t);
    }

    printVec(v);

    return 0;
}

void printVec(vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        if (i) cout << ' ' ;
        cout << vec[i];
    } cout << '\n';

}

