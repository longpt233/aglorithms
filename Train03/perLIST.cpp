
// tim hoan vi thu k
#include<iostream>

using namespace std;

int n,k;
int x[10000];  // mag luu cau hinh   1 2 3 4 5
bool flag[10000]={false};  // so nay da dc dung chua? flag[2]=true
int f=0;
int xOpt[10000];

// int find =0  => loi trung mot ham nao do .them #define find acasfxc

void Try(int i){  // try toi n
    //if(f>k) return;
    for (int t=1;t<=n;t++){
        if(flag[t]==false){
            flag[t]=true;
            x[i]=t;
            if(i==n) {
                f++;
                if (f==k){
                    for(int p=1;p<=n;p++){
                        xOpt[p]=x[p];
                    }
                }
            }else   if(f<k)  {  
                Try(i+1);
            }
            flag[t]=false;
        }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
    cin >>n>>k;
    Try(1);
    if(f <k) cout <<"-1";
    else 
    for (int i=1;i<=n;i++) cout <<xOpt[i]<<" ";
    
    return 0;
}