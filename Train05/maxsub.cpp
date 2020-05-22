#include<bits/stdc++.h>

using namespace std;

int mem[1000000];
int a[1000000];

// dday la day con tang dai nhat 
// int Dp(int i){
//     cout<< i<<":";
//     if (mem[i]!=-1) return mem[i];
//     //int res= Dp(i-1);  // false
//     int res=mem[i-1];
//     if(a[i]>0) res+=a[i];
//     mem[i]=res;
//     cout<< mem[i]<< endl;
//     return res;
// }

int Dp(int i){
    //cout<< i<<":";
    if (mem[i]!=-1) return mem[i];
    //int res= Dp(i-1);  // false
    int res=mem[i-1];
    // for (int j=i-1;j>=0;j--)
    //      res=max(res,res+mem[i]);
    res=max(a[i],res+a[i]);
    mem[i]=res;
    //cout<< mem[i]<< endl;
    return res;
}

int main(){
    int n;
    cin>> n;
    for (int i =0 ; i<n; i++){
        cin >> a[i];
        mem[i]=-1;
    }
    mem[0]=a[0];
    int res=a[0];
    for(int i=1;i<n;i++){
        res=max(Dp(i),res);
        //cout << mem[i]<<" ";
    }
    cout << res;
    // chua chac mem[n-1] da la max 




    return 0;
}