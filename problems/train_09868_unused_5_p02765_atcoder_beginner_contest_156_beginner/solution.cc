#include <iostream>
using namespace std;

int main() {
    int n,r;
    cin>>n>>r;
    cout<<r+max(10-n,0)*100;
}
