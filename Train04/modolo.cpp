#include<bits/stdc++.h>

using namespace std;

int x,n,p;

int modulo(int x,int n, int p){
    if (n==0) return 1;
    if(n%2) return(x*modulo(x,n-1,p)%p);
    int r=modulo(x,n/2,p);
    return((r*r)%p);
}

int mian(){
    cin >>x>>n>>p;
    cout << modulo(x,n,p);

}