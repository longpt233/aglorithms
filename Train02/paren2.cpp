#include<iostream>
#include<stack>
#include<string>

using namespace std;

int IsParen(string a){

    int length=a.length();
    stack<char> b;
   
    int i=0;
    b.push(0);  // k hieu sao k lay dc top == null ??
    b.push(a.at(0));
    while (i<=length-2){
        i++;
    
        if(b.top()=='('&&a.at(i)==')'){
            b.pop();
            continue;
        }
        else if(b.top()=='{'&&a.at(i)=='}'){
            b.pop();
            continue;
        }
        else if(b.top()=='['&&a.at(i)==']'){
            b.pop();
            continue;
        }
        else {
            b.push(a.at(i));
            continue;
        }
            
    }
    /* if (b.top()==0) return 1; */  // ================
    if (0==b.top()) return 1;
    return 0;
}

int main(){
    int t;
    cin >>t;
    int kq[t];
    for(int i=0;i<t;i++){
        string a;
        cin >>a;
        if(IsParen(a)) kq[i]=1;
        else kq[i]=0;
    }
    for(int i=0;i<t;i++){
        cout<<kq[i]<<endl;
    }


    return 0;
}