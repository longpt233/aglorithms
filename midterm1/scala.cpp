#include<iostream>
#include<algorithm>

using namespace std;

int T, n;
int x[1000]={0};
int y[1000]={0};

int fopt=INT32_MAX;
int fcur=0;

int pass[1000]={0};// danh dau tat car cac diem chua tham 

void Try(int i){  // try toi so luong phan tu n
    for(int j=1;j<=n;j++){
        if(pass[j]==0){
            pass[j]=1;
            fcur+= x[i]*y[j];
            if(i==n){
                fopt=min(fopt,fcur);
            }else if(fcur<fopt){
                Try(i+1);
            }
            pass[j]=0;
            fcur-=x[i]*y[j];
        }
    }
}


int main(){
    cin>> T;
    for(int i=1;i<=T;i++){
        fopt=INT32_MAX;
        cin >> n;

        int maxxduong=0;
        int maxxam=0;
        for(int j=1;j<=n;j++){
            cin>>x[j];
            
        }
        for(int j=1;j<=n;j++){
            cin>>y[j];
        }

        Try (1);
        

        cout<< "Case #"<<i<<": " <<fopt<<endl;


    }
    return 0;
}