
#include<iostream>
using namespace std;

int main()
{
  int list[7][7]={
    {0,300,500,600,700,1350,1650},
    {6,0,350,450,600,1150,1500},
    {13,7,0,250,400,1000,1350},
    {18,12,5,0,250,850,1300},
    {23,17,10,5,0,600,1150},
    {43,37,30,25,20,0,500},
    {58,52,45,40,35,15,0}
  };
  int in,out,h,m,start,end,fee;
  bool half;
  while(cin>>in,in){
    cin>>h>>m;
    start=100*h+m;
    cin>>out>>h>>m;
    end=100*h+m;
    if(in>out)swap(in,out);
    in--;out--;
    if( (1730<=start && start<=1930) || (1730<=end && end<=1930) )half=true;
    else half=false;
    if(list[out][in]>40)half=false;
    fee=list[in][out];
    if(half){
      fee/=2;
      fee+=25;
      fee/=50;
      fee*=50;
    }
    cout<<fee<<endl;
  }
}