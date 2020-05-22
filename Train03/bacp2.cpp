

#include<bits/stdc++.h>

using namespace std;

int n,m;
int c[17];
int minTC=INT16_MAX;
int a[17][17];

int x[17]={0};  // mom[]= ki 

int ymaxtoi[17]={0}; // luu tru yTC max  toi khi phan mon i
int yTC[6]={0};  // luu trx=u so tin chi cua hoc ki []
int yMAX=INT32_MAX;
 
int HocPhanDieuKien(int j,int i){//check mon j co the hoc trongki i khi phan xong j-1 mon
    if(i==1) return 1;       // daon nay sai :))
    //for(int k=1;k<=i-1;k++){    // check nhung hoc ki trc no 
        for(int h=1;h<=j-1;h++){    // check tat ca mon hoc
            if(a[h][j]==1){          // neu co mau thuan 
                if(x[h]<i)         // neu mon do dc hoc o ki trc do 
                
                     return 1;  // 1 la co the day 
                else return 0;
                
            }
        }
    //}
    return 1;  // 1 neu co the day 
}

// 
void Try(int i){   // try o toi so mon hoc n  
    for(int k=1;k<=m;k++){  // phan bo mon i vao hoc ki k
        if(HocPhanDieuKien(i,k)==1&&(yTC[k]+c[i])<yMAX){
            
            x[i]=k;   // hoc i o hoc ki k.
            yTC[k]+=c[i];
            if(i==n){
                //cout<< "ymaxtoi :"<<i<<"  laf:"<<ymaxtoi[i]<<endl;
                yMAX= min(ymaxtoi[i-1],yMAX);
                /* cout<< yMAX<<endl;
                for(int q=1;q<=n;q++){
                    cout <<x[q]<<" ";
                } */
                //cout<<"================================";
            }else{
                ymaxtoi[i]=max(ymaxtoi[i-1],yTC[k]);
                if(ymaxtoi[i]<yMAX) Try(i+1);
            }
            yTC[k]-=c[i];
            
        }
    }
}

int main (){
    cin >> n>>m;
    for(int i=1;i<=n;i++){
        cin >> c[i];
        if (c[i]<minTC) minTC=c[i];
    }
    for(int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin >>a[i][j];
        }
    }
    //cout<<endl;
    
    Try(1);
    cout<< yMAX;



    return 0;
}