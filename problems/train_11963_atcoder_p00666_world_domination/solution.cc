#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n;
  int id[100];
  double p[100],w[100];
  bool use[100];
  long long int pascal[101][101];

  for(int i=0;i<=100;i++){
    pascal[i][0] = 1;
    pascal[0][i] = 1;
  }

  for(int i=1;i<=100;i++){
    for(int j=1;j<=100;j++)pascal[i][j] = (pascal[i-1][j] + pascal[i][j-1]) % 100000007;
  }
  
  for(;;){
    scanf("%d",&n);
    if(!n)break;

    for(int i=0;i<n;i++){
      scanf("%lf %d %lf",&p[i],&id[i],&w[i]);
      use[i] = false;
    }

    double ans = 0.0;
    int rem = n;
    long long int pattern = 1;
    for(int i=0;i<n;i++){
      if(!use[i]){
	use[i] = true;
	int tmp = i;
	vector<int> loop;

	loop.push_back(tmp);
	for(;;){
	  tmp = id[tmp];
	  if(tmp==i)break;
	  use[tmp] = true;
	  loop.push_back(tmp);
	}

	int num = 1;
	double m = 1.0/p[loop[0]] - 1.0/w[loop[0]];
	ans += 1.0/w[loop[0]];
	for(int j=1;j<(int)loop.size();j++){
	  ans += 1.0/w[loop[j]];
	  if(abs(m-1.0/p[loop[j]] + 1.0/w[loop[j]])<1e-10){
	    num++;
	  }else if(m > 1.0/p[loop[j]] - 1.0/w[loop[j]]){
	    m = 1.0/p[loop[j]] - 1.0/w[loop[j]];
	    num = 1;
	  }
	}
	ans += m;
	pattern = (pattern * num) % 100000007;
	//cout << rem << " " << loop.size() << " " << pascal[rem-(int)loop.size()][loop.size()] << endl;
	rem -= loop.size();
	pattern = (pattern * pascal[rem][(int)loop.size()]) % 100000007;
      }
    }
    printf("%.11lf %lld\n",ans,pattern);
  }
}