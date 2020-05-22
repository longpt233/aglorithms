#include<bits/stdc++.h>

using namespace std;

int n,m;
int c[17];
int a[17][17];
int pass[17]={0};// pass mon k 
int x[17]={0};  // mom[]= ki 

int y[17]={0};// luu tru hoc ki tinh toi mon thu i
int ymaxtoi[17]={0}; // luu tru thoi luong hoc ki toi i 
int yTC[6]={0};  // luu trx=u so tin chi cua hoc ki []
int yMAX=INT32_MAX;
 
int HocPhanDieuKien(int i,int j){//check mon j co the hoc trongki i
    if(i==1) return 1;
    for(int k=1;k<=i-1;k++){
        for(int h=1;h<=n;h++){
            if(a[h][j]==1){
                if(pass[j]==1) return 1;  // 1 la dc day
                else return 0;
            }
        }
    }
    return 1;  // 1 neu co the cung mot ki 
}

// 
void Try(int i){   // try o toi so mon hoc n  
    for(int k=1;k<=m;k++){  // phan bo mon i vao hoc ki k
        if(pass[i]==0&&HocPhanDieuKien(k,i)&&yTC[k]<=yMAX){
            pass[i]=1;
            x[i]=k;   // hoc i o hoc ki k.
            yTC[k]+=c[i];
            if(i==n){
                ymax;
            }else{

                Try(i+1);
            }
            yTC[k]-=c[i];
            pass[i]=0;
        }
    }
}

int main (){
    cin >> n>>m;
    for(int i=1;i<=n;i++){
        cin >> c[i];

    }
    for(int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin >>a[i][j];
        }
    }




    return 0;
}