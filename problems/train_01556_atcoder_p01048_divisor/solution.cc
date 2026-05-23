#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int answer = 0;
	for(int i = 1; answer == 0; ++i){
		int c = 0;
		for(int j = 1; j * j <= i; ++j){
			if(i % j == 0){
				++c;
				if(j * j != i){ ++c; }
			}
		}
		if(c == n){ answer = i; }
	}
	cout << answer << endl;
	return 0;
}