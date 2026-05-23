#include <bits/stdc++.h>
using namespace std;

int main(){
	cout << fixed << setprecision(7);
	while(true){
		int n, s;
		int sqSUM = 0;
		int SUM = 0;
		
		cin >> n;
		
		if(n==0) break;
		
		for(int i=0; i<n; i++){
			cin >> s;
			
			SUM   += s;
			sqSUM += s * s;
		}
		cout << sqrt((double)(sqSUM * n - SUM * SUM)) / n << "\n";
	}
	cout << flush;
	return 0;
}
