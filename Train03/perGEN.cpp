#include<iostream>

using namespace std;

int n;
int *x;
int *goal;
int *result;
bool *flag;
int f=0;

// int find =0  => loi trung mot ham nao do .them #define find acasfxc

void CopyToResult(int *x){
    for (int i=1;i<=n;i++){
        result[i]=x[i];
    }
}

bool Same(int *x,int *y){
    for (int i=1;i<=n;i++){
        if (y[i]!=x[i])return false;
    }
    return true;
}

void Accept(){
    if(1==f) {
        CopyToResult(x);
        f=2;
    }
    if (f==0){
        if(Same(x,goal)) f=1;
    }
}

void Try(int i){
    for (int t=1;t<=n;t++){
        if(flag[t]==false){
            flag[t]=true;
            x[i]=t;
            if(i==n) Accept();
            else if(f!=2) Try(i+1);
            flag[t]=false;
        }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin >>n;
    goal=new int[n+1];
    x=new int [n+1];
    result= new int[n+1];
    flag=new bool[n+1];
    for (int i=1;i<=n;i++){
        cin>>goal[i];
        flag[i]=false;
    }
    Try(1);
    if(f ==0) cout <<"-1";
    else 
    for (int i=1;i<=n;i++) cout << result[i]<<" ";
    
    return 0;
}