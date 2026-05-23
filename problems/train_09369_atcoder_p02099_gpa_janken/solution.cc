#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef pair<int,int>P;

double a[100000];
int main(){
	int n;scanf("%d",&n);
	vector<double>v;
	rep(i,n){
		scanf("%lf",&a[i]);
		v.push_back(a[i]);
	}
	sort(v.begin(),v.end());
	rep(i,n){
		int low=lower_bound(v.begin(),v.end(),a[i])-v.begin();
		int up=upper_bound(v.begin(),v.end(),a[i])-v.begin();
		printf("%d\n",low*3+(up-low)-1); 
	}	
}