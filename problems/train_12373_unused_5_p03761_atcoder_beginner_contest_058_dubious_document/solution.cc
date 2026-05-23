#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	map<char, int> Nums;
	string S;
	cin >> S;
	for (char c : S) Nums[c]++;
	for (int i = 1; i < n; i++) {
		map<char, int>StrNums;
		string S;
		cin >> S;
		for (char c : S) StrNums[c]++;
		for (auto& p : Nums) p.second = min(p.second, StrNums[p.first]);
	}
	for (const auto& p : Nums) for (int i = 0; i < p.second; i++) cout << p.first;
	cout << endl;

}
