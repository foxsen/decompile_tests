#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define pi M_PI
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

int main() {
    string s, t, s1, s2;
    cin >> s >> t;
    REP(i,s.length()){
        if (i % 2 == 0) s1 += s[i];
        else s2 += s[i];
    }
    int j1 = 0, j2 = 0;
    for (int i=0; i < t.length() && j1 < s1.length() && j2 < s2.length(); i++){
        if (t[i] == s1[j1]) j1++;
        if (t[i] == s2[j2]) j2++;
    }
    if (j1 == s1.length() || j2 == s2.length()) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}