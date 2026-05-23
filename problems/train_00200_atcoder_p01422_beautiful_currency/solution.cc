#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
const double INF = 1e18;
const int lim = 200000;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	
	vector<double> dp(lim+1, 0);
	for(int i=0; i<n; i++){
		vector<double> ndp(lim+1);
		for(int j=0; j<=lim; j++){
			ndp[j] = max(dp[j], fabs(a[i]-j)/a[i]);
		}
		for(int j=1; j<=lim; j++){
			for(int k=j*2; k<=lim; k+=j){
				ndp[k] = min(ndp[k], ndp[j]);
			}
		}
		dp = ndp;
	}
	double ans = INF;
	for(int i=0; i<=lim; i++){
		ans = min(ans, dp[i]);
	}
	cout << fixed << setprecision(10);
	cout << ans << endl;
	return 0;
}
