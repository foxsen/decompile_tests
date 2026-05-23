#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i + 1 < n; ++i){
		for(int j = 0; j + i + 1< n; ++j){
			cout << __builtin_ctz(~j) + 1 << " ";
		}
		cout << endl;
	}
	return 0;
}

