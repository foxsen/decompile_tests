#include<bits/stdc++.h>
#define int long long
using namespace std;

int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeap(int year){return (year%4 == 0 && (year%100 != 0 || year%400 == 0));}

int n, b[14][7], C[100], num[10]={6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int check(char c, int idx){
  
  int d=c-'0', res=0;
  
  if(b[idx][0]){
    
    if(d==0||d==2||d==3||d==5||d==6||d==7||d==8||d==9) res++;
      
  }
  if(b[idx][1]){

    if(d==0||d==4||d==5||d==6||d==8||d==9) res++;
    
  }
  if(b[idx][2]){
    
    if(d==0||d==1||d==2||d==3||d==4||d==7||d==8||d==9) res++;
    
  }
  if(b[idx][3]){
    
    if(d==2||d==3||d==4||d==5||d==6||d==8||d==9) res++;
    
  }
  if(b[idx][4]){
    
    if(d==0||d==2||d==6||d==8) res++;
    
  }
  if(b[idx][5]){
    
    if(d==0||d==1||d==3||d==4||d==5||d==6||d==7||d==8||d==9) res++;
    
  }
  if(b[idx][6]){
    
    if(d==0||d==2||d==3||d==5||d==6||d==8||d==9) res++;
    
  }

  return res;
}

int cal(int h, int m, int s){
  
  string H=to_string(h);
  string M=to_string(m);
  string S=to_string(s);
  
  if(H.size()==1) H='0'+H;
  if(M.size()==1) M='0'+M;
  if(S.size()==1) S='0'+S;
  
  int res=0;
  
  for(int i=0;i<2;i++) res+=num[H[i]-'0'];
  for(int i=0;i<2;i++) res+=num[M[i]-'0'];
  for(int i=0;i<2;i++) res+=num[S[i]-'0'];
  
  res-=check(H[0], 8);
  res-=check(H[1], 9);
  res-=check(M[0], 10);
  res-=check(M[1], 11);
  res-=check(S[0], 12);
  res-=check(S[1], 13);
  
  return res;
}

int cal2(int y, int m, int d){
  
  string Y=to_string(y);
  string M=to_string(m);
  string D=to_string(d);
  
  while(Y.size()!=4) Y='0'+Y;
  if(M.size()==1) M='0'+M;
  if(D.size()==1) D='0'+D;
  
  int res=0;
  
  for(int i=0;i<4;i++) res+=num[Y[i]-'0'];
  for(int i=0;i<2;i++) res+=num[M[i]-'0'];
  for(int i=0;i<2;i++) res+=num[D[i]-'0'];
  
  res-=check(Y[0], 0);
  res-=check(Y[1], 1);
  res-=check(Y[2], 2);
  res-=check(Y[3], 3);
  res-=check(M[0], 4);
  res-=check(M[1], 5);
  res-=check(D[0], 6);
  res-=check(D[1], 7);
  
  return res;
}

void solve(){
  
  for(int h=0;h<=23;h++)
    
    for(int m=0;m<=59;m++)
      
      for(int s=0;s<=59;s++){
	
	int cnt = cal(h, m, s);
	
	C[cnt]++;
	
      }
  
  int ans = 0;
  
  int y=0, m=1, d=1;
  
  while(y<=9999){
    
    while(m<=12){
      
      while(d<=days[m]+(m==2&&isLeap(y))){
	
	int cnt = cal2(y, m, d);
	
	if(n-cnt>=0) ans+=C[n-cnt];
	
	d++;
      }
      
      d=1;
      
      m++;
    }
    
    m=1;
    
    y++;    
  }
  
  cout<<ans<<endl;
}

signed main(){
  
  cin>>n;
  
  int k;
  cin>>k;
  
  for(int i=0;i<k;i++){
    int p, q;
    cin>>p>>q;
    b[p][q]=1;
  }
  
  solve();
  
  return 0;
}

