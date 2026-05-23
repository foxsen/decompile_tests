#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll unsigned long long
#define pii pair<int,int>
#define uu first
#define vv second
#define INF 1000000000
#define V 38

map<string,int>ma;
map<string,pii>ma1;


struct Person
{
    string name;
    int matha;
    int kobe;
};

bool operator<(Person a,Person b)
{
    if(a.matha!=b.matha)return a.matha>b.matha;
    return a.kobe>b.kobe;
}

set<Person>hard_work;
set<Person>ailsha;

int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        int a;
        scanf("%d",&a);
        //cout<<s<<" "<<a<<endl;
        Person p;
        p.name = s;
        p.matha=a;
        p.kobe=i;
        ailsha.insert(p);
        int y = (i-1)*.2 , u = i*.2;
        ma[s] = 1;
        ma1[s] = pii(i,a);
        if(u>y)
        {
            set<Person>::iterator it = ailsha.begin();

            Person hagu = *it;
            ma[hagu.name] = 2;
            //ma1[s] = pii(hagu.kobe,hagu.matha);
            hard_work.insert(hagu);
            ailsha.erase(hagu);
        }
        else if(u==y and y!=0)
        {
            set<Person>::iterator it = ailsha.begin();
            set<Person>::iterator it1 = hard_work.end();
            it1--;
            if((((*it).matha>(*it1).matha) or (((*it).matha==(*it1).matha)and(*it).kobe>(*it1).kobe)))
            {
                Person hagu = *it;
                Person hay = *it1;
                ma[hagu.name] = 2;
                //ma1[s] = pii(hagu.kobe,hagu.matha);
                hard_work.insert(hagu);

                //if(hagu.name!=s)cout<<s<<" is not working now.\n";
                //cout<<hagu.name<<" is working hard now.\n";
                ailsha.erase(hagu);
                //hagu = *it1;
                ma[hay.name] = 1;
                ailsha.insert(hay);
                hard_work.erase(hay);
                //cout<<hay.name<<" is not working now.\n";
            }
        }
    }
    int sz = n;
    //set<Person>::iterator it = ailsha.begin();
    //for(;it!=ailsha.end();it++)
     //   cout<<it->name<<endl;
    int m;
    scanf("%d",&m);
    getchar();
    for(int q=n+1;q<=n+m;q++)
    {
        //cout<<"hihi\n";
        char c;
        c = getchar();
        //cout<<c<<endl;
        //getchar();
        if(c=='-')
        {
            string s;
            cin>>s;
            if(ma[s]==0)continue;
            //cout<<s<<endl;
            if(ma[s]==1)
            {

                pii uff = ma1[s];
                int matha = uff.second;
                int kobe = uff.first;
                Person p;
                p.name = s;
                p.kobe=kobe;
                p.matha=matha;
                ma[s]=0;
                ailsha.erase(p);
                //else continue;
                int y = (sz-1)*.2 , u = sz*.2;
                //cout<<"HIHI\n";
                if(y<u)
                {
                    set<Person>::iterator it = hard_work.end();
                    it--;
                    Person yuki = *it;
                    //cout<<(*it).name<<endl;
                    cout<<(*it).name<<" is not working now.\n";ailsha.insert(yuki);
                    hard_work.erase(yuki);

                    ma[yuki.name] = 1;
                }
                sz--;
            }
            else
            {
                pii uff = ma1[s];
                int matha = uff.second;
                int kobe = uff.first;
                Person p;
                p.name = s;
                p.kobe=kobe;
                p.matha=matha;
                hard_work.erase(p);
                //else continue;
                ma[s]=0;
                int y = (sz-1)*.2 , u = sz*.2;
                if(y==u)
                {
                    Person yuki = *ailsha.begin();
                    hard_work.insert(yuki);
                    cout<<(yuki).name<<" is working hard now.\n";
                    ma[yuki.name] = 2;
                    ailsha.erase(yuki);

                }
                sz--;
            }
            getchar();
        }
        else
        {
            string s;
            int a;
            cin>>s;

            scanf("%d",&a);
            getchar();

            Person p;
            p.name = s;
            p.matha=a;
            p.kobe=q;
            ailsha.insert(p);
            sz++;
            int y = (sz-1)*.2 , u = sz*.2;
            ma[s] = 1;
            ma1[s] = pii(q,a);
            set<Person>::iterator it = ailsha.begin();
            set<Person>::iterator it1 = hard_work.end();

            if(u == y and u!=0)
            {

                it1--;
                if((((*it).matha>(*it1).matha) or (((*it).matha==(*it1).matha)and(*it).kobe>(*it1).kobe)))
                //cout<<(*it).kobe<<" "<<(*it1).kobe<<endl;
                {
                    Person hagu = *it;
                    Person hay = *it1;
                    ma[hagu.name] = 2;
                    //ma1[s] = pii(hagu.kobe,hagu.matha);
                    hard_work.insert(hagu);

                    //if(hagu.name!=s)cout<<s<<" is not working now.\n";
                    cout<<hagu.name<<" is working hard now.\n";
                    ailsha.erase(hagu);
                    //hagu = *it1;
                    ma[hay.name] = 1;
                    ailsha.insert(hay);
                    hard_work.erase(hay);
                    cout<<hay.name<<" is not working now.\n";
                }
                else cout<<s<<" is not working now.\n";
            }
            else if(u>y and y!=0)
            {
                it1--;

                Person hagu = *it;
                ma[hagu.name] = 2;
                //ma1[s] = pii(hagu.kobe,hagu.matha);
                hard_work.insert(hagu);
                ailsha.erase(hagu);
                if(hagu.name!=s)cout<<s<<" is not working now.\n";
                cout<<hagu.name<<" is working hard now.\n";

            }

            else if(u>y)
            {
                Person p = *ailsha.begin();
                ma[p.name] = 2;
                ailsha.erase(p);
                hard_work.insert(p);
                if(p.name!=s)cout<<s<<" is not working now.\n";
                cout<<p.name<<" is working hard now.\n";
            }




            else cout<<s<<" is not working now.\n";

            //cout<<s<<" "<<a<<endl;
        }
    }
}