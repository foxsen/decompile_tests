#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector <long long> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int length;
    length=unique(a.begin(),a.end())-a.begin();
    int j;
    for(j=0;j<length-1;j++)
    {
        cout<<a[j]<<" ";
    }
    cout<<a[j]<<endl;
    return 0;
}

