#include<bits/stdc++.h>
using namespace std;
int main(){int A,B,C,D;cin>>A>>B>>C>>D;cout<<max(min(min(B-A,D-A),min(B-C,D-C)),0)<<endl;}