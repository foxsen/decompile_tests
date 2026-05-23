#include <bits/stdc++.h>
using namespace std;

int main(){
  int X,A,B;
  cin>>X>>A>>B;
  if(A+X<B) cout<<"dangerous"<<endl;
  else if(B<=A) cout<<"delicious"<<endl;
  else cout<<"safe"<<endl;
}
