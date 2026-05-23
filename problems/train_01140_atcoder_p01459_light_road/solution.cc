#include<iostream>
#include<string.h>
#include<queue>
#define inf 1000000001
using namespace std;

int X[4]={0,1,0,-1};
int Y[4]={-1,0,1,0};
int H,W,A,si,sj;
char map[100][100];

bool in(int y,int x){
  if(y<0 || x<0 || y>=H || x>=W)return false;
  return true;
}
    
class State{
public:
  int y,x,muki,numL,numR;
  State(int y,int x,int muki,int l,int r):y(y),x(x),muki(muki),numL(l),numR(r){}
};

int main()
{
  int memo[100][100][4];
  for(int i=0;i<100;i++){
    for(int j=0;j<100;j++){
      for(int k=0;k<4;k++)memo[i][j][k]=inf;
    }
  }
  queue<State> Q;
  cin>>H>>W>>A;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>map[i][j];
      if(map[i][j]=='S'){
	si=i;
	sj=j;
	map[i][j]='.';
      }
    }
  }
  Q.push(State(si,sj,2,0,0));
  memo[si][sj][0]=0;
  memo[si][sj][2]=0;
  int ans=inf;
  int a,b;
  while(!Q.empty()){
    State u=Q.front();
    //cout<<u.y<<" "<<u.x<<" "<<u.muki<<" "<<u.numL<<" "<<u.numR<<endl;
    Q.pop();
    if(u.numL>A || u.numR>A)continue;
    if(map[u.y][u.x]=='G'){
      ans=min(memo[u.y][u.x][u.muki],ans);
      continue;
    }
    a=u.y+Y[u.muki];
    b=u.x+X[u.muki];
    if(in(a,b)){
      if(map[a][b]!='#'){
	if(memo[a][b][u.muki]>=u.numL+u.numR){
	  memo[a][b][u.muki]=u.numL+u.numR;
	  Q.push(State(a,b,u.muki,u.numL,u.numR));
	}
      }
    }
    if(u.y==si && u.x==sj){}
    else {
      a=u.y+Y[(u.muki+1)%4];
      b=u.x+X[(u.muki+1)%4];
      if(in(a,b)){
	if(map[a][b]!='#'){
	  if(memo[a][b][(u.muki+1)%4]>=u.numL+u.numR+1){
	    memo[a][b][(u.muki+1)%4]=u.numR+u.numL+1;
	    if(memo[a][b][(u.muki+1)%4]<ans){
	      if(((u.muki+1)%4)%2==0){
		if(u.numL<A)Q.push(State(a,b,(u.muki+1)%4,u.numL+1,u.numR));
	      }
	      if(((u.muki+1)%4)%2==1){
		if(u.numR<A)Q.push(State(a,b,(u.muki+1)%4,u.numL,u.numR+1));
	      }
	    }
	  }
	}
      }
      a=u.y+Y[(u.muki+3)%4];
      b=u.x+X[(u.muki+3)%4];
      if(in(a,b)){
	if(map[a][b]!='#'){
	  if(memo[a][b][(u.muki+3)%4]>=u.numR+u.numL+1){
	    memo[a][b][(u.muki+3)%4]=u.numR+u.numL+1;
	    if(memo[a][b][(u.muki+3)%4]<ans){
	      if(((u.muki+3)%4)%2==0){
		if(u.numR<A)Q.push(State(a,b,(u.muki+3)%4,u.numL,u.numR+1));
	      }
	      if(((u.muki+3)%4)%2==1){
		if(u.numL<A)Q.push(State(a,b,(u.muki+3)%4,u.numL+1,u.numR));
	      }
	    }
	  }
	}
      }
    }
  }
  if(ans==inf)cout<<-1<<endl;
  else cout<<ans<<endl;
  return 0;
}