#include <bits/stdc++.h>
using namespace std;

int main() {
  int K;
  cin>>K;
  int64_t Z=0;
  map<string,vector<int64_t>> m;
  vector<int64_t> em(26);
  m["#"]=em;
  vector<pair<int,string>> p(K);
  for(int i=0;i<K;i++){
    string S;
    cin>>S;
    int N=S.size();
    p[i]=make_pair(N,S);
  }
  sort(p.begin(),p.end());
  for(int i=0;i<K;i++){
    int N;
    string S;
    tie(N,S)=p[i];
    if(N==1){
      char a=S[0];
      m["#"][a-'a']++;
    }
    else{
      reverse(S.begin(),S.end());
      string T="";
      vector<int> q(26);
      for(int j=0;j<N;j++){
        int b=S[j]-'a';
        q[b]++;
      }
      if(m.count("#")){
        vector<int64_t> vec=m["#"];
        for(int l=0;l<26;l++){
          if(q[l]!=0){
            Z+=vec[l];
          }
        }
      }
      for(int j=0;j<N-2;j++){
        T+=S[j];
        q[S[j]-'a']--;
        if(m.count(T)){
          vector<int64_t> vec=m[T];
        for(int l=0;l<26;l++){
          if(q[l]!=0){
            Z+=vec[l];
          }
        }
        }
      }
      T+=S[N-2];
      if(!m.count(T)){
        m[T]=em;
      }
      m[T][S[N-1]-'a']++;
    }
  }
  cout<<Z<<endl; 
}