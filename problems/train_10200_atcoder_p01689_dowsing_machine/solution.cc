#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
string t[50];
bool vd[50][50];
bool flg[50][50];
int r[12];
int h,w,d,n;
int x,y,size;
int cntA,cntB;
int Dy,Dx;
void init();
void delete_flg();
void count_flg();
void dfs(int y,int x);
void print(){
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cout<<(int)flg[i][j];
    }
    cout<<endl;
  }
  cout<<endl;
}
int main(){
  cin>>h>>w>>d>>n;
  for(int i=0;i<h;i++)cin>>t[i];
  for(int i=1;i<=d;i++)cin>>r[i];
  init();
  for(int i=0;i<n;i++){
    cin>>x>>y>>size;
    delete_flg();
    //print();
  }
  count_flg();
  dfs(Dy,Dx);
  if(cntB==0)cout<<"Broken"<<endl;
  else if(cntA==0)cout<<"No"<<endl;
  else if(cntA==cntB)cout<<"Yes"<<endl;
  else cout<<"Unknown"<<endl;
  
  return 0;
}

void init(){
  r[0]=-1;
  r[d+1]=10000;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      flg[i][j]=(t[i][j]!='#');
      vd[i][j]=(t[i][j]=='#');
      if(t[i][j]=='D'){
	Dx=j;
	Dy=i;
      }
    }
  }
  cntA=cntB=0;
}

void delete_flg(){
  int nr;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      nr=max(abs(i-y),abs(j-x));
      if(r[size]<nr&&nr<=r[size+1]){}
      else flg[i][j]=false;
    }
  }
}

void count_flg(){
  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
      if(flg[i][j])cntB++;
}
void dfs(int y,int x){
  vd[y][x]=true;
  if(flg[y][x])cntA++;
  if(y>0&&!vd[y-1][x])dfs(y-1,x);
  if(x>0&&!vd[y][x-1])dfs(y,x-1);
  if(y+1<h&&!vd[y+1][x])dfs(y+1,x);
  if(x+1<w&&!vd[y][x+1])dfs(y,x+1);
}