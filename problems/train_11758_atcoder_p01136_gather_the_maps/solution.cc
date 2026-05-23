#include<cstdio>
#include<iostream>
#include<vector>


using namespace std;
vector<int>ans;


int main(){
	int count = 0;
	while (1){
		int n;
		cin >> n;
		int half = n / 2;
		if (n == 0)break;
		count++;
		const int low_ans = (1 << half) - 1,up_ans=(1<<(n-half))-1;
		vector<unsigned long long int>sk;
		vector<unsigned long long int>upper;
		vector<unsigned long long int>lower;
		for (int i = 0; i < n; i++){
			sk.push_back(0);
			int m;
			cin >> m;
			for (int j = 0; j < m; j++){
				int temp;
				cin >> temp;
				sk[i] |= (1 << temp);
			}
			if (i < half)
				lower.push_back(1 << i),upper.push_back(0);
			else lower.push_back(0), upper.push_back(1 << (i - half));
		}


		int i;
		for (i = 1; i <= 30; i++){
			unsigned long long int check = 1 << i;
			unsigned long long int low = 0,up=0;
			for (int j = 0; j < n; j++)
			if (check&sk[j])
				low |= lower[j],up|=upper[j];
			for (int j = 0; j < n; j++)
			if (check&sk[j])
				lower[j]=low,upper[j]=up;
			if (low==low_ans&&up==up_ans)break;
		}
		if (i == 31)
			i = -1;
		ans.push_back(i);

	}
	for (int i = 0; i < count; i++)
		cout << ans[i] << endl;


	return(0);
}