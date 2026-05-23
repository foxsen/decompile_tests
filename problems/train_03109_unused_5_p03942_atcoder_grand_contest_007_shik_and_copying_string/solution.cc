#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
using namespace std;

int n,ans;
char s[1000010],t[1000010];
deque<int> q;

int main(){
    scanf("%d%s%s",&n,s+1,t+1);
    q.push_back(n+1);
    for(int i=n,j=n+1,tmp=0,pre;i;i--){
        for(pre=j;j&&(i<j||s[j]!=t[i]);j--);
        if(!j){
            puts("-1");
            return 0;
        }
        if(pre==j){
            while(!q.empty()&&q.back()-tmp>=i)
                q.pop_back();
            q.push_back(i+tmp);
        }
        else{
            tmp++;
            if(i!=j){
                ans=max(ans,(int)q.size());
                q.push_front(j+tmp);
            }
        }
    }
    printf("%d",ans);
    return 0;
}