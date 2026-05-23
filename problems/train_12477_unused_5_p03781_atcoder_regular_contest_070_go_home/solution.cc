#include<iostream>
using namespace std;

int main() {
	int x; cin >> x;
	int now = 0, time = 0;
	for (int i = 1; now < x; i++) {
		now += i, time = i;
	}
	cout << time << endl;
	return 0;
}