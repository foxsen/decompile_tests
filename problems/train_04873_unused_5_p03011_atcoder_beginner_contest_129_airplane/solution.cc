#include<bits/stdc++.h>
using namespace std;
int main(){
  int p,q,r;
  cin>>p>>q>>r;
  cout<<min(p,q)+min(q,r)+min(p,r)-min(p,min(q,r));
}
