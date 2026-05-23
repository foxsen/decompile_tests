#include<bits/stdc++.h>
#define optimize() ios_base::sync_with_stdio(0);
#define ll long long
using namespace std;
int main()
{
   
    int t;cin>>t;
    while(t--)

    {
        ll n,i,j,k=1,x,y,m,sum;
        ll a[210000],b[210000],c;
        map<ll,ll>mp1;
        cin>>n;
        vector<ll>v[n+3];
        vector<ll>v1[n+3];
        map<pair<int,int>,ll>mp;
        pair<int,int>p;
        for(i=1;i<=n;i++){
          cin>>a[i];
          if(mp1[a[i]]==0){
            b[k]=a[i];k++;
          }
          mp1[a[i]]=1;
        }
        for(i=1;i<=n;i++){
            cin>>c;
            v[a[i]].push_back(c);
            a[i]=0;
        }
        sort(b+1,b+k);
        for(i=1;i<k;i++){
          x=b[i];sum=0;
          sort(v[x].rbegin(),v[x].rend());
          for(j=0;j<v[x].size();j++){
            sum+=v[x][j];
           // cout<<sum<<" ";
           p=make_pair(x,j+1);
           mp[p]=sum;
           v1[j+1].push_back(x);
          }
            
        }
        
        for(i=1;i<=n;i++){
          sum=0;
          for(auto u:v1[i]){
            y=v[u].size()/i;
            y=y*i;
           // cout<<y<<" ";
            p=make_pair(u,y);
            sum+=mp[p];
          }
          cout<<sum<<" ";
        }
        cout<<endl;
    }
return 0;
}


