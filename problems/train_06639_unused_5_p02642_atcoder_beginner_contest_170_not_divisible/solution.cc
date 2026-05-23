#include <iostream>
#include <algorithm>
using namespace std;
 
int b[1000001];
int ans;
int main () {
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++) {
		cin >> a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++) {
		if(b[a[i]]==0) {
			if (a[i]!=a[i-1]&&a[i]!=a[i+1]) {
				ans++;
			}
			for(int j=a[i];j<1000001;j+=a[i]) {
				b[j]=1;
			}
		}
	}
	cout << ans;
}