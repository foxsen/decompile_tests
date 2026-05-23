#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

typedef basic_string<int> IS;

int main(){
  for(int a,b,c,d,e,na,nb,nc;cin>>a>>b>>c>>d>>e>>na>>nb>>nc,a;){
    IS is=IS(nc,c)+IS(nb,b)+IS(na,a);
    int m,cs=a*na+b*nb+c*nc;
    m=cs;
    for(int i=0;i<is.size();i++){
      cs-=is[i];
      m=min(m,cs+max(i+1,d)*e);
    }
    cout<<m<<endl;
  }
}

  
  