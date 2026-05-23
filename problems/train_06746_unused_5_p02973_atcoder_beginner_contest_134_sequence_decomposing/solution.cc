#include <cstdio>
#include <deque>
#include <iostream>
using namespace std;

int n;

signed main(void)
{
    cin >> n;
    int a;
    deque <int> b;
   for(int i=0; i<n; ++i)
    {
        cin >> a;
        int it= lower_bound(b.begin(),b.end(),a)-b.begin();
        if(!it) b.push_front(a);
        else b[it-1]=a;
    }
    cout << b.size() << "\n";
 
	return 0;
}