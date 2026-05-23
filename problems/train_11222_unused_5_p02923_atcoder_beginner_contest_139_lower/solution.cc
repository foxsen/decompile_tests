#include<bits/stdc++.h>
using namespace std;

int v[(int)1e5+5], n;

int main(){
  cin>>n;
  int c=1, s=0;

  cin>>v[0];
  for(int i=1;i<n;i++){
    cin>>v[i];
    if(v[i-1]>=v[i])
        c++;
    else{
        s=max(s, c);
        c=1;
    }
  }

  cout<<max(s, c)-1;
}
