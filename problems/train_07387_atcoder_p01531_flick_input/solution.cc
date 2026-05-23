#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<vector>
#include<cmath>
#include<cstdio>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define it ::iterator
#define all(in) in.begin(),in.end()
const double PI=acos(-1);
const double ESP=1e-10;
using namespace std;
char tmp[10]={' ',' ','k','s','t','n','h','m','y','r'};
int main(){
  map<char,char>t;
  t['T']='a';
  t['L']='i';
  t['U']='u';
  t['R']='e';
  t['D']='o';
  string in;
  cin>>in;
  int j=0;
  rep(i,in.size()){
    int d=in[j]-'0';
    j++;
    char g=in[j];
    if(d==0){
      if(g=='T')cout<<"wa";
      else if(g=='U')cout<<"nn";
      else if(g=='D')cout<<"wo";
    }else if(d==1)cout<<t[g];
    else cout<<tmp[d]<<t[g];
    j++;
    if(j==in.size())break;
  }
  cout<<endl;
}