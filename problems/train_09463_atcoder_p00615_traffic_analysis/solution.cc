#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
  int i, n, m, x, max;
  vector<int> data;

  while(1){
    cin >> n >> m;
    if(n == 0 && m == 0) break;

    for(i=0; i<n+m; ++i){
      cin >> x;
      data.push_back(x);
    }

    sort(data.begin(), data.end());

    for(i=1, max=data[0]; i<data.size(); ++i){
      if(max < data[i] - data[i-1])
	max = data[i] - data[i-1];
    }

    cout << max << endl;
    data.clear();
  }

  return 0;
}