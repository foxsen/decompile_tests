#include<bits/stdc++.h>
using namespace std;
int n,x,l[105];
int main()
{
  scanf("%d%d",&n,&x);
  for(int i=1;i<=n;++i)
  {scanf("%d",&l[i]);
  l[i]+=l[i-1];
  }
  printf("%d\n",upper_bound(l+1,l+n+1,x)-l);
return 0;
}