#include<stdio.h>
#include<stdlib.h>
#define array(N,t) (t*)calloc(N,sizeof(t))
signed main(void)
{
  int N,i,j,p;long long K;
  i=scanf("%d %lld",&N,&K);
  int *A=array(N,int),*town=array(N,int);
  for(i=0;i<N;i++)town[i]=-scanf("%d",&A[i]);
  for(i=0,j=0;;i=A[i]-1,j++)if(town[i]<0)town[i]=j;else break;
  for(p=0;K>0;p=A[p]-1,K--)if(i==p){K%=town[i]-j;if(!K)break;}
  free(A),free(town);
  return printf("%d\n",p+1),0;
}