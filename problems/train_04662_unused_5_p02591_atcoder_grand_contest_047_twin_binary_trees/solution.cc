#pragma GCC optimize("O3")   //
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef unsigned long long ull;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 300001;

ll h;

struct pt{
    ll x,y;
};

vi P;


ll PROD[MAXN][20] = {0};

int pp(ll i){
    return P[i-(1 << (h-1))] + (1 << (h-1));
}

ll C[MAXN] = {0};
int CC1[MAXN] = {0};
int cc1 = 0;
vi NEW1 = {0};
void reset(){
    trav(i,NEW1){
        C[i] = 0;
    }
    cc1++;
    NEW1.clear();
}

void add(ll p, ll to){
    C[to] += p;
    C[to] %= big;
    if(CC1[to] != cc1){
        CC1[to] = cc1;
        NEW1.push_back(to);
    }
    //cerr << "ADD: "  << p << " to: " << to << "\n";
}

void dfs(ll i, ll p, int start){
    while(i > 0){
        p *= i;
        p %= big;
        if(i > 1){
            ll other = (i/2)*2;
            if(other == i)other++;
            add((p*(i/2)), other);
        }

        if(i == 1)return;
        i /= 2;
    }
}

void setup(ll i, ll p){
    ll jj = i;
    ll nums = 1;
    ll b = 0;
    while(jj < (1 << (h-1))){
        jj *= 2;
        nums *= 2;
        b++;
    }

    rep(c1,0,nums){
        dfs(pp(jj+c1), PROD[jj+c1][b], i);
    }

}


int CC2[MAXN] ={0};
int cc2 = 0;

ll solve(ll i){
    reset();
    setup(2*i+1,1);
    ll j = i;

    ll nums = 1;
    while(j < (1 << (h-1))){
        j *= 2;
        nums *= 2;
    }
    nums /= 2;

    ll ans = 0;

    ll ppp = 0;
    ll jjj = i;
    while(jjj < (1 << (h-1))){
        jjj*=2;
        ppp++;
    }

    for(ll c1 = 0; c1 < nums; c1++){
        ll j2 = j+c1;
        cc2++;
        ll prod = 1;
        ll j3 = j2;

        prod = PROD[j3][ppp];

        j3 = pp(j2);

        while(j3 > 0){

           prod *= j3;
            prod %= big;
            ans += prod*C[j3];
            ans %= big;
            j3 /= 2;
        }

    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> h;
    n = (1 << h)+1;


    for(ll c1 = 1; c1 < (1 << h)+1; c1++){
        ll p = c1;
        ll c2 = c1;
        PROD[c1][0] = p;
        for(ll c3 = 1; c3 < 20; c3++){
            c2 /= 2;
            p *= c2;
            p %= big;
            PROD[c1][c3] = p;
        }
    }

    rep(c1,0,(1 << (h-1))){
        cin >> a;
        //a = c1+1;
        P.push_back(a-1);
    }

    ll ans = 0;
    rep(c1,1,(1 << (h-1))){
        ans += solve(c1);
        ans %= big;
    }

    cout << ans << "\n";

    return 0;
}
