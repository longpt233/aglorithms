#include<bits/stdc++.h>

using namespace std;


string a;
int pos;
int leng;
int x; // chieu dai 
void findmax(){
    int max=-1;
    for(int j=pos+1;j<leng-x;j++){
        if((int)a.at(j)>max) {
            max=a.at(j);
            pos=j;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin>> a;
    leng= a.size();
    //cout<< leng;
    cin>>x;
    pos=-1;
    if(x==leng) cout<<a;
    else
    while (x--){
        findmax();
        cout<< a.at(pos);
    }
    

    return 0;
}