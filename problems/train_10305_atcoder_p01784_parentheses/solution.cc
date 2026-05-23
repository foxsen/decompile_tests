#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
typedef pair<int,int> pii;
 
int main(){
  int n;
  string s;
 
  cin >> n;
 
  vector<pii> v1,v2;
  rep(i,n){
    cin >> s;
 
    pii p = pii(0,0);
    rep(j,s.size()){
      if(s[j]=='('){
	p.first++;
      }else{
	if(p.first)p.first--;
	else p.second++;
      }
    }
    if(p.first>p.second)v1.push_back(p);
    else v2.push_back(p);
  }
 
  int num1 = 0;
  rep(i,v1.size()){
    if(num1>=v1[i].second){
      num1 += v1[i].first - v1[i].second;
      v1.erase(v1.begin()+i);
      i=-1;
    }
  }
  if(v1.size()){
    cout << "No" << endl;
    return 0;
  }
 
  int num2 = 0;
  rep(i,v2.size()){
    if(num2>=v2[i].first){
      num2 += v2[i].second - v2[i].first;
      v2.erase(v2.begin()+i);
      i=-1;
    }
  }
  if(v2.size()){
    cout << "No" << endl;
    return 0;
  }
  
  if(num1==num2)cout << "Yes" << endl;
  else cout << "No" << endl;
}