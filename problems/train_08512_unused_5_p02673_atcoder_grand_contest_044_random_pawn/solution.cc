#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[400001];
ll b[400001];
ll pb[400001];
ll ppb[400001];
ll s1(int l,int r){
	//cout << "s1 " << (ppb[r]-ppb[l])-l*(pb[r]-pb[l]) << ' ' << l << ' ' << r << endl;
	return (ppb[r]-ppb[l])-l*(pb[r]-pb[l]);
}
ll s2(int l,int r){
	return (r+1)*(pb[r]-pb[l])-(ppb[r]-ppb[l]);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	int g=1;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		if(a[i]>a[g]) g=i;
	}
	for(int i=1; i<=n ;i++){
		cin >> b[i];
		b[i]*=2;
	}
	for(int i=1; i<=n ;i++){
		a[n+i]=a[i];
		b[n+i]=b[i];
	}
	for(int i=1; i<=2*n ;i++){
		pb[i]=pb[i-1]+b[i];
		ppb[i]=ppb[i-1]+i*b[i];
	}
	vector<int>v;
	for(int i=g; i<=n+g ;i++){
		while(v.size()>=2){
			int x=v[v.size()-2];
			int y=v.back();
			int z=i;
			ll w1=(z-y)*(a[x]-s1(x,y))+(y-x)*(a[z]-s2(y,z-1));
			ll w2=(z-x)*a[y];
			//cout << x << ' ' << y << ' ' << z << ' ' << w1 << ' ' << w2 << endl;
			if(w1>w2) v.pop_back();
			else break;
		}
		v.push_back(i);
	}
	int ptr=0;
	double tot=0;
	for(int i=g; i<n+g ;i++){
		if(v[ptr+1]==i){
			ptr++;
			tot+=a[i];
		}
		else{
			int x=v[ptr];
			int z=v[ptr+1];
			int y=i;
			ll w1=(z-y)*(a[x]-s1(x,y))+(y-x)*(a[z]-s2(y,z-1));
			//cout << s1(x,y) << endl;
			//cout << x << ' ' << y << ' ' << z << ' ' << w1 << endl;
			tot+=1.0*w1/(z-x);
			//cout << i << ' ' << 1.0*w1/(z-x) << endl;
		}
	}
	tot/=n;
	cout << fixed << setprecision(10) << ' ' << tot << '\n';
}