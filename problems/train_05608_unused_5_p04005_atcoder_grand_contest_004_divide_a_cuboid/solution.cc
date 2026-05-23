#include<iostream>
#include<algorithm> 
using namespace std;
long long a[3];
int main(){
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    cout<<((a[0]&1&a[1]&1&a[2]&1)?a[0]*a[1]:0)<<endl;
}