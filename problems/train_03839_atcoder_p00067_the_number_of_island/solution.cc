#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void dfs(vector<string>& m,int i,int j){
  int di[]={1,0,-1,0};
  int dj[]={0,1,0,-1};
  for(int k=0;k<4;++k){
    int ni=i+di[k];
    int nj=j+dj[k];
    if(ni<0||ni>=12||nj<0||nj>=12)continue;
    if(m[ni][nj]=='1'){
      m[ni][nj]='0';
      dfs(m,ni,nj);
    }
  }
}

int main() {
  while(1){
    vector<string> m(12);
    for(int i=0;i<12;++i){
      cin>>m[i];
    }
    if(m[11].size()!=12)break;
    int cnt=0;
    for(int i=0;i<12;++i)
      for(int j=0;j<12;++j)
        if(m[i][j]=='1'){
          cnt++;
          dfs(m,i,j);
        }
    cout<<cnt<<endl;
    string wl;
    //cin>>wl;
  }
  return 0;
}