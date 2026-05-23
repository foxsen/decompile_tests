//firstly save by ctrl+s before running the code
//press f5 to debug and input in terminal
//typcast by e.g (long long)variable and for constant e.g 5ll
//-----------------------------------------------------------------------------------------------------------------------------
//count set bits using __builtin_popcount(n);
// cout << fixed << setprecision(10) << pi <<" "<<npi<<endl;-->synax to set precision for float/double datatype pi , npi
//ceil or floor used for double and return double 
//log also return double
//use floor(n)==n to see if a double n is integer
//for int x,y to get ceil in x/y do as (x+(y-1))/y and x/y itself equals floor only (but returns int)
//log2(n)==floor(log2(n))-->to check if power of 2 
//------------------------------------------FUN BEIGINS!-----------------------------------------------------------------------
#include<bits/stdc++.h>
#include<fstream>
#define N 1000000007
#define M 998244353
using namespace std;
#define ll long long
#define pll  pair<ll,ll>
#define vll  vector<ll>
#define vpll  vector<pll>
#define  vvll vector<vll>
#define endl "\n"                   //"\n" not flushes output but endl do
#define umap unordered_map<ll,ll>
//------------------------------------------------------------------------------------------------------------------------------
vector<vector<long long>>adj;
map<long,bool>vis,viss; 
vector<long long>rnk,parent,sz;
#define sieve_max 1000000
ll spf[sieve_max+1];
umap mp;
void yg(vll v, ll l, ll r,ll prev){
    if(r<l)return;

    if(r==l){mp[r]=prev; return;}
    ll mx=LLONG_MIN;
    ll ct=0;

  for(ll i=l;i<=r;i++){if(v[i]>mx){
      mx=v[i]; ct=i;
  }}
        
    mp[ct]=prev;

    yg(v,l,ct-1,prev+1); yg(v,ct+1,r,prev+1);

    return;


}

int main(){
    ios_base::sync_with_stdio(false);    cin.tie(NULL);
    ll t,temp;
    cin>>t; 
    while(t--){
        mp.clear();
        ll n;
        cin>>n; vll v;
        for(ll i=0;i<n;i++){
            cin>>temp; v.push_back(temp);
        }
        yg(v,0,n-1,0);

        for(ll i=0;i<n;i++)cout<<mp[i]<<" ";
        cout<<endl;


    }
   

       
     
return 0;
}