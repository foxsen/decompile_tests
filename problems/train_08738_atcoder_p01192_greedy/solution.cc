#include<bits/stdc++.h>
using namespace std;
int n;
int c[100];
 
int greedy(int x){
  int res=0;
  for(int i=n-1;i>=0;i--){
    res+=x/c[i];
    x%=c[i];
  }
  return res;
}
 
int dp[5000];
 
void solve(){
  if(c[0]!=1){
    printf("Cannot pay some amount");
    return;
  }
 
  fill( dp, dp+5000, 1e9);
  dp[0]=0;
   
  for(int i=0;i<n;i++){
    int val=c[i];
    for(int j=0;j<2000;j++){
      if(j-val>=0)dp[j]=min(dp[j],dp[j-val]+1);
    }
  }
   
  for(int num=0;num<2000;num++){
    int cost=greedy(num);
    if(cost!=dp[num]){
      //      cout<<num<<' '<<cost<<' '<<dp[num]<<endl;
      printf("Cannot use greedy algorithm");
      return;
    }
  }
 
  for(int j=2000;j<5000;j++){
 
    for(int i=0;i<n;i++){
      int val=c[i];      
      dp[j]=min(dp[j],dp[j-val]+1);
    }
     
    if( dp[j]!=dp[j- c[n-1] ]+1 ){
      printf("Cannot use greedy algorithm");
      return;
    }
  }
  printf("OK");
}
 
int main(){
  for(int tc=1;;tc++){
    scanf("%d",&n);
    if(n==0)break;
    for(int i=0;i<n;i++)scanf("%d",&c[i]);
    printf("Case #%d: ",tc);
    solve();
    printf("\n");
  }
  return 0;
}


/*
#include<bits/stdc++.h>
using namespace std;

struct state{
  int qy,qx,ay,ax,f;
};

int W,H;
int syA,sxA;
int syQ,sxQ;

char t[30][30];
int d[30][30][30][30][2];// 0-> qturn 1->aturn
int C[30][30][30][30][2];// 0-> qturn 1->aturn
int dy[]={-1,0,1,0,0};
int dx[]={0,1,0,-1,0};

bool inField(int y,int x){
  return (0<=y&&y<H&&0<=x&&x<W&&t[y][x]!='#');
}

queue< state > que;

void init(){
  while( !que.empty() ) que.pop();
  
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(t[i][j]=='#')continue;
      
      for(int k=0;k<H;k++){
        for(int l=0;l<W;l++){
          if(t[k][l]=='#')continue;
          
          int cc;

          cc=5;
          for(int dir=0;dir<4;dir++){
            int ny=k+dy[dir];
            int nx=l+dx[dir];
            if(!inField(ny,nx))cc--;
          }
          C[i][j][k][l][0]=cc;
          d[i][j][k][l][0]=0;

          cc=5;
          for(int dir=0;dir<4;dir++){
            int ny=i+dy[dir];
            int nx=j+dx[dir];
            if(!inField(ny,nx))cc--;
          }
          
          C[i][j][k][l][1]=cc;
          d[i][j][k][l][1]=0;
        }
      }
    }
  }


        
  for(int i=0;i<H;i++)
    for(int j=0;j<W;j++)
      if(t[i][j]!='#')
      for(int k=0;k<H;k++)
        for(int l=0;l<W;l++)
          if(t[k][l]!='#')
            for(int f=0;f<2;f++)
              if(i==k&&j==l&&f==0)
                que.push( (state){i,j,k,l,f} ), d[i][j][k][l][f]=-1;
              else if(t[i][j]=='E'&&f==0)
                que.push( (state){i,j,k,l,f} ), d[i][j][k][l][f]=1;

}

string winstr="Queen can escape.";
string losestr="Army can catch Queen.";
string drawstr="Queen can not escape and Army can not catch Queen.";

string solve(){
  while(!que.empty()){
    state s=que.front();que.pop();
    C[s.qy][s.qx][s.ay][s.ax][s.f]=0;

    int &judge=d[s.qy][s.qx][s.ay][s.ax][s.f];
    if(s.f==0){
      
      int flg=-1;
      for(int dir=0;dir<5;dir++){
        int nqy=s.qy+dy[dir];
        int nqx=s.qx+dx[dir];
        if(inField(nqy,nqx))
          if(d[nqy][nqx][s.ay][s.ax][1-s.f]==1)flg=1;
      }
      if(judge==0)judge=flg;
      
      for(int dir=0;dir<5;dir++){
        int nay=s.ay+dy[dir];
        int nax=s.ax+dx[dir];
        if(!inField(nay,nax))continue;
        
        int &cc=C[s.qy][s.qx][nay][nax][1-s.f];
        cc--;
        if(judge==-1&&cc>0)cc=0;
        if(cc==0)que.push( (state){s.qy,s.qx,nay,nax,1-s.f} );
      }
      
      
    }else if(s.f==1){
      int flg=1;
      for(int dir=0;dir<5;dir++){
        int nay=s.ay+dy[dir];
        int nax=s.ax+dx[dir];
        if(inField(nay,nax))
          if(d[s.qy][s.qx][nay][nax][1-s.f]==-1)flg=-1;
      }
      if(judge==0)judge=flg;

      for(int dir=0;dir<5;dir++){
        int nqy=s.qy+dy[dir];
        int nqx=s.qx+dx[dir];
        if(!inField(nqy,nqx))continue;
        int &cc=C[nqy][nqx][s.ay][s.ax][1-s.f];
        cc--;
        if(judge==1&&cc>0)cc=0;
        if(cc==0)que.push( (state){nqy,nqx,s.ay,s.ax,1-s.f} );
      }
    }
    if(1){
      cout<<s.qy<<' '<<s.qx<<' '<<s.ay<<' '<<s.ax<<' '<<s.f<<endl;
      cout<<d[s.qy][s.qx][s.ay][s.ax][s.f]<<endl;
      cout<<"C[0][0][0][1][0] = "<<C[0][0][0][1][0]<<endl;
      cout<<endl;
    }
    if( s.qy == syQ && s.qx == sxQ &&
        s.ay == syA && s.ax == sxA &&
        s.f  == 0 ){
      if( d[s.qy][s.qx][s.ay][s.ax][s.f] == 1 )return winstr;
      else return losestr;
    }
  }
  return drawstr;
}

int main(){
  while(1){
    
    cin>>W>>H;
    if(W==0&&H==0)break;
    
    for(int i=0;i<H;i++){
      for(int j=0;j<W;j++){
        char ch;
        cin>>ch;
        t[i][j]=ch;
        if(ch=='A'){
          syA=i;sxA=j;
        }
        if(ch=='Q'){
          syQ=i;sxQ=j;
        }
      }
    }
    init();
    
    cout<<solve()<<endl;
  }
  return 0;
}

*/