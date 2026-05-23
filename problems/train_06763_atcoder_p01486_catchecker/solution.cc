#include <iostream>
#include <string>

using namespace std;

typedef string::const_iterator Cursor;
bool cat(Cursor& c,Cursor& e){
    if(*c == 'm'){
        c++;
        cat(c,e);
        if(*c == 'e'){
            c++;
            cat(c,e);
            if(*c == 'w'){
                c++;
                return true;
            }
        }
        return false;
    }else{
        return true;
    }
}

int main(){
    string s;
    cin >> s;
    Cursor c = s.begin(),e = s.end();
    bool r = cat(c,e);
    if(c == e){
        cout << "Cat" << endl;
    }else{
        cout << "Rabbit" << endl;
    }
    return 0;
}