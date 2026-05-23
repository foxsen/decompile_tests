#include <bits/stdc++.h>
using namespace std;

class arrayInfo{
  private:
    int element=-1;
    map<string,string> value;
  public:
    bool isInRange(string index){
        return stoi(index)<element;
    }
    void set(string index, string val){
        if(isInRange(index)){
            value[index]=val;
        }else{
            throw 1;
        }
    }
    string get(string index){
        if(isInRange(index) && value.find(index)!=value.end()){
            return value[index];
        }else{
            throw 1;
        }
    }
    void setRange(string range){
        if(element==-1){
            element=stoi(range);
        }else{
            throw 1;
        }
    }
};
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

map<string, arrayInfo> ar;

string parse(string str, string type){
    int l,r;
    if(str.find("[")!=string::npos){
        l=str.find("[");
        r=str.rfind("]");
        if(type=="name") return str.substr(0,l);
        if(type=="index") return parse(str.substr(l+1,r-l-1), "value");
        if(type=="value") return ar[str.substr(0,l)].get(parse(str.substr(l+1,r-l-1), "value"));
    }
    return str;
}

int main(void){
    while(true){
        ar.erase(ar.begin(),ar.end());
        //cout<<"=========\n";
        string ln;
        cin>>ln;
        if(ln=="."){
            break;
        }
        int n=1;
        bool isOccured=false;
        while(ln!="."){
            try{
                if(ln.find("=")==string::npos){
                    ar[parse(ln,"name")].setRange(parse(ln,"index"));
                }else{
                    string ls=ln.substr(0,ln.find("="));
                    string rs=ln.substr(ln.find("=")+1);
                    ar[parse(ls,"name")].set(parse(ls,"index"),parse(rs,"value"));
                }
            }catch(...){
                isOccured=true;
                break;
            }
            n++;
            cin>>ln;
        }
        if(isOccured){
            cout<<n<<endl;
            while(cin>>ln,ln!=".");
        }else{
            cout<<0<<endl;
        }
    }
}