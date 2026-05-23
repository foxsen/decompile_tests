#include <bits/stdc++.h>
using namespace std;


bool check(string a,string b,int d){
  if(a.size()<b.size())swap(a,b);
  if(a==b) return 1;
  int A = a.size(),B=b.size();
  if(d==0||A-B>d)return 0;


  //erase
  for(int i=0;i<A;i++){
    char ch = a[i];
    a.erase(a.begin()+i);
    if(check(a,b,d-1))return 1;
    a.insert(a.begin()+i,ch);
  }
  
  if(A!=B) return 0;

  
  //swap
  for(int i=0;i<A-1;i++){
    if(a[i]==a[i+1]||a[i+1]!=b[i]||a[i]!=b[i+1])continue;
    swap(a[i],a[i+1]);
    if(check(a,b,d-1))return 1;
    swap(a[i],a[i+1]);
  }

  //change
  int cnt=0;
  for(int i=0;i<A;i++) cnt+=a[i]!=b[i];
  if(cnt<=d)return 1;
  
  return 0;
}

int main(){
  int n,d;
  while(cin>>n,n){
    cin>>d;
    string str[201];
    for(int i=0;i<n;i++)cin>>str[i];
    sort(str,str+n);

    int cnt=0;    
    for(int i=0;i<n;i++)
      for(int j=i+1;j<n;j++)
	if(check(str[i],str[j],d)) cout<<str[i]<<","<<str[j]<<endl,cnt++;
    cout<<cnt<<endl;
  }
  return 0;
}