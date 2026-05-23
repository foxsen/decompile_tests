#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  int n, q, b, m, e;
  cin >> n;

  std::vector<int> A;
  int a[n];
  for(int i=0; i<n; i++){
    cin >> a[i];
    A.push_back(a[i]);
  }

  cin >> q;

  for(int i=0; i<q; i++){
    cin >> b >> m >> e;
    std::rotate(A.begin()+b, A.begin()+m, A.begin()+e);
  }

  for(int i=0; i<n; i++){
    cout << A[i];
    if(i!=n-1) cout << " ";
  }
  cout << endl;

  return 0;
}

