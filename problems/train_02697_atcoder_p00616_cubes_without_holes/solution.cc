#include<iostream>
#include<string>
#include<set>
using namespace std;

int main(){
	int n,h;
	while(true){
		cin >> n >> h;
		set<int> deletecube;
		if(n == 0 && h == 0){
			break;
		}

		for(int i=0;i<h;i++){
			string m;
			int a,b;
			cin >> m >> a >> b;
			a--;
			b--;
			if(m == "xy"){
				for(int j=0;j<n;j++){
					deletecube.insert(a + n*b + n*n*j);
				}
			}
			if(m == "xz"){
				for(int j=0;j<n;j++){
					deletecube.insert(a + n*j + n*n*b);
				}
			}
			if(m == "yz"){
				for(int j=0;j<n;j++){
					deletecube.insert(j + n*a + n*n*b);
				}
			}
		}
		int ans = n*n*n - deletecube.size();
		cout << ans << endl;
	}
}