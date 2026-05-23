#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	pair<int,int> a[200000];
	rep(i,n) scanf("%d%d",&a[i].second,&a[i].first);

	sort(a,a+n);

	int t=0;
	rep(i,n){
		t+=a[i].second;
		if(a[i].first<t){
			puts("No");
			return 0;
		}
	}
	puts("Yes");

	return 0;
}
