#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const double PI=acos(-1);

double SIN[200000];

double area(int i,int j){if(j-i<0) printf("!! i = %d, j = %d\n",i,j); return 2*SIN[i]*SIN[j]*SIN[j-i]; }

int main(){
	int n;
	lint k; scanf("%d%lld",&n,&k);

	rep(i,n) SIN[i]=sin(PI*i/n);

	double lo=0,hi=1.3;
	rep(_,35){
		double mi=(lo+hi)/2;

		lint cnt=0;
		for(int i=1;i<n-1;i++){
			int lo2=i,hi2=(n+i)/2+1;
			while(hi2-lo2>1){
				int mi2=(lo2+hi2)/2;
				if(area(i,mi2)<mi) lo2=mi2;
				else               hi2=mi2;
			}

			int l=lo2;
			int r=n-(l-i);
			cnt+=(l-i)+(n-r)-(l==r?1:0);
		}
		cnt=cnt*n/3;

		if(cnt<k) lo=mi;
		else      hi=mi;
	}
	printf("%.15f\n",lo);

	return 0;
}
