//32
#include<iostream>
#include<vector>
#include<utility>

using namespace std;

typedef pair<int,int> pii;

#define S(X) ((X)*(X))

int main(){
  for(int a,b,r;cin>>a>>b>>r,a|b|r;){
    int x[100000],y[100000];
    for(int i=0;i<a;i++){
      cin>>x[i]>>y[i];
    }
    vector<pii> v[250][250];
    for(int i=0;i<b;i++){
      int xb,yb;
      cin>>xb>>yb;
      v[yb/40][xb/40].push_back(pii(yb,xb));
    }
    int s=0;
    for(int i=0;i<a;i++){
      int yy=y[i]/40,xx=x[i]/40;
      for(int j=-1;j<=1;j++){
	for(int k=-1;k<=1;k++){
	  int yt=yy+j,xt=xx+k;
	  if(0<=yt&&yt<250&&0<=xt&&xt<250){
	    for(int l=0;l<v[yt][xt].size();l++){
	      s+=S(y[i]-v[yt][xt][l].first)+S(x[i]-v[yt][xt][l].second)<=S(4*r);
	    }
	  }
	}
      }
    }
    cout<<s<<endl;
  }
  return 0;
}