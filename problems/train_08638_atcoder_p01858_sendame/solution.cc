#include<bits/stdc++.h>
using namespace std;

int main(){
  int K;
  cin >> K;
  int atk[2];
  atk[0]=atk[1]=0;
  vector<string>cmd[2];
  cmd[0].resize(K),cmd[1].resize(K);
  for(int i=0;i<2;i++){
    for(int j=0;j<K;j++){
      cin >> cmd[i][j];
    }
  }

  int winner=-1,lst=-1;

  for(int tc=0;tc<K;tc++){

    for(int i=0;i<2;i++){
      if(cmd[i][tc]=="tameru")atk[i]=min(atk[i]+1,5);
      else if(cmd[i][tc]=="kougekida"){
        if(atk[i]==0 && cmd[1-i][tc]!="kougekida"){winner=1-i;goto end;}
        if(atk[i]==5 || cmd[1-i][tc]=="tameru"){
          lst=1;
          winner=i;
          goto end;
        }
        if(cmd[i][tc]=="kougekida" && cmd[1-i][tc]=="kougekida"){
          lst=3;
          if(atk[0]==0 && atk[1]==0)break;
          if(atk[0]==atk[1]){
            atk[0]=atk[1]=0;
            break;
          }
          winner=atk[0]<atk[1]?1:0;
          goto end;
        }
        atk[i]=0;
      }
    }

  }

  end:;

  if(winner==0)cout << "Isono-kun" << endl;
  else if(winner==1)cout << "Nakajima-kun" << endl;
  else cout << "Hikiwake-kun" << endl;
  return 0;
}