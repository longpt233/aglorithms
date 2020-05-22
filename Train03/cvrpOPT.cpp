// chi phi nho nhat 

#include<bits/stdc++.h>

using namespace std;

int n,k,q;
int d[13]={0};
int sokhach[6]={0};  // cung lam 5 xe
int sothung[6]={0};

int x[13]={0};   // khach i = xe j phuc vu
int c[13][13]={0};  // cung lam 12 khach
int fopt=100000;

int minSothung(){
    int m=INT32_MAX;
    for(int i=1;i<=k;i++){
        if(sothung[i]<m) m=sothung[i];
    }
    return m;
}

bool pass[13];
int road[13];
int F;
int FMin; 

void TryTSP(int i, int h){  // try toi so khach hang xe h phuc vu
    for (int k=0;k<=n;k++){   // thu tat ca khach hang 
        if(pass[k]==false&&x[k]==h){//&&c[road[i-1]][k]!=0){ 
            pass[k]=true;
            road[i]=k;
            F=F+c[road[i-1]][k];
            if(i==sokhach[h]){
                if ((F+c[road[i]][0])<FMin)//&&cost[road[i]][1]!=0) 
                    {FMin=F+c[road[i]][0];
                        for(int z=0;z<=i;z++){
                            //cout<< road[z]<<"==>";
                        }
                        //cout<<"Fmin="<<FMin<<endl;
                    }
            }else{
                //if ((f+(n-i+1)*cMin) <fMin) 
                TryTSP(i+1,h);
            }
            F=F-c[road[i-1]][k];
            pass[k]=false;
            road[i]=0;
        }
    }
}

int TSP(int i){   //tim quang duong ngan nhat cua xe i
    //cout<< " load vao xe "<<i<<"....."<<endl;
    pass[13]={false};
    road[13]={0};
    F=0;
    FMin =INT32_MAX;
    pass[0]=true;
    TryTSP(1,i);
    return FMin;
}


void Try(int i){  // try toi so khach
    for(int j=1;j<=k;j++){    // thu het cac xe 
        if(d[i]+sothung[j]<=q){// neu con chat dc them 
            sothung[j]+=d[i];
            sokhach[j]++;
            x[i]=j;
            if(i==n&&minSothung()>0){
                int f=0;   // luu tru tong quang duong cua th hien tai
                for(int h=1;h<=k;h++){// tinh tong ngan nhat cua tung xe
                    int l=TSP(h);
                    f+=l;
                    
                    //cout<< "min xe "<<h<<"="<<l<< endl;
                }
                //cout <<"f="<<f<<endl;
                fopt=min(f,fopt);
                //cout<<"fopt="<<fopt<<endl<<"============"<<endl;
                
        
            }else if(true){
                Try(i+1);
            }
            sothung[j]-=d[i];
            sokhach[j]--;
            x[i]=0;
        }
    }
}

int main (){
    //freopen("input.txt","r",stdin); // qick input 
    cin >>n>>k>> q;
    for (int i=1;i<=n;i++){
        cin >>d[i];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cin >> c[i][j];
        }
    }

  /*   cout<< n<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout<< c[i][j]<<" ";
        }
        cout<< endl;
    } */

    Try(1);
    cout<< fopt;
    return 0; // return 1 la co loi 
}