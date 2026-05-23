/***********************************************
#      Filename: 1534_C.cpp
#      author:	 Dios
#      created:  2021-06-14 01:35:43
***********************************************/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int maxn=400005;
const int mod=1e9+7;
int T,n;
ll ans;
int p[maxn],q[maxn],nxt[maxn];
bool vis[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>p[i];
        for(int i=1;i<=n;i++) cin>>q[i],nxt[p[i]]=q[i];
        for(int i=1;i<=n;i++)vis[i]=false;
        ans=1;
        for(int i=1;i<=n;i++)
            if(!vis[i]){
                int j=i;
                while(!vis[j]) vis[j]=true,j=nxt[j];
                ans=2LL*ans%mod;
            }
        cout<<ans<<endl;
    }
}
