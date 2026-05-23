#include<iostream>
#include<queue>
#include<map>
#include<cstring>
using namespace std;

typedef pair<int,int> P;
typedef pair<int,P> PP;

int bfs();
int n;
int bill[2][222];
bool flag[2][222];

int main(){
  while(1){
    memset(bill,0,sizeof(bill));
    cin >> n;
    if(n == 0) break;
    for(int i=0;i<n;i++){
      cin >> bill[0][i];
    }
    for(int i=0;i<n;i++){
      cin >> bill[1][i];
    }
    memset(flag,0,sizeof(flag));
    int ans = bfs();
    if(ans == -1) cout << "NA" << endl;
    else cout << ans << endl;
  }
}

int bfs(){
  queue<PP> que;
  que.push(PP(0,P(0,0)));
  que.push(PP(0,P(1,0)));
  while(!que.empty()){
    PP a = que.front();
    que.pop();
    int cou = a.first;
    int b = a.second.first;
    int k = a.second.second;
    if(bill[b][k] == 1){
      while(bill[b][k+1] == 1) k++;
    }
    else if(bill[b][k] == 2){
      while(bill[b][k] == 2) k--;
    }
    if(k == n-1) return cou;
    int v = 0;
    if(b == 0) v = 1;
    if(flag[v][k] == false){
      flag[v][k] = true;
      for(int i=0;i<3;i++){
	if(k+i < n){ 
	  que.push(PP(cou+1,P(v,k+i)));
	}
      }
    }
  }
  return -1;
}