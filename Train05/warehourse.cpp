#include<iostream>
#include<algorithm>

using namespace std;

int main(){

    int n,t1,d;
    cin >>n>>t1>>d;  // voi t1 la thoi gian max
    int a[n],t[n];   // t la mang cua thoi gian chat kho i
    for (int i=0;i<n;i++){
        cin >>a[i];
    }
    for (int i =0;i<n;i++){
        cin >>t[i];
    }
    
    int f[n][t1+1]; //f[i][k] =max toi i voi thoi gian <=k
    //i chay tu 0 toi n-1 
    // k chay tu 

    
    // for (int i=0;i<n;i++){
    //     if(i==0) for (int k=t[i];k<=t1;k++) f[i][k]=a[i];
    //     for(int k=0;k<t[i];k++){
    //         f[i][k]=0;
    //     }
    // }
    for (int i=0;i<n;i++){
        for (int j=0;j<=t1;j++){
            f[i][j]=0;
            if(i==0&&j>=t[0]) f[i][j]=a[0];
            //cout<< f[i][j];
        }
        //cout<< endl;
    }
    int res=0;
    for(int i=0;i<n;i++){
        for(int k=t[i];k<=t1;k++){
            for (int j=max(0,i-d);j<i;j++){
                f[i][k]=max(f[i][k],f[j][k-t[i]]+a[i]);   // k-t => dam bao luon nho hon k
            }
            res=max(res,f[i][k]);
        }   
    }

    cout << res;
    
    return 0;
}