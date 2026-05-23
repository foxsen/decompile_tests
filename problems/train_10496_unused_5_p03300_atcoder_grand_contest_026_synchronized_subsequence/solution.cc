#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  static char s[10000];
  scanf("%s",s);
  static int a[3000],b[3000],c[10000];
  int na=0,nb=0;
  for(int i=0;i<2*n;i++){
    if(s[i]=='a'){
      a[na]=i;
      c[i]=na++;
    }
    else{
      b[nb]=i;
      c[i]=nb++;
    }
  }
  vector<int> bg,ed;
  for(int i=0;i<n;){
    if(a[i]>b[i]){
      bg.push_back(i);
      int t=a[i];
      while(b[i]<t){
	t=a[i];
	i++;
      }
      ed.push_back(i);
    }
    else{
      i++;
    }
  }
  string ans;
  for(int t=bg.size()-1;t>=0;t--){
    int x=bg[t],y=ed[t];
    string p="";
    for(int i=x;i<y;i++){
      string q;
      for(int j=0;j<2*n;j++){
	if(c[j]>=i&&c[j]<y){
	  q+=s[j];
	}
      }
      if(p<q){
	p=q;
      }
    }
    if(p+ans>ans){
      ans=p+ans;
    }
  }
  for(int i=n-1;i>=0&&a[i]<b[i];){
    ans+="ab";
    int t=a[i];
    while(i>=0&&b[i]>t)i--;
  }
  printf("%s\n",ans.c_str());
  return 0;
}
