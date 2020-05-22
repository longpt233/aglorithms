#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n1, n2;
    cin >>n1>>n2;
    int a1[n1],a2[n2];

    int f[n1+1][n2+1];

    for(int i=0;i<n1;i++){
        cin>> a1[i];
    }
    
    for(int i=0;i<n2;i++){
        cin >> a2[i];

    }

    for (int i=0;i<n1+1;i++){
        f[i][0]=0;
    }
    
    for(int i=0;i<n2+1;i++){
        f[0][i]=0;

    }
    
    int res=0;
    for (int i=0;i<n1;i++){
        for (int j=0;j<n2;j++){
            if (a1[i]==a2[j]) f[i+1][j+1]=f[i][j]+1;
            else f[i+1][j+1]=max(f[i][j+1],f[i+1][j]);
            // for (int i=0;i<n1+1;i++){
            //     for (int j=0;j<n2+1;j++){
            //         cout<<f[i][j]<<" ";
            //     }
            //     cout<< endl;
            // }
            res=max(res,f[i+1][j+1]);
        }
    }

    cout << res;
    


    return 0;
}