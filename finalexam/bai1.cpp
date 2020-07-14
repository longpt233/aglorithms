#include<bits/stdc++.h>

using namespace std;
int n,m;

int main(){
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    if((m+n)==0) {cout <<0;return 0;}
    int k=min(n,m);
    if(n<100){
        if(k<m||k<n) k++;
    } else if(k>m||k>n) k++;
    cout << (int)sqrt(2*k);

    return 0;
}