// bai topan cai tui 
// truong hop khong  dc lay trung lap(mot vat lay nhieu lan)
// dynamic program
// ham muc tieu phu thuoc : trong luong con lai + vat con lai 
// F[i,j]= max(F[i-1,j], V[i]+    F[     i-1,j-W[i]       ]  ) 

#include<iostream>
#include<algorithm>

using namespace std;

int MaxValue(int n,int b, int w[],int c[] ){
    long long result[n+1][b+1];
    for (int i=0;i<=n;i++) result[i][0]=0;
    for (int i=0;i<=b;i++) result[0][i]=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=b;j++)
            if (j>=w[i]) result[i][j]=max(result[i-1][j], result[i-1][j-w[i]]+c[i]);
            else result[i][j]=result[i-1][j];

            
    return result[n][b];
}

int main(){
    int n,b;
    cin >>n>>b;
    int w[n+1],c[n+1];
    for(int i=1;i<=n;i++){
        cin >>w[i]>>c[i];
    }
    cout<< MaxValue(n,b,w,c);



    return 0;
}