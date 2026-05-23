#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B;
  cin >> A >> B;
  int N=0;
  for(int i=A/100;i<=B/100;i++){
    int tmp=i*100+(i%100/10)*10+(i/100);
    if(A<=tmp&&tmp<=B)N++;
  }
  cout<<N<<endl;
}