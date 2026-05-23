#include <cstdio>

int n,x[50],y[50];

int main(){
  for(int c=1;;c++){
    float a=0;
    scanf("%d",&n); if(!n) break;

    for(int i=0; i<n; i++)
      scanf("%d %d",&x[i],&y[i]);

    for(int i=0; i<n; i++)
      a += 0.5*(x[i]*y[(i+1)%n]-y[i]*x[(i+1)%n]);

    a *= a>0?1:-1;

    printf("%d %.1f\n",c,a);
  }
}