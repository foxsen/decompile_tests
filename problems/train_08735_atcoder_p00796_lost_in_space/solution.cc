#include <iostream>
#include <cmath>

#define calc(x1, x2) ((x1-x2)*(x1-x2))

using namespace std;

int n, m;
double l[3], x[31], y[31], z[31];

bool check(int i, int j, int k)
{
  double t[3];
  t[0] = sqrt(calc(x[j], x[k])+calc(y[j], y[k])+calc(z[j], z[k]));
  t[1] = sqrt(calc(x[k], x[i])+calc(y[k], y[i])+calc(z[k], z[i]));
  t[2] = sqrt(calc(x[i], x[j])+calc(y[i], y[j])+calc(z[i], z[j]));

  for(int i = 0; i < 3; ++i)
    if(fabs(l[i]/l[(i+1)%3] - t[i]/t[(i+1)%3]) >= 0.0001) return false;

  return true;
}

void solve()
{
  for(int i = 0; i < m; ++i)
    for(int j = 0; j < m; ++j)
      if(i != j) 
	for(int k = 0; k < m; ++k)
	  if(i != k && j != k && check(i, j, k)){
	    cout << (i+1) << " " << (j+1) << " " <<  (k+1) << endl;
	    return;
	  }
}

int main()
{
  while(cin>>n && n)
    while(n--){
      for(int i = 0; i < 3; ++i) cin >> l[i];
      cin >> m;
      for(int i = 0; i < m; ++i)
	cin >> x[i] >> y[i] >> z[i];

      solve();
    }

  return 0;
}