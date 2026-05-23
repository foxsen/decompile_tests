#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--){
		int N, prev, maxup = 0, maxdown = 0;
		cin >> N >> prev;
		while(--N){
			int height;
			cin >> height;
			if(prev < height){
				maxup = max(maxup, height - prev);
			}else{
				maxdown = max(maxdown, prev - height);
			}
			prev = height;
		}
		cout << maxup << " " << maxdown << endl;
	}
	return 0;
}