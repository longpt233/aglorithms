#include<iostream>
#include<stack>

using namespace std;

string s;
int lengs=0;

int f=0;

bool Check(string s){
    //bool ok=false;
    stack<char> k;
    for(int i=0;i<s.length();i++){
        if(k.empty())
            k.push(s.at(i));
        else if(k.top()=='('&&s.at(i)==')'){
            k.pop();
        }
        else{
            k.push(s.at(i));
        }
    }
    if(k.empty()) return true;
    return false;
    
}

void Try(int i){ // try toi so ki tu 
    if(i==lengs-1){
            //cout<< s<<endl;
            if(Check(s)==true) f=(f+1)%1000000007;
    }else if(s[i]=='?'){
        s[i]='(';
            
            Try(i+1);
        
        s[i]=')';
        
            Try(i+1);
        s[i]='?';  // tra lai 
    }else Try(i+1);
}

int main(){
    cin>> s;
    lengs=s.length();

    //cout <<lengs<<s.at(0);

    /* if(Check(s)) cout<< "ok";
    else
    {
        cout << "k dung";
    } */
    
     Try(0);
     cout<<f;

    return 0;
}