#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string s;
string tt;
int ans;
int ff,fff;

int main(){
  cin >> s;
  while(s!="."){
    ans=0;
    ff=0;
    fff=0;
    int i=0;
    int j=0;
    cin >> tt;
    for(;i<int(s.size())&&j<int(tt.size());){
      if(s[i]==tt[j]&&s[i]!=0x22&&tt[j]!=0x22){
        ++i;
        ++j;
      }
      else{
        if(s[i]!=tt[j]){
          ans=1;
          break;
        }
        if(s[i]==0x22&&tt[j]==0x22){
          ++i;
          ++j;
          for(;s[i]!=0x22&&tt[j]!=0x22;){
            if(s[i]!=tt[j]){
              ++ff;
              fff=1;
              break;
            }
            ++i;
            ++j;
          }
          if(fff==0&&s[i]!=tt[j]){
            ++ff;
          }
          fff=0;
          while(s[i]!=0x22){
            ++i;
          }
          while(tt[j]!=0x22){
            ++j;
          }
          ++i;
          ++j;
        }
      if(ans==1)break;
      }
    }
    if(i==int(s.size())&&j==int(tt.size())){}
    else{
      ans=1;
    }
    if(ans==1||ff>=2){
      printf("DIFFERENT\n");
    }
    else if(ff==0){
      printf("IDENTICAL\n");
    }
    else{
      printf("CLOSE\n");
    }
    cin >> s;
  }
}

