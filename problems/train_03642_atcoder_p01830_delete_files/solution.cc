// #define _GLIBCXX_DEBUG // for STL debug (optional)
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
using namespace std;
using ll = long long int;
using int64 = long long int;
 
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int INF = 1001001001;
const ll LONGINF = 1001001001001001LL;
const ll MOD = 1000000007LL;
 
int main() {
    int N; cin >> N;
    vector<char> C(N);
    vector<int> L(N), pass(N), ord;
    for(int i=0; i<N; i++) {
        cin >> C[i] >> L[i];
        ord.emplace_back(i);
    }

    sort(ord.begin(), ord.end(), [&L](int a, int b) {
            return L[a] < L[b];
        });
    
    int ans = 0;
    for(int i=0; i<N; i++) {
        int k = ord[i];
        if(C[k] == 'n' or pass[k]) continue;
        ans++;
        for(int j=k; j>=0; j--) {
            if(C[j] == 'n' and L[j] >= L[k]) break;
            if(C[j] == 'y' and L[j] >= L[k]) pass[j] = true;
        }
        for(int j=k+1; j<N; j++) {
            if(C[j] == 'n' and L[j] >= L[k]) break;
            if(C[j] == 'y' and L[j] >= L[k]) pass[j] = true;
        }
    }
    cout << ans << endl;
    return 0;
}

