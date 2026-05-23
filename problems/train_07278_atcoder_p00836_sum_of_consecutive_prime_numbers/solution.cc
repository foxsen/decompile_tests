#include<cstdio>

int main(){
  int i,j,n,pn=0,p[10000],sum[10000],ans[10001];
  
  for(i=2;i<=10000;i++){
    for(j=2;j*j<=i;j++){
      if(!(i%j))break;
    }
    if(i<j*j)p[pn++] = i;
  }
  
  sum[0] = 0;
  for(i=0;i<pn;i++)sum[i+1] = sum[i] + p[i];
  
  for(i=0;i<=10000;i++)ans[i] = 0;
  
  for(i=0;i<=pn;i++)
    for(j=i+1;j<=pn;j++)
      if(sum[j]-sum[i]<=10000)ans[sum[j]-sum[i]]++;

  while(scanf("%d",&n),n)printf("%d\n",ans[n]);
}