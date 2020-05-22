//Traveling Salesman Problem
// Branch and Bounch
#include<iostream>
using namespace std;

const int maxC=1000000;
int n,m;
int cost[21][21];
bool pass[21];
unsigned int   f=0; // chi phi hien tai 
unsigned int   fMin;  // chi phi tối thiểủ 
int road[21];
int cMin;

/* int FindMin(){
    int min=maxC;
    for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n ; j++) {
			
			if ((min >cost[i][j])&&(cost[i][j]!=0)) min =cost[i][j];
		}
    }
    return min;
} */

void Try(int i){
    for (int k=1;k<=n;k++){
        if(pass[k]==false&&cost[road[i-1]][k]!=0){ 
            pass[k]=true;
            road[i]=k;
            f=f+cost[road[i-1]][k];
            if(i==n){
                if ((f+cost[road[i]][1])<fMin&&cost[road[i]][1]!=0) 
                    fMin=f+cost[road[i]][road[1]];
            }else{
                if ((f+(n-i+1)*cMin) <fMin) Try(i+1);
            }
            f=f-cost[road[i-1]][k];
            pass[k]=false;
        }
    }
    
}

int main(){
    //freopen("input.txt","r",stdin);
    // freopen ("data.out","w",stdout)
    cin >>n>>m;
    // graph init
    for (int i=1;i<=n;i++){
        pass[i]=false;
        for(int j=1;j<=n;j++)
            cost[i][j]=0;
    }
    // graph input
    int min=maxC;
    for (int k=0;k<m;k++){
        int i,j;
        cin >> i>>j;
        cin>>cost[i][j];
        if (min >cost[i][j]) min =cost[i][j];
    }

    road[1]=1;
    pass[1]=true;
    //cMin=FindMin();
    cMin = min ;
    fMin=(n+1)*maxC;

    Try(2);

    cout<<fMin;
    return 0;
}