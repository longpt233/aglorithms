#include<bits/stdc++.h>

using namespace std;

const  int mod = 1000000007;

int main(){
    int n;
    cin>>n;
     int64_t c=4;
     int64_t b=15;
     int64_t a=0;
    for (int i=4;i<=n;i++){
        // if(c>mod){
        //     a=a%mod;b=b%mod;c=c%mod;
        // }
        a=( int64_t)((int64_t)4*b-c);
        c=( int64_t)b;
        b=( int64_t)a;
    }
    if(n==2) cout<<4;
    else if(n==3) cout<<15;
    else{
        if(a>=mod) a=a%mod;
        cout<< a;
    }
    
    

    return 0;
}