#include<bits/stdc++.h>

using namespace std;

int n,k,q;
int d[11]={0};
int R=0;
int sokhach[6]={0};
int sothung[6]={0};
const int mod=1000000007;

int minSothung(){
    int m=INT32_MAX;
    for(int i=1;i<=k;i++){
        if(sothung[i]<m) m=sothung[i];
    }
    return m;
}

int fato2[11]={0};// cung lam 1 xe phuc vu 10
int fato(){  // tinh san gia thua cho toi n
    fato2[0]=1;
    for(int i=1;i<=11;i++){
        fato2[i]=fato2[i-1]*i;
    }
}


void Try(int i){  // try toi so khach
    for(int j=1;j<=k;j++){    // thu het cac xe 
        if(d[i]+sothung[j]<=q){
            sothung[j]+=d[i];  // song luong xe j cho
            sokhach[j]++;
            if(i==n&&minSothung()>0){
                int temp=1;
                for(int h=1;h<=k;h++){  // tinh den so xe
                  //  cout<< sokhach[h]<<"  "<<sothung[h]<<endl;
                    temp *=(fato2[sokhach[h]]);
                }
                
                //temp/fato2[k];
                R=(R+temp)%mod;
               // cout<<R<<"  ==============="<<endl;
            }else if(true){
                Try(i+1);
            }
            sothung[j]-=d[i];
            sokhach[j]--;
        }
    }
}

int main (){
    cin >>n>>k>> q;
    for (int i=1;i<=n;i++){
        cin >>d[i];
    }
    
    fato();
    Try(1);
    cout<< R/fato2[k];   // chia cho so hoan vi cac xe nua
    return 0; // return 1 la co loi 
}