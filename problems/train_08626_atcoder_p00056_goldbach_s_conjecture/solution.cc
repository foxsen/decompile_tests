#include<iostream>
#include<vector>
using namespace std;

vector<bool> pt;

void MakeTable(int n){
  pt.resize(++n);
  pt[0] = pt[1] = false;pt[2] = true;
  
  int i = 2;
  while(++i<n)pt[i] = i&1;
  
  i = 3;
  while(i*i<n){
    for(int j=3*i;j<n;j+=2*i)pt[j]=false;
    do{i+=2;}while(!pt[i]);
  }
}

int main(){
  int n,ans;
  MakeTable(50000);

  while(1){
    cin >> n;
    if(!n)break;

    ans = 0;
    for(int i=0;i<=n/2;i++)
      if(pt[i] && pt[n-i])ans++;
    cout << ans << endl;
  }
}
	