#include<bits/stdc++.h>
int main()
{
  int n;
  scanf("%d",&n);
  long long sum=0;
  for(int i=1;i<=n;i++)
  {
    if(i%3&&i%5) sum+=i;
  }
      printf("%lld\n",sum);
  return 0;
}