#include<iostream>
#include<vector>
#include<cstdlib>
#include<complex>

using namespace std;

typedef complex<double> P;

vector<P> pl();

char *p;

double cross(P a,P b){
  return a.real()*b.imag()-a.imag()*b.real();
}

vector<P> plf(){
  p++;
  if(*p=='('){
    auto l=pl();
    p++;
    return l;
  }else{
    int x=strtol(p,&p,10);
    p++;
    int y=strtol(p,&p,10);
    p++;
    return {P(x,y)};
  }
}

vector<P> pl(){
  auto l=plf();
  while(*p=='@'){
    p++;
    auto r=plf();
    if(l.size()<r.size()){
      swap(l,r);
    }
    if(l.size()==1){
      l.push_back(r[0]);
    }else if(r.size()==1){
      l={l[0]+(r[0]-l[0])*polar(1.,(arg(l[1]-l[0])-arg(r[0]-l[0]))*2)};
    }else{
      l={l[0]+(l[1]-l[0])/cross(l[1]-l[0],r[1]-r[0])*cross(r[0]-l[0],r[1]-r[0])};
    }
  }
  return l;
}
    

int main(){
  for(char s[123];cin>>s,s[0]!='#';){
    p=s;
    auto r=pl()[0];
    cout<<fixed<<r.real()<<' '<<r.imag()<<endl;
  }
}