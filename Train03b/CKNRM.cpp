#include<iostream>

using namespace std;

int k,n;

const int m=1000000007;

int fato2[1000]={0};// cung lam 1 xe phuc vu 10
int fato(){  // tinh san gia thua cho toi n
    fato2[0]=1;
    for(int i=1;i<=11;i++){
        fato2[i]=fato2[i-1]*i;
    }
}

int C1(int k , int n){
    if(k==0||k==n) return 1;
    if(k==1) return n;
    return ((C1(k-1,n-1)%m)+ (C1(k,n-1)%m))%m;
}

int main(){
    cin >>k>>n;
    cout<< C1(k,n);

    return 0;
}