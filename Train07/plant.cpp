#include<bits/stdc++.h>
using namespace std;

int main (){
    int n;
    cin>>n;
    int t[1000000];
    int res[1000000];

    for (int i =0;i<n;i++){
        cin >> t[i];
    }

    sort(t,t+n);   // cai lau nhat se o cuoi cung
                    // cai nhanh nhat se ve dau 
    // if (n+t[0]+1>t[n-1]+2)
    //     cout<< n+t[0]+1;
    // else
    //     cout<<t[n-1]+2;
    
   
    for (int i =n-1;i>=0;i--){
        res[i]=n-i+t[i]+1;
    }
    cout<<*max_element(res,res+n);
    

    return 0;
}