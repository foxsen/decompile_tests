#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<string>
#include<iomanip>
#include<bitset>
#include<list>

using namespace std;

#define ll long long int

ll const MOD = 1000000007;
ll const INF = (long long int)1 << 61;

ll mypow(ll x,ll n){
    ll ret = 1;
    while(n > 0){
        if(n&1){
            ret = (ret*x)%MOD;
        }
        x = (x*x)%MOD;
        n >>= 1;
    }
    return ret;
}

ll mypow(ll x,ll n,ll mod){
    ll ret = 1;
    while(n > 0){
        if(n & 1){
            ret = (ret * x) % mod;
        }
        x = (x * x)%mod;
        n >>= 1;
    }
    return ret;
}

struct pointSet{
    ll teamNum;
    ll totalVal;

    pointSet(vector<ll> &point){
        teamNum = point.size();
        ll base = 1;
        totalVal = 0;
        for(int i = 0; i < point.size(); i++){
            totalVal += base*point[i];
            base *= teamNum;
        }
    }

    vector<ll> getVal(){
        vector<ll> ret;
        ll r = teamNum;
        for(int i = 0; i < teamNum; i++){
            ll t = totalVal%r;
            ret.push_back(t);
            totalVal -= t;
            totalVal /= r;
        }
        return ret;
    }

    bool operator < (const pointSet &right)const{
        return totalVal < right.totalVal;
    }
};

void dfs(vector<ll> &vec,vector<pair<ll,ll>> &sel,map<pointSet,ll> &mp,vector<vector<ll>> &b,ll idx){
    if(idx == sel.size()){
        pointSet ps(vec);
        if(mp.find(ps) == mp.end()){
            mp.insert(make_pair(ps,1));
        }else{ 
            mp[ps]++;
        }
        return;
    }

    if(b[sel[idx].first][sel[idx].second] == 1){
        vec[sel[idx].first-1]++;
        dfs(vec,sel,mp,b,idx+1);
        vec[sel[idx].first-1]--;
    }else if(b[sel[idx].first][sel[idx].second] == -1){
        vec[sel[idx].second-1]++;
        dfs(vec,sel,mp,b,idx+1);
        vec[sel[idx].second-1]--;
    }else{
        vec[sel[idx].first-1]++;
        dfs(vec,sel,mp,b,idx+1);
        vec[sel[idx].first-1]--;
        vec[sel[idx].second-1]++;
        dfs(vec,sel,mp,b,idx+1);
        vec[sel[idx].second-1]--;
    }
}

ll solve(ll n){
    ll t;
    cin >> t;
    vector<vector<ll>> board(n+1,vector<ll>(n+1,0));
    for(int i = 0; i < t; i++){
        ll a,b;
        cin >> a >> b;
        board[a][b] = 1;
        board[b][a] = -1;
    }

    vector<pair<ll,ll>> sel1,sel2;
    ll m = 1;
    ll e = 2;
    for(int i = 0; i < (n*(n-1))/4; i++){
        sel1.push_back(make_pair(m,e));
        if(++e > n){
            e = ++m + 1;
        }
        /*cerr << m << " ";
        cerr << e << endl;*/
    }
    for(int i = (n*(n-1))/4; i < (n*(n-1))/2 ; i++){
        sel2.push_back(make_pair(m,e));
        if(++e > n){
            e = ++m + 1;
        }
        /*cerr << m << " ";
        cerr << e << endl;*/
    }
    map<pointSet,ll> mp1,mp2;
    vector<ll> vec(n,0);

    dfs(vec,sel1,mp1,board,0);
    dfs(vec,sel2,mp2,board,0);

    ll ans = 0;

    for(auto itr = mp1.begin(); itr != mp1.end(); itr++){
        vector<ll> need(n,0);
        auto ps = (*itr).first;
        bool cont = true;
        auto ret = ps.getVal();
        for(int i = 0; i < n; i++){
            ll x = ret[i];
            //cerr << x << " ";
            if(x > (n-1)/2){
                cont = false;
            }
            need[i] = (n-1)/2 - x;
        }
        //cerr << endl;
        if(cont && mp2.find(pointSet(need)) != mp2.end()){
            ans += mp2[pointSet(need)]*(*itr).second;
        }
    }
    return ans;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    vector<ll> ans;

    while(true){
        ll n;
        cin >> n;
        if(n == 0){
            break;
        }
        ans.push_back(solve(n));
    }

    for(auto &x:ans){
        cout << x << endl;
    }

    return 0;
}
