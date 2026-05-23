#include <iostream>
#include <vector>
using namespace std;
using ll=long long;

int main() {
  string S; cin>>S;
  int N=S.size();
  vector<int> A(N+1);
  for(int i=0; i<N; i++){
    if(S.at(i)=='<') A.at(i+1)=A.at(i)+1;
  }
  for (int i=N-1; i>=0; i--){
    if(S.at(i)=='>' && A.at(i)<=A.at(i+1)) A.at(i)=A.at(i+1)+1;
  }
  ll answer=0;
  for(int i=0; i<=N; i++) answer+=A.at(i);
  cout<<answer<<endl;
}
