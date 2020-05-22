#include<iostream>

using namespace std;

int n;
int cost[30][30];
bool visited[12]={false};
int x[12];
int fMin=INT32_MAX;
int f=0,g=0;
int cMin=INT16_MAX; // cost max


void Try(int k){
    if(k==1){
        for (int i=1;i<=n;i++){
            x[k]=i;
            visited[i]=true;
            f+=cost[0][i]+cost[i][i+n];
            Try(k+1);
            f-=cost[0][i]+cost[i][i+n];
            visited[i]=false;
        }
    }else
    for(int i=1;i<=n;i++){
        if (visited[i]==false){  // dm == 
            x[k]=i;
            visited[i]=true;
            f+=  cost[x[k-1]+n][i]+cost[i][i+n];
            if (k==n) {
                if (f+cost[i+n][0]<fMin) 
                    fMin= f+cost[i+n][0];
            }else{
                g=f+(2*(n-k)+1)*cMin; // chi phi di tiep tot nhat
                if (g<fMin)  Try(k+1);// neu di tiep co the tot honthi moi dii
            }
            visited[i]=false;
            f-=  cost[x[k-1]+n][i]+cost[i][i+n];
        }
    }
}

int main(){
    cin >>n;
    
    for (int i=0;i<2*n+1;i++){
        for (int j=0;j<2*n+1;j++){
         cin>> cost[i][j];
         if ((cMin >cost[i][j])&&cost[i][j]!=0) cMin=cost[i][j];
        }
    }
    
  /*   for (int i=0;i<2*n+1;i++){
        for (int j=0;j<2*n+1;j++){
         cout<< cost[i][j]<<" ";
         
        }
        cout<<endl;
    } */

    //cout<<cMax;
    x[0]=0;
    visited[0]=true;
    Try(1);
    cout<< fMin;

    return 0;
}