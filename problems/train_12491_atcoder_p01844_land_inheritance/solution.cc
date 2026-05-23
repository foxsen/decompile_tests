#include<bits/stdc++.h>
using namespace std;

int H,W,N;
int a[201][201];
int A[201][201];


int calc(int h,int w,int H,int W){
  return A[H][W]-A[H][w]-A[h][W]+A[h][w];
}


int solve(int h,int w,int H,int W,int N){
  int res=0,total=calc(h,w,H,W);
  if(N==1)return total;
  
  for(int i=h;i<H;i++){
    for(int divi=1;divi<N;divi++){
      int v=solve(h,w,i,W,divi);
      int k=solve(i,w,H,W,N-divi);
      res=max(res, min(v,k) );
    }
  }
  for(int j=w;j<W;j++){
    for(int divi=1;divi<N;divi++){
      int v=solve(h,w,H,j,divi);
      int k=solve(h,j,H,W,N-divi);
      res=max(res, min(v,k) );
    }
  }
  return res;
}

int compute(){
  if(N!=4)return 0;
  int res=0;
  for(int ah=1;ah+1<H;ah++){
    for(int bh=ah+1;bh<H;bh++){
      for(int aw=1;aw+1<W;aw++){
        for(int bw=aw+1;bw<W;bw++){
          int sum0=calc(0,0,ah,bw);
          int sum1=calc(0,bw,bh,W);
          int sum2=calc(bh,aw,H,W);
          int sum3=calc(ah,0,H,aw);
          res=max(res,min(min(sum0,sum1),min(sum2,sum3)));
          
          sum0=calc(0,0,bh,aw);
          sum1=calc(bh,0,H,bw);
          sum2=calc(ah,bw,H,W);
          sum3=calc(0,aw,ah,W);
          res=max(res,min(min(sum0,sum1),min(sum2,sum3)));
        }
      }
    }
  }
  return res;
}

int main(){
  scanf("%d %d %d",&H,&W,&N);
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      scanf("%d",&a[i][j]);
      A[i+1][j+1]=a[i][j]+A[i+1][j]+A[i][j+1]-A[i][j];
    }
  }

  int ans=max(solve(0,0,H,W,N),compute());
  printf("%d\n",ans);
  return 0;
}