#include <bits/stdc++.h>
using namespace std;
int main () {
	std::map<string, int> count;
	int r,b;
	cin >> b;
	for (int i = 0; i < b; ++i)
	{
		string tmp;
		cin >> tmp;
		count[tmp]++;
	}
	cin >> r;
	for (int i = 0; i < r; ++i)
	{
		string tmp;
		cin >> tmp;
		count[tmp]--;
	}
	int max = 0;
	    for(auto x : count) {
        max = std::max(max,x.second);
    }
    cout << max << endl;
}