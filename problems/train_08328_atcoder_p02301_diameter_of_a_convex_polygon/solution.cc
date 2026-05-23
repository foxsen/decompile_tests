#include<bits/stdc++.h>
#define lb long double
#define N 100010 
using namespace std;
struct Po{lb x,y;}a[N];
int n;
lb ansn;
Po operator -(Po x,Po y){return (Po){x.x-y.x,x.y-y.y};}
lb operator *(Po x,Po y){return x.x*y.y-x.y*y.x;}
void get(Po &x){scanf("%Lf %Lf",&x.x,&x.y);}
int pa(int x){if (x>n)x-=n;return x;}
lb le(Po x){return sqrtl(x.x*x.x+x.y*x.y);}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) get(a[i]);
	for (int i=1,j=2;i<=n;i++){
		while((a[pa(i+1)]-a[i])*(a[j]-a[i])<=(a[pa(i+1)]-a[i])*(a[pa(j+1)]-a[i]))j=pa(j+1);
		ansn=max(ansn,max(le(a[j]-a[i]),le(a[j]-a[pa(i+1)])));
	}
	printf("%.10Lf\n",ansn);
	return 0;
} 
