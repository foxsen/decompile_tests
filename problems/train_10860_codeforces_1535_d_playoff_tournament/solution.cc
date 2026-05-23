#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <bitset>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <random>
#include <stdio.h>
#define reado freopen("INPUT.txt", "r", stdin); freopen("OUTPUT.txt", "w", stdout)
//#define reado freopen("peacefulsets.in", "r", stdin); freopen("peacefulsets.out", "w", stdout)
#define bist ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define kolvo1(x) __builtin_popcount(x)
const int mod = 1e9 + 7, MAXN = 1e5 + 1;
const ll inf = 1e18;
const double eps = 1e-12;
using namespace std;
/**/



signed main() {
    //reado;
    bist;
    int k;
    cin >> k;
    int n = (1 << k) - 1;
    string s;
    cin >> s;
    reverse(s.begin(),s.end());
    int q;
    cin >> q;
    vector<int> dp(n);
    for(int i = n-1; i >= 0; i--) {
        if (s[i] == '0') {
            if (i*2 + 2 < n) {
                dp[i] = dp[i*2+2];
            } else {
                dp[i] = 1;
            }
        }
        else if (s[i] == '1') {
            if (i*2+1 < n) {
                dp[i] = dp[i*2+1];
            }
            else {
                dp[i] = 1;
            }
        }
        else if (s[i] == '?') {
            if (i*2 +2 < n) {
                dp[i] = (dp[i*2+2]+dp[i*2+1]);
            } else {
                dp[i] = 2;
            }
        }
    }
    while (q--) {
        int i;
        char neww;
        cin >> i >> neww;
        i = n - i;
        int f = 229;
        s[i] = neww;
        do {
            if (s[i] == '0') {
                if (i * 2 + 2 < n) {
                    dp[i] = dp[i * 2 + 2];
                }
                else {
                    dp[i] = 1;
                }
            }
            else if (s[i] == '1') {
                if (i * 2 + 1 < n) {
                    dp[i] = dp[i * 2 + 1];
                }
                else {
                    dp[i] = 1;
                }
            }
            else if (s[i] == '?') {
                if (i * 2 + 2 < n) {
                    dp[i] = (dp[i * 2 + 2] + dp[i * 2 + 1]);
                }
                else {
                    dp[i] = 2;
                }
            }
            i = (i-1)/2;
            if (i == 0 && f == 229) f = 1;
            else if (i == 0) f = 0;
        } while(i != 0 || f);
        cout << dp[0] << '\n';
    }
    
}