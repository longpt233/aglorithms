#include<iostream>

using namespace std;

int n,k;// k:cho ngoi ban dau 
int seated=0;   //cho ngoi con lai
int cost[30][30];
bool visited[30]={false};  // mã n=11
int x[30];        // moi ban chi co 1 khach ok
long long fMin=__LONG_LONG_MAX__;
long long  f=0,g=0;
int cMin=INT32_MAX; // cost min



bool UCV(int i){
    if(i<=n){  // den de don duoc khong
        return(visited[i]==false&&seated<k);
    }else{
        return(visited[i]==false&&visited[i-n]==true);  // den de tra duoc khong
    }
}
void Try(int k){
   
    for(int i=1;i<=2*n;i++){
        if (UCV(i)== true){  // dm == 
            x[k]=i;
            visited[i]=true;
            if(i<=n)   // neu den de don 
                seated++;
            else   
                seated--;// neu den de tra
                
            
            f+=cost[x[k-1]][i];

            if (k==2*n) {
                if (f+cost[i][0]<fMin) 
                    fMin= f+cost[i][0];
            }else{
                 g=f+(2*n-k+1)*cMin; // chi phi di tiep tot nhat
                if (g<fMin)   Try(k+1);// neu di tiep co the tot honthi moi dii
            }
            
            visited[i]=false;
            if(i<=n)   // neu den de don 
                seated--;
            else   
                seated++;// neu den de tra
            f-=cost[x[k-1]][i];
           
        }
    }
}

int main(){
    
    cin >>n>>k;
    
    for (int i=0;i<2*n+1;i++){
        for (int j=0;j<2*n+1;j++){
         cin>> cost[i][j];
         if ((cMin >cost[i][j])&&cost[i][j]!=0) cMin=cost[i][j];
        }
    }
    
    seated=0;
    x[0]=0;
    visited[0]=true;
    Try(1);
    cout<< fMin;

    return 0;
}
