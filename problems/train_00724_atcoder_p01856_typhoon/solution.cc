#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

int D[523][523];
int g[523][523];
int cnt,fx,fy;

void find(int y,int x){
  if(D[y][x]){
    fy=y+1;
    fx=x+1;
    cnt++;
    int p=D[y][x];
    g[fy][fx]=p;
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
	D[y+i][x+j]-=p;
      }
    }
  }
}

int main(){
  int H,W;
  cin>>H>>W;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>D[i][j];
    }
  }
  for(int i=0;i<W;i++){
    int y=0,x=i;
    for(;x>=0;y++,x--){
      find(y,x);
    }
  }
  for(int i=1;i<H;i++){
    int y=i,x=W-1;
    for(;y<H;y++,x--){
      find(y,x);
    }
  }
  vector<pair<int,int> > ans;
  if(cnt==1){
    ans.emplace_back(fy,fx);
  }else{
    for(int i=0;i<H;i++){
      for(int j=0;j<W;j++){
	if(g[i][j]){
	  int d=g[i][j]-1;
	  for(int k=-1;k<=1;k++){
	    int ny=i+k;
	    if(ny<0||H<=ny)continue;
	    for(int l=-1;l<=1;l++){
	      int nx=j+l;
	      if(nx<0||W<=nx||k==0&&l==0)continue;
	      d+=g[ny][nx];
	    }
	  }
	  if(d%2){
	    ans.emplace_back(i,j);
	  }
	}
      }
    }
  }
  cout<<ans.back().first<<' '<<ans.back().second<<' '<<ans[0].first<<' '<<ans[0].second<<endl;
}