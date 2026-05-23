#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define MAX 300000
typedef long long ll;

char t[MAX],d[MAX];
ll N,Q;
string s;




bool mycheck(ll goal,ll place){
  for(ll i=1;i<=Q;i++){
    if(t[i]==s[place-1]){
      if(d[i]=='L') place--;
      else place++;
    }
    if(place==goal) return true;
    if(place==0 || place==N+1) return false;
  }
  return false;
}

int main(){
  cin>>N>>Q>>s;

  for(ll i=1;i<=Q;i++){
    cin>>t[i]>>d[i];
  }

  ll s=0,e=N+1,ans0,ansN,ans,h;
  h=(s+e)/2;

  while(true){
    if(mycheck(0,h)) s=h;
    else e=h;
    h=(s+e)/2;
    if(s+1==e) break;
  }
  ans0=s;

  s=0,e=N+1;
  h=(s+e)/2;

  while(true){
    if(mycheck(N+1,h)) e=h;
    else s=h;
    h=(s+e)/2;
    if(s+1==e) break;
  }
  ansN=e;
  if(ans0+1>=ansN) ans=N;
  else ans=ans0+(N+1-ansN);
  cout<<N-ans<<endl;




}
