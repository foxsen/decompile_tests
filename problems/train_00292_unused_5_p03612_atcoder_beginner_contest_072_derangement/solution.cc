#include <iostream>
#include <vector>
using namespace std;
int main() {
	int N;
	cin >> N;
	int S = 0;
	int seq = 0;
	int p;
	for(int i = 1; i <= N; i++) {
		cin >> p;
		if(i != p) {
			S += seq / 2 + seq % 2;
			seq = 0;
		}
		if(i == p) seq++;
	}
	S += seq / 2 + seq % 2;
	cout << S << endl;
	return 0;
}