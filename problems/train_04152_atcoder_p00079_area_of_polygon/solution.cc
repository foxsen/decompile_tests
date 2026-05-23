#include <cstdio>
#include <cmath>
int main(){
	double xs[21],ys[21];
	double x,y;
	int n=0;
	while(scanf("%lf,%lf",&x,&y)!=EOF){
		 xs[n]=x,ys[n++]=y;
	}
	x=0;
	for(int i=0;i<n;i++)x+=(xs[i]-xs[(i+1)%n])*(ys[i]+ys[(i+1)%n]);
	printf("%.8f\n",fabs(x/2.0));
}