#include <iostream>
using namespace std;
int main(){
  int a,b,c,mon=0,k[10][10];
  cin>>a>>b;
  for(int i=0;i<=9;++i){
    for(int j=0;j<=9;++j){
      cin>>k[i][j];
    }
  }
  
  for(int i=0;i<=9;++i){
    for(int j=0;j<=9;++j){
      for(int kk=0;kk<=9;++kk){
        if(k[j][kk]>k[j][i]+k[i][kk]){
          k[j][kk]=k[j][i]+k[i][kk];
        }
      }
    }
  }
  
  for(int i=0;i<a;++i){
    for(int j=0;j<b;++j){
      cin>>c;
      if(c!=-1) mon+=k[c][1];
    }
  }
  
  cout<<mon<<endl;
}