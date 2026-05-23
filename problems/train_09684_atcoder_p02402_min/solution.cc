#include<iostream>
#define MAX 1000000;
using namespace std;
int main()
{
int t;
long min=MAX;
long max=-MAX;
long sum=0;
int n;
cin>>n;
for(int i=0;i<n;i++){
std::cin>>t;
if(min > t) min = t;
if(max < t) max = t;
sum = sum + t;

}
cout<<min<<" "<<max<<" "<<sum<<endl;
return 0;
}