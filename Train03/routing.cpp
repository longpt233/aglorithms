#include<iostream>

using namespace std;

int n,r;
int e[100][100];
int pass[100]={false};
int f, fMin; // toi uu ham 
int begin,last;


int Try(int x,int l, int sum){
    for (int y=1;y<=n;y++){
        if (e[x][y]==1&&pass[y]==false&&(y!=last||l==k))
    }
}

int main(){
    cin >> n>>r;
    for (int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >>e[i][j];
        }
    }
    for (int i=1;i<=r;i++){
        for (int j=1;j)
    }


    return 0;
}