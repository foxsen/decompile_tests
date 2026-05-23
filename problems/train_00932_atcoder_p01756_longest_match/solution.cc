#include<stdio.h>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;

#define MAX 200005
#define INF (1<<26)

int segN=1000000;
struct data{
    int value;
    data* ch[2];
    
    void init(){
        value=INF;
        ch[0]=new data;
        ch[1]=new data;
        ch[0]->ch[0]=NULL;
        ch[1]->ch[0]=NULL;
    }
    
    void set(int i,int x,int l,int r){
        int m=(l+r)/2;
        if(ch[0]==NULL)init();
        if(i<l || r<=i)return;
        if(x<value)value=x;
        if(r-l==1)return;
        ch[0]->set(i,x,l,m);
        ch[1]->set(i,x,m,r);
    }
    
    void set(int i,int x){
        set(i,x,0,segN);
    }
    
    int min(int a,int b,int l,int r){
        int m=(l+r)/2;
        if(ch[0]==NULL)init();
        if(b<=l || r<=a)return INF;
        if(a<=l && r<=b)return value;
        int lc=ch[0]->min(a,b,l,m);
        int rc=ch[1]->min(a,b,m,r);
        return (lc<rc?lc:rc);
    }
    
    int min(int a,int b){
        if(0<=a&&a<b)return min(a,b,0,segN);
        else return INF;
    }
};

int rak[MAX+1];
int tmp[MAX+1];
int n,k;

bool compare_sa(int i,int j){
    if(rak[i]!=rak[j])return (rak[i]<rak[j]);
    else{
        int ri=(i+k<=n?rak[i+k]:-1);
        int rj=(j+k<=n?rak[j+k]:-1);
        return ri < rj;
    }
}

void construct_sa(string s,int *sa){
    n=s.size();
    for(int i=0;i<=n;i++){
        sa[i]=i;
        rak[i]=(i<n?s[i]:-1);
    }
    for(k=1;k<=n;k*=2){
        sort(sa,sa+n+1, compare_sa );
        tmp[sa[0]]=0;
        for(int i=1;i<=n;i++){
            tmp[sa[i]]=tmp[sa[i-1]]+
            (compare_sa(sa[i-1],sa[i])?1:0);
        }
        for(int i=0;i<=n;i++)rak[i]=tmp[i];
    }
}


int search(string &target,int *sa,string &s){
    int l=0,r=n,m;
    int size=target.size(),res;
    while(l<r){
        m=(l+r)/2;
        res=s.compare(sa[m],size,target);
        if(res>=0)r=m;
        else l=m+1;
    }
    if(s.compare(sa[l],size,target)<0)return n+1;
    return l;
}

int search2(string &target,int *sa,string &s){
    int l=0,r=n,m;
    int size=target.size(),res;
    while(l<r){
        m=(l+r)/2;
        res=s.compare(sa[m],size,target);
        if(res>0)r=m;
        else l=m+1;
    }
    if(s.compare(sa[l],size,target)<=0)return n+1;
    return l;
}

data T,T2;
string s,s2;
string x,y;
int m;
int sa[MAX+1];
int sa2[MAX+1];

int main(){
    T.init();
    T2.init();
    
    cin>>s;
    s2=s;
    reverse(s2.begin(),s2.end());
    
    construct_sa(s2,sa2);
    construct_sa(s,sa);
    
    for(int i=0;i<=n;i++){
        T.set(i,sa[i]);
        T2.set(i,sa2[i]);
    }
    
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        reverse(y.begin(),y.end());
        int xl=search(x,sa,s),xr=search2(x,sa,s);
        int yl=search(y,sa2,s2),yr=search2(y,sa2,s2);
        int xs=x.size();
        int X=T.min(xl,xr);
        int Y=T2.min(yl,yr);
        if(Y!=INF)Y=n-Y;
        
        if(Y<X+xs)cout<<0<<endl;
        else if(X==INF||Y==INF)cout<<0<<endl;
        else cout<<Y-X<<'\n';
        
    }
    
    return 0;
}