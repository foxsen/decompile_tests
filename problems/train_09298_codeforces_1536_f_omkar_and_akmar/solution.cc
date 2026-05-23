#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
const ll lp = 1e9+7;
const int msize = 1e6+7;

//! ll power
ll powmod(int a, int x){ //a^x
    if (x == 0) return 1;
    if (x % 2 == 0){
        ll temp = powmod(a,x/2);
        return (temp*temp) % lp;
    }else{
        ll temp = powmod(a,x/2);
        return ((temp*temp) % lp * a) % lp;
    }
}
ll lpinv(int a){ //inverse of a under the prime
    return powmod(a,lp-2);
}
//! ll ncr offset
ll ncroffset(int n, int r, int n0, int r0, int prev){
    ll ans = prev;
    if (r == 0 || n == r) return 1;

    //*numerator
    if (n > n0){ 
        for (int i=n0+1; i<=n; ++i){
            ans = (ans*i) % lp;
        }
    }else if (n < n0){
        for (int i=n0; i>n; --i){
            ans = (ans*lpinv(i)) % lp;
        }
    }

    //*denominator1
    if (r > r0){
        for (int i=r0+1; i<=r; ++i){
            ans = (ans*lpinv(i)) % lp;
        }
    }else if (r < r0){
        for (int i=r0; i>r; --i){
            ans = (ans*i) % lp;
        }
    }

    //*denominator2
    r = n-r;
    r0 = n0-r0;
    if (r > r0){
        for (int i=r0+1; i<=r; ++i){
            ans = (ans*lpinv(i)) % lp;
        }
    }else if (r < r0){
        for (int i=r0; i>r; --i){
            ans = (ans*i) % lp;
        }
    }

    return ans;

}
vector<ll> facarr(msize,0);
void facpre(){
    facarr[0] = 1;
    for (int i=1; i<msize; ++i){
        facarr[i] = (facarr[i-1]*i) % lp;
    }
    return;
}

int m,n,k,cnt,idx,len,temp,test_cnt;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    facpre();
    //cout << ncr(8,5) << endl;
    //cout << fac(10) << endl;
    //cout << ncroffset(8,5,7,6,7) << endl;
    //cout << lpinv(2) << endl;

    cin >> cnt;
    int twocnt = cnt/2, onecnt = cnt % 2;
    if ((twocnt + onecnt) % 2){
        twocnt--;
        onecnt+=2;
    }
    ll ans = 0;
    int n0,r0,v0;
    n0 = r0 = v0 = 1;
    while(twocnt >= 0){
        v0 = ncroffset(twocnt+onecnt, twocnt,n0,r0,v0);
        n0 = twocnt+onecnt;
        r0 = twocnt;

        ll part = (v0*facarr[twocnt+onecnt]) % lp;
        //cout << part <<  " " << twocnt << " " << onecnt << '\n';
        ans = (ans+part) % lp;
        twocnt-=2;
        onecnt+=4;
    }


    twocnt = cnt/2-1; onecnt = cnt % 2;
    if ((twocnt + onecnt) % 2 == 0){
        twocnt--;
        onecnt+=2;
    }
    n0 = r0 = v0 = 1;
    while(twocnt >= 0){
        v0 = ncroffset(twocnt+onecnt, twocnt,n0,r0,v0);
        n0 = twocnt+onecnt;
        r0 = twocnt;

        ll part = (v0*facarr[twocnt+onecnt+1]) % lp;
        //cout << part <<  " " << twocnt << " " << onecnt << '\n';
        ans = (ans+part) % lp;
        twocnt-=2;
        onecnt+=4;
    }

    ans = (ans*2) % lp;
    cout << ans << endl;
    
    return 0;
}