#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <climits>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
using namespace std;
typedef pair<int ,int > P;
typedef long long ll;

struct Dir {
    string name;
    bool is_file;
    Dir(string name, bool is_file) : name(name),is_file(is_file) {}
    bool operator==(const Dir &rhs) const {
        return name==rhs.name&&is_file==rhs.is_file;
    }
};

vector<Dir> split(const string &s, char delim) {
    vector<Dir> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        if (!item.empty()) {
            elems.push_back(Dir(item,false));
        }
    }
    return elems;
}

vector<Dir> get_path(const string &s) {
    vector<Dir> tmp=split(s,'/');
    if(s[s.size()-1]=='/') {
        tmp.pb(Dir("index.html",true));
    }
    else if(tmp[tmp.size()-1].name!="index.html") {
        //tmp.pb("index.html");
    }
    //tmp[tmp.size()-1].is_file=true;

    return tmp;
}

struct Node {
    string name;
    vector<Node*> children;
    Node* parent;
    Node(string name) : name(name) {
        parent=nullptr;
    }
    ~Node() {
        for(auto child:children) delete child;
    }

    void add(Node *node,vector<Dir> &path,int pos) {
        if(pos==path.size()) return;
        Node *t = new Node(path[pos].name);
        bool f=true;
        for(auto child:node->children) {
            if(child->name==path[pos].name) {
                t=child;
                f=false;
                break;
            }
        }
        if(f) node->children.pb(t);
        t->parent=node;
        add(t,path,pos+1);
    }
    void show(int indent) {
        cout<<string(indent,'\t');
        if(parent!=nullptr) 
        cout<<name<<"("<<parent->name<<")"<<endl;
        rep(i,children.size()) {
            children[i]->show(indent+1);
        }
    }
    bool find(Node *node,const vector<Dir> &in,int pos,vector<Dir> &ret) {
        if(in.size()==pos+1) {
            // file
            if(node->children.size()==0) return true;
            else {
                bool f=false;
                if(in[in.size()-1].is_file) return false;
                for(auto child:node->children) {
                    if(child->name=="index.html"&&child->children.size()==0) f=true;
                }
                if(f) {
                    ret.pb(Dir("index.html",true));
                }
                return f;
            }
        }
        //cout<<pos<<" : "<<node->name<<", "<<in[pos]<<", "<<in.size()<<", "<<node->children.size()<<endl;
        if(in[pos+1].name==".") {
            return find(node,in,pos+1,ret);
        }
        if(in[pos+1].name=="..") {
            if(node->parent==nullptr) return false;
            ret.erase(--ret.end());
            return find(node->parent,in,pos+1,ret);
        }

        for(auto child:node->children) {
            //cout<<"\t"<<child->name<<endl;
            if(child->name==in[pos+1].name) {
                if(child->children.size()!=0) {
                    ret.pb(Dir(child->name,false));
                    return find(child,in,pos+1,ret);
                }
                else {
                    ret.pb(Dir(child->name,true));
                    return in.size()==pos+2;
                }
            }
        }

        return false;
    }
};

int N,M;

void solve() {
    Node root("/");
    rep(i,N) {
        string s;
        cin>>s;
        vector<Dir> tmp=get_path(s);
        root.add(&root,tmp,0);
    }
    //root.show(0);
    rep(i,M) {
        string s1,s2;
        cin>>s1>>s2;
        vector<Dir> path1;
        vector<Dir> path2;
        vector<Dir> tmp1(get_path(s1));
        vector<Dir> tmp2(get_path(s2));
        path1.pb(Dir("/",false));
        path2.pb(Dir("/",false));
        rep(i,tmp1.size()) path1.pb(tmp1[i]);
        rep(i,tmp2.size()) path2.pb(tmp2[i]);

        tmp1.clear(); tmp2.clear();
        if(!root.find(&root,path1,0,tmp1)) {
            cout<<"not found"<<endl;
        }
        else if(!root.find(&root,path2,0,tmp2)) {
            cout<<"not found"<<endl;
        }
        else {
            bool f=tmp1.size()==tmp2.size();
            if(f) rep(i,tmp1.size()) {
                f&=tmp1[i]==tmp2[i];
            }
            /*
            rep(i,tmp1.size()) cout<<tmp1[i]<<", ";
            cout<<endl;
            rep(i,tmp2.size()) cout<<tmp2[i]<<", ";
            cout<<endl;
            */
            if(f) cout<<"yes"<<endl;
            else cout<<"no"<<endl;
        }
    }

}

int main() {
    while(cin>>N>>M) {
        if(N+M==0) break;
        solve();
    }
    return 0;
}