#include <iostream>
using namespace std;
int main() {
	int n; cin >> n;
	int curr;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		if (i == 0) curr = x - 1;
		else{
			if (x > curr) curr = x - 1;
			else if (x == curr);
			else {
				cout << "No"; return 0;
			}
		}
	}
	cout << "Yes";
}