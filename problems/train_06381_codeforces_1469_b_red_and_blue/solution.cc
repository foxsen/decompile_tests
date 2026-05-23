/*
------------------------------------------------------------
--                                                        --
--   cccccc   oooooooo    ddddd      eeeeee    rrrrr      --
--   cc       oo    oo    dd   dd    ee        rr   rr    --
--   cc       oo    oo    dd   dd    eeeeee    rrrrr      --
--   cc       oo    oo    dd   dd    ee        rr  rr     --
--   cccccc   oooooooo    ddddd      eeeeee    rr   rr    --
--                                                        --
------------------------------------------------------------
*/
#include<bits/stdc++.h>
#include<cmath>
#define ll long long int
#define accuracy(n,value) fixed<<setprecision(n)<<double(value)
#define floop(i,a,b) for(ll i=a;i<b;i++)
#define all(v) v.begin(), v.end()
#define pb(a) push_back(a)
#define INF 1e9+7
#define present(container, element) (container.find(element) != container.end())
#define cpresent(container, element) (find(all(container),element) != container.end())
using namespace std;


ll mod=1000000007;
ll getElement(set<int>&st,int index){
    return *(std::next(st.begin(), index));
}


ll power(ll x,ll y){
    ll ans=1;
    while(y--){
        ans*=x;
    }
    return ans;
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
  

  int t;
  cin>>t;

  while(t--){
         
      int n;
      cin>>n;

      
      vector<int>first(n+1,0);
      for(int i=1;i<=n;i++){
          int value;
          cin>>value;
          first[i]=first[i-1]+value;
      }

      int m;
      cin>>m;
      vector<int>second(m+1,0);
      for(int i=1;i<=m;i++){
          int value;
          cin>>value;
          second[i]=second[i-1]+value;
      }

      cout<<*max_element(all(first))+*max_element(all(second))<<'\n';
  }
}


