#include<bits/stdc++.h>
#define int long long int
#define inf 1000000000000
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define forf(i, a,b) for (int i = a; i <b; i++)
#define forr(i,a,b) for(int i=a;i>=b;i--)
#define tc(t) int t; cin >> t; while (t--)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int> >
#define vll vector<ll>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mii map<int,int>
#define mll map<ll,ll>
#define S(x) (int)(x).size()
#define L(x) (int)(x).length()
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
using namespace std;
void solve(){
int n;
cin>>n;
bool ig= true;
        int v[n+1][3];
        int tim=0,pos=0;
        int req=0,ans=0;
        bool go= true;
        for(int i=0;i<=n;i++) {
            int a=1e12,b=1e12;
            if(i!=n) cin>>a>>b;
            v[i][0]=a; v[i][1]=b;
            if(tim+req>a) {
                ig= false;
                if(go) v[i][2]= pos+ a-tim;
                else v[i][2]= pos -(a-tim);
//                cout<<"#"<<a-tim<<"# ";
            }else{
                if(go) pos+= req;
                else pos-= req;
                v[i][2]=pos;
                tim=a;
                req= abs(b-pos);
                if(b>=pos) go= true;
                else go= false;
                ig= true;
//                cout<<"$"<<pos<<"$ ";
            }
        }
        for(int i=0;i<n;i++) {
//            cout<<v[i][2]<<" ";
            if(v[i][2]<=v[i][1] && v[i][1]<= v[i+1][2]) ans++;
            else if(v[i][2]>=v[i][1] && v[i][1]>= v[i+1][2]) ans++;
        }
//        cout<<v[n-1][2]<<"@ ";
//        if(ig) ans++;
        cout<<ans<<"\n";
}
signed main(){
    IOS

    tc(t){
      solve();
    }
    return 0;
}
