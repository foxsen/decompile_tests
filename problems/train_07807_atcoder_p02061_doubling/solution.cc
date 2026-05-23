#include <stdio.h>

int main(void)
{
  int a;
  int l;
  int max=0;
  long Q[100000]={0};
  long sum[100000]={0};
  long mul[100000]={0};
  int i,j=0;
  
  scanf("%d",&a);
  for(l=0;l<a;l++){
    scanf("%d", &Q[l]);
    if(max<=Q[l])
      max=Q[l];
  }

  for(i=1;i<=max;i++)
    mul[i]=1;
  
  for(i=2;i<=max;i++){
    for(j=2*i;j<=max;j+=i){
      mul[j]*=i;
      if(mul[j]>2*j)
	mul[j]=2*j;
    }
  }
  
  for(i=2;i<=max;i++){
    sum[i]=sum[i-1];
    if(mul[i]>=2*i)
      sum[i]++;
  }
  
  for(l=0;l<a;l++)
    printf("%d\n",sum[Q[l]]);

  return 0;
}
