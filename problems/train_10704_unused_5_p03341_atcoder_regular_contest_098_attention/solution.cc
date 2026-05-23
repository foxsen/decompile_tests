#include <cstring>
#include <bits/stdc++.h>
using namespace std;
int main(){
int counter1,counter2;
counter1=0;
counter2=0;
int N;
cin>>N;
string str;
cin>>str;
for (int i=1;i<str.size();i++){
if (str.at(i)=='E')
counter1++;}
counter2=counter1;
for (int i=1;i<str.size();i++){
if (str.at(i-1)=='W'){
counter1++;}
if (str.at(i)=='E'){
counter1--;}
counter2=min(counter1,counter2);}
cout<<counter2<<endl;}


