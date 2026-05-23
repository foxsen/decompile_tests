#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef pair<int,int> P;
P p[3000];
int n;
int ans;
int main(){
  while(cin>>n&&n){
    ans=0;
    for(int i=0;i<n;i++)
      scanf("%d %d",&p[i].first,&p[i].second);
    sort(p,p+n);
    for(int i=0;i+1<n;i++){
      for(int j=i+1;j<n;j++){
	P a=p[i],b=p[j],c,d;
	c.first = a.first + a.second - b.second;
	c.second = a.second + b.first - a.first;
	d.first = b.first + a.second - b.second;
	d.second = b.second + b.first - a.first;
	if(binary_search(p,p+n,c) == false)continue;
	if(binary_search(p,p+n,d) == false)continue;
	int d1 = (a.first-b.first);
	int d2 = (a.second-b.second);
	int d3 = d1*d1 + d2*d2;
	ans=max(ans,d3);
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}