#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, x;
	set<int> him;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> x;
		him.insert(x);
	}
	cout << (int) him.size() << "\n";
}