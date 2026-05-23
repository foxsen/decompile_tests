#include<bits/stdc++.h>
#define int long long
using namespace std;

int a[1000000];
int cnt[1000000];

signed main (){

int t;

cin >> t;

while(t--){
	int n;
	cin >> n;
	for (int i=1;i<=n;i++){
		cnt[i] = 0;
	}
	for (int i=1;i<=n;i++){
		cin >> a[i];
		cnt[a[i]]++;
	}
	int res = 0;
	for (int i=1;i<=n;i++){
		int k = cnt[i]+cnt[i-1]+cnt[i-2];
		int kk = cnt[i-1]+cnt[i-2];;
		res+=k*(k-1)*(k-2)/6-(kk*(kk-1)*(kk-2)/6);
	}
	cout << res << endl;
}
	
return 0;	
}