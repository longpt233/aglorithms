#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
 
 int n;
 int a[1000000];
 int mem[1000000];// mang luu do dai day con tang lon nhat cho toi i
 int Dp(int i){  // do dai day con tang ket thuc tai phan tu i
        if(mem[i]!=-1) return mem[i];
        int res=1;
        for ( int j = 0; j < i ; j ++) {
            if ( a[j] < a[i]) {
                res = max( res , 1 + Dp(j));
            }
        }
        mem[i] = res ;
        return res;
    }

int main(){
    ios_base::sync_with_stdio(false);
    
    cin>>n;
    //int f[n];

   // memset(mem,-1,n);   // deo hieu tai sao khong duoc 
    for (int i =0;i<n;i++){
        cin >>a[i];
        mem[i]=-1;
    }


mem[0]=1;
//Dp(n-1);  // xong cout max element => 20d ?
 int res=Dp(0);
    for (int i =1;i<n;i++){
        res=max(res,Dp(i));
    }

cout<<res;
    // for (int i =0;i<n;i++){
    //     cout<< mem[i]<<" ";
    // }
// cout<<res;
    //cout <<li[2];

    //cout <<f[1];
   
    // for(int i=0;i<n;i++){
    //     cin >>a[i];
    //     f[i] = 1;
    //     if(i>0){
    //         for (int j=0; j<i; j++) if (a[j] < a[i]) {
    //             f[i] = max(f[i], f[j] + 1);
    //         }
    //     }
    // }

   // cout << *max_element(mem,mem+n);

//cout << li[2];

    
   
    return 0;
}