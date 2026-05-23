#include<stdio.h>
#include<cmath>
#include<string.h>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

#define MAX 3000000
#define MAXN 9999
#define MAXSIZE (100005/2)
#define DLEN 4

class BigNum{
public:
    int a[100005/2];
    int len;

    BigNum(){len=1,memset(a,0,sizeof(a));}
    BigNum(const int);
    BigNum(const char*);
    BigNum(const BigNum &);
    BigNum &operator =(const BigNum &);
    friend istream& operator >>(istream&, BigNum&);
    friend ostream& operator <<(ostream&, BigNum&);
    BigNum operator +(const BigNum &) const;
    BigNum operator -(const BigNum &) const;
    BigNum operator *(const BigNum &) const;
    BigNum operator /(const int &) const;
    BigNum operator ^(const int &) const;
    int operator %(const int &) const;
    bool operator >(const BigNum &) const;
    bool operator >(const int &t) const;
    void print();
};
BigNum::BigNum(const int b){
    int c,d=b;
    len=0;
    memset(a,0,sizeof(a));
    while(d>MAXN){
        c=d-(d/(MAXN+1))*(MAXN+1);
        d=d/(MAXN+1);
        a[len++]=c;
    }
    a[len++]=d;
}
BigNum::BigNum(const char*s){
    int t,k,index,l,i;
    memset(a,0,sizeof(a));
    l=strlen(s);
    len=l/DLEN;
    if(l%DLEN)
        len++;
    index=0;
    for(i=l-1;i>=0;i-=DLEN){
        t=0;
        k=i-DLEN+1;
        if(k<0)
            k=0;
        for(int j=k;j<=i;j++)
            t=t*10+s[j]-'0';
        a[index++]=t;
    }
}
BigNum::BigNum(const BigNum &T):len(T.len){
    int i;
    memset(a,0,sizeof(a));
    for(i=0;i<len;i++)
        a[i]=T.a[i];
}
BigNum &BigNum::operator=(const BigNum &n){
    int i;
    len=n.len;
    memset(a,0,sizeof(a));
    for(i=0;i<len;i++)
        a[i]=n.a[i];
    return *this;
}
istream &operator>>(istream &in,BigNum &b){
    char ch[MAXSIZE*4];
    int i=-1;
    in>>ch;
    int l=strlen(ch);
    int count=0,sum=0;
    for(i=l-1;i>=0;){
        sum=0;
        int t=1;
        for(int j=0;j<4&&i>=0;j++,i--,t*=10)
            sum+=(ch[i]-'0')*t;
        b.a[count]=sum;
        ++count;
    }
    b.len=count++;
    return in;
}
ostream& operator<<(ostream& out,BigNum &b){
    int i;
    out<<b.a[b.len-1];
    for(i=b.len-2;i>=0;--i){
        out.width(4);
        out.fill('0');
        out<<b.a[i];
    }
    return out;
}
BigNum BigNum::operator+(const BigNum &T) const{
    BigNum t(*this);
    int i,big;
    big=T.len>len?T.len:len;
    for(i=0;i<big;i++){
        t.a[i]+=T.a[i];
        if(t.a[i]>MAXN){
            t.a[i+1]++;
            t.a[i]-=MAXN+1;
        }
    }
    if(t.a[big]!=0)
        t.len=big+1;
    else
        t.len=big;
    return t;
}
BigNum BigNum::operator-(const BigNum &T) const{
    int i,j,big;
    bool flag;
    BigNum t1,t2;
    if(*this>T){
        t1=*this;
        t2=T;
        flag=0;
    }
    else{
        t1=T;
        t2=*this;
        flag=1;
    }
    big=t1.len;
    for(i=0;i<big;i++){
        if(t1.a[i]<t2.a[i]){
            j=i+1;
            while(t1.a[j]==0)
                j++;
            t1.a[j--]--;
            while(j>i)
                t1.a[j--]+=MAXN;
            t1.a[i]+=MAXN+1-t2.a[i];
        }
        else
            t1.a[i]-=t2.a[i];
    }
    t1.len=big;
    while(t1.a[t1.len-1]==0&&t1.len>1){
        t1.len--;
        big--;
    }
    if(flag)
        t1.a[big-1]=0-t1.a[big-1];
    return t1;
}
BigNum BigNum::operator*(const BigNum &T) const{
    BigNum ret;
    int i,j,up;
    int temp,temp1;
    for(i=0;i<len;i++){

    }
    return ret;
}
BigNum BigNum::operator/(const int &b) const{
    BigNum ret;
    return ret;
}
bool BigNum::operator>(const BigNum &T) const{
    int ln;
    if(len>T.len)
        return true;
    else if(len==T.len){
        ln=len-1;
        while(a[ln]==T.a[ln]&&ln>=0)
            ln--;
        if(ln>=0&&a[ln]>T.a[ln])
            return true;
        else
            return false;
    }
    else
        return false;
}
bool BigNum::operator>(const int &t) const{
    BigNum b(t);
    return *this>b;
}
void BigNum::print(){
    int i;
    cout<<a[len-1];
    for(i=len-2;i>=0;--i){
        cout.width(DLEN);
        cout.fill('0');
        cout<<a[i];
    }
    cout<<endl;
}

char A[100005],B[100005];
int main(){
    scanf("%s",A);
    scanf("%s",B);
    if(A[0]=='-'&&B[0]=='-'){
        BigNum a(A+1);
        BigNum b(B+1);
        printf("-");
        a=a+b;
        cout<<a;
    }
    else if(A[0]=='-'&&B[0]!='-'){
        BigNum a(A+1);
        BigNum b(B);
        BigNum c;
        c=b-a;
        cout<<c;
    }
    else if(A[0]!='-'&&B[0]=='-'){
        BigNum a(A);
        BigNum b(B+1);
        BigNum c;
        c=a-b;
        cout<<c;
    }
    else{
        BigNum a(A);
        BigNum b(B);
        a=a+b;
        cout<<a;
    }
    cout<<endl;
}
