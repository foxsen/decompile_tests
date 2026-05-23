#include<bits/stdc++.h>
using namespace std;

int main(){
  int p;
  string a[2],c,ans;
  while(1){
    cin>>a[0];
    if(a[0]=="-")break;
    cin>>a[1]>>c;
    p=1;
    while(c.size()){
      if(c[0]==a[p][0]){
	if(c.size())c=c.substr(1,c.size()-1);
	if(a[p].size())a[p]=a[p].substr(1,a[p].size()-1);
	p=0;
      }else{
	ans+=a[p][0];
	if(a[p].size())a[p]=a[p].substr(1,a[p].size()-1);
	p=1;
      }
    }
    ans+=a[0];
    ans+=a[1];
    cout<<ans<<endl;
    ans.clear();
    a[0].clear();
    a[1].clear();
    c.clear();
  }
  return 0;
}