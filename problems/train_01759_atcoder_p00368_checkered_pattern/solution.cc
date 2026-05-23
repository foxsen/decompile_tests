#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;

using ld=long double;


int main() {	
	int W,H;cin>>W>>H;
	vector<vector<int>>field(H,vector<int>(W));
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cin>>field[i][j];
		}
	}
	bool ok=true;
	vector<int>v(field[0]);
	int b_num=count(v.begin(),v.end(),1);
	if (b_num == W / 2 || (b_num == W / 2 + 1 && W % 2)) {
		vector<int>rev_v(v);
		for_each(rev_v.begin(), rev_v.end(), [](int &a) {a = !a; });

		int same_num=0;
		int rev_num=0;
		for (int i = 0; i < H; ++i) {
			if(field[i]==v)same_num++;
			else if(field[i]==rev_v)rev_num++;
			else {
				ok=false;
				break;
			}
		}
		if (same_num == H / 2 || (same_num == H / 2 + 1 && H % 2)) {

		}
		else {
			ok=false;
		}
	}
	else {
		ok=false;
	}
	if(ok)cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	return 0;
}