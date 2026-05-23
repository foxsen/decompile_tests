#include <iostream>

using namespace std;

int main(){
	int n, m;
	int p[20];
	while(cin >> n >> m, n){
		bool ok = true;
		for(int i=0;i<m;i++){
			cin >> p[i];
			if(p[i]==1) ok = false;
		}
		printf("%.6lf\n", ok ? 0.5*n : 0);
	}
	return 0;
}