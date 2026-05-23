#include<cstdio>
#include <iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<functional>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<numeric>

#define rep(i,n) for(int i=0; i<int(n); i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

ll d[200010],sum[200010];
map<ll,int>m;

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> d[i];
	}
	sum[0] = 0;
	int  mx = 0;
	for (int i = 1; i <= N; i++) {
		sum[i] = sum[i - 1] + d[i];
		if(m.find(sum[i]) == m.end()){ //not found
		  m[sum[i]] = i;
		}else{
		  int j = m[sum[i]];
		  mx = max(mx,i-j);
		}
		if(sum[i] == 0)
		  mx = max(mx,i);
	}
	cout << mx << endl;
	return 0;
}