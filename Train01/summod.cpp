#include<iostream>

using namespace std;
const unsigned int c = 1000000007;

int SumMod(int *a,int n){
    int result=0;
    for (int i=0;i<n;i++){
        result= ((result%c)+(a[i]%c))%c;
    }
    return result;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>> a[i];
    }
    cout<< SumMod(a,n);
    return 0;
}