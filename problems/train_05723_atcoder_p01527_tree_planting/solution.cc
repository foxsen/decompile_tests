#include<iostream>
#include<cstdio>
 
using namespace std;
 
 
int main(){
  int h,w,imap[1010][1010],H[1010],W[1010];
  for(int i=0;i<1010;i++)H[i] = W[i] = 0;
  cin >> h >> w;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin >> imap[i][j];
      if(imap[i][j] == 0)H[i]++,W[j]++;
    }
  }
 
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      (H[i]+W[j]-1+imap[i][j])%2==0?cout << 0:cout << 1;
      if(j != w-1)cout << ' ';
    }
    cout << endl;
  }
  return 0;
}