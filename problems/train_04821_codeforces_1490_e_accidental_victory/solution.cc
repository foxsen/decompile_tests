/* -> Written by <-
   -----------
  |K_A_Z_A_M_A|
  |___________|
  |    ___    |
  |   (^_^)   |
  |  /( | )\  |
  |____|_|____|
    H O A N G
*/

#include <bits/stdc++.h>

#define Task            ""
#define F               first
#define S               second
#define pb              push_back
#define bit(x, i)       ((x >> (i)) & 1)
#define inf             1e9 + 7
#define INF             1e18 + 7
#define ll              long long
#define pii             pair <int, int>
#define debug(x)        cerr << #x << " is " << x << "\n";

using namespace std;

const int MOD = 1e9 + 7;
const int maxn = 1e6 + 5;

int n;
pair <int, int> a[200005];
ll s[200005];

void Solve(){
    cin >> n;
    for (int i = 1; i <= n; ++ i){
        int x; cin >> x;
        a[i] = {x, i};
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++ i){
        s[i] = s[i-1] + a[i].F;
    }
    vector <int> res;
    res.pb(a[n].S);
    for (int i = n - 1; i >= 1; -- i){
        if (s[i] >= a[i+1].F){
            res.pb(a[i].S);
        }
        else break;
    }
    sort(res.begin(), res.end());
    cout << (int)res.size() << "\n";
    for (auto p : res)
        cout << p << " ";
    cout << "\n";
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    if(fopen(Task".inp", "r")){
        freopen(Task".inp","r",stdin);
        freopen(Task".out","w",stdout);
    }
    int test_case = 1;
     cin >> test_case;
    while (test_case --){
        Solve();
    }
    return 0;
}
