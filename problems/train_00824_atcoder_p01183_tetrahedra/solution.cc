#include<cmath>
#include<cstdio>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

// 三角形が作れるかどうか
bool tri(int a,int b,int c){
	int p[]={a,b,c};
	sort(p,p+3);
	return p[0]+p[1]>p[2];
}

double volume(double U,double V,double W,double u,double v,double w){
	double X=(w-U+v)*(U+v+w);
	double x=(U-v+w)*(v-w+U);
	double Y=(u-V+w)*(V+w+u);
	double y=(V-w+u)*(w-u+V);
	double Z=(v-W+u)*(W+u+v);
	double z=(W-u+v)*(u-v+W);
	double a=sqrt(x*Y*Z);
	double b=sqrt(y*Z*X);
	double c=sqrt(z*X*Y);
	double d=sqrt(x*y*z);
	return sqrt((-a+b+c+d)*(a-b+c+d)*(a+b-c+d)*(a+b+c-d))/(192*u*v*w);
}

int main(){
	for(int n;scanf("%d",&n),n;){
		int L[15];
		rep(i,n) scanf("%d",L+i);

		double ans=0;
		int p[15]={1,1,1,1,1,1};
		do{
			int m=0,q[6];
			rep(i,n) if(p[i]==1) q[m++]=i;
			do{
				int a=L[q[0]];
				int b=L[q[1]];
				int c=L[q[2]];
				int d=L[q[3]];
				int e=L[q[4]];
				int f=L[q[5]];
				if(tri(a,b,c) && tri(a,e,f) && tri(b,f,d) && tri(c,d,e)) ans=max(ans,volume(a,b,c,d,e,f));
			}while(next_permutation(q,q+5)); // 一つの辺は固定していい
		}while(prev_permutation(p,p+n));

		printf("%.9f\n",ans);
	}

	return 0;
}