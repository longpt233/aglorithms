// n k :  dinh .tim so duong di co do dai bang k 
// m  :  so canh 
// canh [][]

#include<iostream>
#include<vector>

using namespace std;

int n,k;
int m;
int e[31][31]={0}; 

// G=(V,E)
// V=1..n

// E + ma tran ke:  E[x][y]= true, false. neu vo huong E[x][y]=k[y][x]
// duyet dinh : for i in V
// duyet canh : for i in V for j in V if E[x][y]
// duyet ke a : for i in V if E[i][a]
// kha ton bo nho khi E<V^2 . cham 

// E + danh sach ke 
// dung danh sach lien ket de luu danh sach ke cua tung dinh 
// vetor <int>

int f=0;
bool pass[31]={false};

void Try(int i,int h){   // try h den k
    for (int j=1;j<=n;j++){
        if (e[i][j]==1&&pass[j]==false){
            pass[j]=true;
            if(k==h) {
                f++;
            }else {
                
                Try(j,h+1);
            }
            pass[j]=false;
        }
    }
}

int main(){
    cin >> n>> k;
    cin>> m;
    for (int i=1;i<=m;i++){
        int u,v;
        cin >> u>>v;
        e[u][v]=e[v][u]=1;
    }
    for(int z=1;z<=n;z++){
        pass[z]=true;
        Try(z,1);
        pass[z]=false;
    }
    cout<< f/2;
    return 0;
}