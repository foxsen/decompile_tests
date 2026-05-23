#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

int main(){
	int n;
	while( cin >> n, n ){
		long long emp[4001];
		vector<int> nums;
		bool exist = false;
		memset( emp, 0, sizeof(emp) );
		rep(i,n){
			int num;
			long long val, am;
			cin >> num >> val >> am;
			emp[num] += val*am;
			if( find(nums.begin(), nums.end(), num) == nums.end() ){
				nums.push_back(num);
			}
		}
		rep(i,nums.size()){
			if( emp[nums[i]] >= 1000000 ){
				exist = true;
				cout << nums[i] << endl;
			}
		}
		if(!exist){
			cout << "NA" << endl;
		}

	}
	return 0;
}