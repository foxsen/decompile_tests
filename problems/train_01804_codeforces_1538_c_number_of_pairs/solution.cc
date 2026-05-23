#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vll vector<ll>
#define F first
#define S second
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//"\n" __builtin_popcount
using namespace std;
int N;
vll T;
map<int,int>ind;
ll query(int pos){
   ll res=0;
   while(pos>0){
      res+=T[pos];
      pos-=(pos&-pos);
   }
   return res;
}
void update(int pos){
   while(pos<=N){
      T[pos]++;
      pos+=(pos&-pos);
   }
}
int main(){
   fast
   int t,n,l,r,x;
   cin>>t;
   set<int>st;
   vi v;
   while(t--){
      v.clear();
      ind.clear();
      st.clear();
      cin>>n>>l>>r;
      for(int i=0;i<n;i++){
         cin>>x;
         v.pb(x);
         st.insert(x);
         if(l-x>0){
            st.insert(l-x);
         }
         if(r-x>0){
            st.insert(r-x);
         }
      }
      int num=1;
      for(auto it : st){
         ind[it]=num;
         num++;
      }
      N=num;
      T.assign(N+2,0);
      ll res=0;
      for(int i=0;i<n;i++){
         x=v[i];
         int a=max(l-x,1),b=r-x;
         if(b>0){
            res+=query(ind[b])-query(ind[a]-1);
         }
         update(ind[x]);
      }
      cout<<res<<"\n";
   }
   return 0;
}
