#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <chrono>
#include <stack>
#include <string>
#include <bitset>
#include <unordered_map>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <cassert>
#include <tuple>
#include <iomanip>
#include <random>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <fstream>
using namespace std;
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define popb pop_back()
#define ll long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define forn(x) for(int i=1;i<=x;i++) 
#define sforn(x, y) for(int i=1;i<=x;i++)for(int j=1;j<=y;j++)
#define pii pair<int, int>
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  
/*
    LOL KEK CHEBUREK
  
    PIHALITI
  
*/
void solve() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int cnt1=0, cnt2 = 0;
    for(int i = 0; i < s1.size(); i++) {
        if(s1[i] > s2[i]) {
            cnt1++;
        } else if(s1[i] < s2[i]){
            cnt2++;
        }
    }
    if(cnt1 > cnt2) {
        cout <<  "RED" << endl;
    } else if(cnt1 < cnt2) {
        cout << "BLUE" << endl;
    } else {
        cout << "EQUAL" << endl;
    }
}
int main() {
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
} 