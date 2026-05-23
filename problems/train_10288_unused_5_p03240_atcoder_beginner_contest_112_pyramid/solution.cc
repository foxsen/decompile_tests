#include <bits/stdc++.h>
using namespace std;
int main(){
	int N; cin >> N; 
	int X[110], Y[110], H[110];
	int pos = -1;  
	for(int i = 0; i < N; i++){
		cin >> X[i] >> Y[i] >> H[i]; 
		if(H[i]) pos = i; 
	}
	for(int i = 0; i <= 100; i++){
		for(int j = 0; j <= 100; j++){
			int height = H[pos] + abs(i - X[pos]) + abs(j - Y[pos]); 
			bool ok = true; 
			for(int k = 0; k < N; k++){
				if(H[k] != max(0, height - abs(i - X[k]) - abs(j - Y[k]))){
					ok = false; break; 
				}
			}
			if(ok){
				cout << i << " " << j << " " << height << endl; 
				return 0; 
			}
		}
	}
}