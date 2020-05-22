
#include<iostream>

using namespace std;

int n,k1,k2;
int ans=0;
int x[100];// trang thai da qua 0 la nghi 1 la lam 
int snl=0;
void Print(){
    for (int i=1;i<=n;i++){
        cout <<x[i];
    }
    cout<< endl;
}

void Try(int k){ 
    int start=0,end=1;
    
    if (k>1){
        if (x[k-1]==0) start=1;
        else if(snl>=k2) end=0;
        else if (snl<k1) start=1;
    }

    for (int i=start;i<=end;i++ ){
        x[k]=i;
        if(x[k]==1) snl ++;
        if (k==n) ans++;   //Print();
        else Try(k+1);
        if(x[k]==1) snl--;
    }

}


int main(){
    cin >> n>>k1 >>k2; // so buoi nghi >= k1<= k2
    Try(1);
    cout << ans;


    return 0;
}