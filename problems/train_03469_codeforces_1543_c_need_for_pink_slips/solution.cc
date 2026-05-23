    #include <bits/stdc++.h>
    using namespace std;
    #include <math.h>
    #include <iomanip>
    #include <cstdint>
    #include <string>
    #include <sstream>
    template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
    template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
    #define rep(i,n) for (int i = 0; i < (n); ++i)
    typedef long long ll;
    using P=pair<ll,ll>;
    const int INF=1001001001;
    const int mod=998244353;
    
    long double t=1000000;
    
    long double dfs(int c,int m,int p,int v){
        long double ans=p/t;
        if(c>0){
            if(c>v){
                if(m>0){
                    ans+=(c/t)*(1+dfs(c-v,m+v/2,p+v/2,v));
                }
                else{
                    ans+=(c/t)*(1+dfs(c-v,0,p+v,v));
                }
            }
            else{
                if(m>0){
                    ans+=(c/t)*(1+dfs(0,m+c/2,p+c/2,v));
                }
                else{
                    ans+=(c/t)*(1+dfs(0,0,p+c,v));
                }
            }
        }
        if(m>0){
            if(m>v){
                if(c>0){
                    ans+=(m/t)*(1+dfs(c+v/2,m-v,p+v/2,v));
                }
                else{
                    ans+=(m/t)*(1+dfs(0,m-v,p+v,v));
                }
            }
            else{
                if(c>0){
                    ans+=(m/t)*(1+dfs(c+m/2,0,p+m/2,v));
                }
                else{
                    ans+=(m/t)*(1+dfs(0,0,p+m,v));
                }
            }
        }
        return ans;
    }
    void solve(){
        long double q,w,e,r;
        cin>>q>>w>>e>>r;
        int c=round(t*q);
        int m=round(t*w);
        int p=round(t*e);
        int v=round(t*r);
        long double ans=dfs(c,m,p,v);
        printf("%.10Lf\n",ans);
    } 

    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int t;
        cin>>t;
        rep(i,t){
            solve();
        }
        
        return 0;
    }